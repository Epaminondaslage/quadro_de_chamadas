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

void handleStatus() {
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  String json = "{";
  json += "\"temperatura\":";
  json += isnan(temperatura) ? "\"Ind\"" : String(temperatura, 1);
  json += ",";
  json += "\"umidade\":";
  json += isnan(umidade) ? "\"Ind\"" : String(umidade, 1);
  json += ",";
  json += "\"buzzer\":" + String(buzzerAtivo ? "true" : "false") + ",";

  for (int i = 0; i < 4; i++) {
    json += "\"entrada" + String(i + 1) + "\":" + String(digitalRead(entradas[i]) ? "true" : "false");
    if (i < 3) json += ",";
  }
  json += "}";

  server.send(200, "application/json", json);
}

void handleMute() {
  buzzerDesligadoAte = millis() + 60000;
  digitalWrite(buzzerPin, LOW);
  buzzerAtivo = false;
  server.send(200, "text/plain", "Buzzer desativado por 1 minuto");
}

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
    pinMode(entradas[i], INPUT);
    pinMode(saidas[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
  pinMode(botaoMute, INPUT);

  server.serveStatic("/", SPIFFS, "/");
  server.on("/status.json", handleStatus);
  server.on("/mute", handleMute);

  server.onNotFound([]() {
    if (!handleFileRead(server.uri())) {
      server.send(404, "text/plain", "Not found");
    }
  });

  server.begin();
}

void loop() {
  server.handleClient();

  for (int i = 0; i < 4; i++) {
    bool estado = digitalRead(entradas[i]);
    digitalWrite(saidas[i], estado ? HIGH : LOW);
    if (estado && millis() > buzzerDesligadoAte) {
      digitalWrite(buzzerPin, HIGH);
      buzzerAtivo = true;
    }
  }

  if (digitalRead(botaoMute)) {
    buzzerDesligadoAte = millis() + 60000;
    digitalWrite(buzzerPin, LOW);
    buzzerAtivo = false;
  }

  if (millis() > buzzerDesligadoAte) {
    digitalWrite(buzzerPin, LOW);
    buzzerAtivo = false;
  }

  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  if (!isnan(temperatura) && !isnan(umidade)) {
    Serial.println("===== DADOS DHT11 =====");
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");

    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.println(" %");

    // Gerar e mostrar o JSON no loop
    String json = "{";
    json += "\"temperatura\":" + String(temperatura, 1) + ",";
    json += "\"umidade\":" + String(umidade, 1) + ",";
    json += "\"buzzer\":" + String(buzzerAtivo ? "true" : "false") + ",";

    for (int i = 0; i < 4; i++) {
      json += "\"entrada" + String(i + 1) + "\":" + String(digitalRead(entradas[i]) ? "true" : "false");
      if (i < 3) json += ",";
    }
    json += "}";

    Serial.println("===== JSON GERADO (LOOP) =====");
    Serial.println(json);
    Serial.println("==============================");

  } else {
    Serial.println("Falha na leitura do sensor DHT11.");
  }

  delay(5000);
}

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
