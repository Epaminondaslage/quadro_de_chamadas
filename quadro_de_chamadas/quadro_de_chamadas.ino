
#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>
#include <FS.h>
#include <SPIFFS.h>

#define SSID "SEU_SSID"
#define PASSWORD "SUA_SENHA"

#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

WebServer server(80);

// PINOS
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
  json += ""temperatura":" + String(temperatura, 1) + ",";
  json += ""umidade":" + String(umidade, 1) + ",";
  json += ""buzzer":" + String(buzzerAtivo ? "true" : "false") + ",";

  for (int i = 0; i < 4; i++) {
    json += ""entrada" + String(i + 1) + "":" + String(digitalRead(entradas[i]) ? "true" : "false");
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
  Serial.println("WiFi conectado");

  dht.begin();
  SPIFFS.begin(true);

  for (int i = 0; i < 4; i++) {
    pinMode(entradas[i], INPUT);
    pinMode(saidas[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
  pinMode(botaoMute, INPUT);

  // Roteamento SPIFFS
  server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");
  server.on("/status.json", handleStatus);
  server.on("/mute", handleMute);
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
}
