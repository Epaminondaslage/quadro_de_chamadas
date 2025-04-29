#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>
#include <FS.h>
#include <SPIFFS.h>

#define SSID "PLT-DIR"
#define PASSWORD "epaminondas"

#define DHTPIN 15
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

WebServer server(80);

const int entradas[4] = {32, 33, 25, 26};
const int saidas[4] = {4, 5, 18, 19};
const int buzzerPin = 21;
const int botaoMute = 27;

bool buzzerAtivo = false;
unsigned long buzzerDesligadoAte = 0;

// =================================================
// Classe Pisca quando algum box chama a enfermagem
// =================================================
class Pisca {
  private:
    int pino;
    unsigned long intervaloPrincipal;
    unsigned long intervaloPisca;
    unsigned long tempoAnterior;
    unsigned long tempoPisca;
    int estadoPisca;
    bool habilitado;

  public:
    Pisca(int pinoSaida, unsigned long intervalo, unsigned long intervaloEntrePiscas) {
      pino = pinoSaida;
      intervaloPrincipal = intervalo;
      intervaloPisca = intervaloEntrePiscas;
      tempoAnterior = 0;
      tempoPisca = 0;
      estadoPisca = 0;
      habilitado = false;
      pinMode(pino, OUTPUT);
      digitalWrite(pino, LOW);
    }

    void ativar() {
      habilitado = true;
    }

    void desligar() {
      habilitado = false;
      digitalWrite(pino, LOW);
      estadoPisca = 0;
    }

    void atualizar() {
      if (!habilitado) return;

      unsigned long agora = millis();

      if (estadoPisca == 0 && agora - tempoAnterior >= intervaloPrincipal) {
        tempoAnterior = agora;
        estadoPisca = 1;
        tempoPisca = agora;
        digitalWrite(pino, HIGH);
      }

      if (estadoPisca > 0 && agora - tempoPisca >= intervaloPisca) {
        tempoPisca = agora;
        if (estadoPisca % 2 == 1) {
          digitalWrite(pino, LOW);
        } else {
          digitalWrite(pino, HIGH);
        }
        estadoPisca++;

        if (estadoPisca > 6) {
          estadoPisca = 0;
        }
      }
    }
};

// =================================================
// Função para ler arquivos do SPIFFS
// =================================================
bool handleFileRead(String path) {
  if (path.endsWith("/")) path += "index.html";

  String contentType = "text/plain";
  if (path.endsWith(".html")) contentType = "text/html";
  else if (path.endsWith(".css")) contentType = "text/css";
  else if (path.endsWith(".js")) contentType = "application/javascript";
  else if (path.endsWith(".png")) contentType = "image/png";

  if (SPIFFS.exists(path)) {
    File file = SPIFFS.open(path, "r");
    server.streamFile(file, contentType);
    file.close();
    return true;
  }
  return false;
}

// =================================================
// Função para gerar JSON do status
// =================================================
String getJsonAsString(float temperatura, float umidade){
  String json = "{";
  json += "\"temperatura\":" + String(temperatura, 1) + ",";
  json += "\"umidade\":" + String(umidade, 1) + ",";
  json += "\"buzzer\":" + String(buzzerAtivo ? "true" : "false") + ",";
  for (int i = 0; i < 4; i++) {
    json += "\"entrada" + String(i + 1) + "\":" + String(digitalRead(entradas[i]) ? "true" : "false");
    if (i < 3) json += ",";
  }
  json += "}";
  return json;
}

// =================================================
// Parâmetros do pisca
// =================================================
Pisca pisca(2, 1000, 200); // Pino 2, intervalo de 1s, piscadas de 200ms

// =================================================
// Setup
// =================================================
void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi conectado");
  Serial.print("IP atribuído: ");
  Serial.println(WiFi.localIP());

  dht.begin();

  if (!SPIFFS.begin(true)) {
    Serial.println("❌ Falha ao montar SPIFFS");
    return;
  }
  Serial.println("✅ SPIFFS montado com sucesso");

  Serial.println("Arquivos SPIFFS disponíveis:");
  File root = SPIFFS.open("/");
  if (!root || !root.isDirectory()) {
    Serial.println("Erro ao abrir diretório raiz SPIFFS.");
  } else {
    File file = root.openNextFile();
    while (file) {
      Serial.print("  ");
      Serial.println(file.name());
      file = root.openNextFile();
    }
  }

  for (int i = 0; i < 4; i++) {
    pinMode(entradas[i], INPUT_PULLDOWN);
    pinMode(saidas[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
  pinMode(botaoMute, INPUT_PULLDOWN);

  server.on("/status.json", []() {
    float temperatura = dht.readTemperature();
    float umidade = dht.readHumidity();
    String json = getJsonAsString(temperatura, umidade);
    Serial.println(json);
    server.send(200, "application/json", json);
  });

  server.on("/mute", []() {
    buzzerDesligadoAte = millis() + 60000;
    digitalWrite(buzzerPin, LOW);
    buzzerAtivo = false;
    server.send(200, "text/plain", "Buzzer desativado por 1 minuto");
  });

  server.serveStatic("/", SPIFFS, "/");

  server.onNotFound([]() {
    if (!handleFileRead(server.uri())) {
      server.send(404, "text/plain", "Not found");
    }
  });

  server.begin();
}

// =================================================
// Loop principal
// =================================================
void loop() {
  server.handleClient();
  bool algumaEntradaAtiva = false;

  // Verifica entradas e ativa saídas
  for (int i = 0; i < 4; i++) {
    bool estado = digitalRead(entradas[i]);
    digitalWrite(saidas[i], estado ? LOW : HIGH);
    if (estado) {
      algumaEntradaAtiva = true;
    }
  }

  // Controle do pisca
  if (algumaEntradaAtiva) {
    pisca.ativar();
  } else {
    pisca.desligar();
  }

  pisca.atualizar();

  // Verifica botão de mute
  if (digitalRead(botaoMute) == HIGH) {
    buzzerDesligadoAte = millis() + 60000;
    digitalWrite(buzzerPin, LOW);
    buzzerAtivo = false;
  }

  // Controle do buzzer
  if (millis() > buzzerDesligadoAte) {
    if (algumaEntradaAtiva) {
      tocarAlertaSonoro();
      buzzerAtivo = true;
    } else {
      noTone(buzzerPin);
      buzzerAtivo = false;
    }
  } else {
    digitalWrite(buzzerPin, LOW);
    buzzerAtivo = false;
  }

  // Exibe temperatura e umidade a cada 5s na Serial
  static unsigned long ultimaLeituraSerial = 0;
  if (millis() - ultimaLeituraSerial > 5000) {
    ultimaLeituraSerial = millis();
    float temp = dht.readTemperature();
    float umid = dht.readHumidity();

    if (isnan(temp) || isnan(umid)) {
      Serial.println("❌ Erro ao ler do sensor DHT!");
    } else {
      Serial.print("🌡️ Temp: ");
      Serial.print(temp);
      Serial.print(" °C\t");
      Serial.print("💧 Umidade: ");
      Serial.print(umid);
      Serial.println(" %");
    }
  }
}

// =================================================
// Função do alerta sonoro
// =================================================
void tocarAlertaSonoro() {
  tone(buzzerPin, 1000); delay(150); noTone(buzzerPin); delay(100);
  tone(buzzerPin, 1500); delay(150); noTone(buzzerPin); delay(100);
  tone(buzzerPin, 1200); delay(150); noTone(buzzerPin); delay(300);
}
