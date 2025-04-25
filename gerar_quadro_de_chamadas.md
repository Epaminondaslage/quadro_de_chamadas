# Projeto: quadro_de_chamadas (ESP32)

## ✅ Visão geral

Este projeto implementa um painel de monitoramento com ESP32 utilizando:

- Conexão Wi-Fi
- Sensor de temperatura e umidade DHT22
- Buzzer
- Quatro entradas digitais
- Quatro saídas digitais
- Interface web (HTML/CSS/JS via SPIFFS)
- Display de status com atualização dinâmica
- Desativação do buzzer por botão físico ou pela web

---

## 📡 Conexão Wi-Fi

```cpp
#define SSID "DEE-Prediais"
#define PASSWORD "prediais123"
```

---

## 🌡 Sensor DHT22

- Ligado ao GPIO 15
- Mostra temperatura e umidade no display e na interface web
- Se não estiver conectado: mostra `Ind`

---

## 🔔 Controle de Buzzer

- Ativado por qualquer uma das 4 entradas digitais
- Desligado por:
  - Botão físico no GPIO 27
  - Botão na interface web
- Fica desativado por 60 segundos

- ## 🔍 Monitor Serial

Após reiniciar o ESP32, o monitor deve exibir:

```
WiFi conectado
IP atribuído: 240.0.0.x
✅ SPIFFS montado com sucesso
Arquivos SPIFFS disponíveis:
  /index.html
  /style.css
  /script.js
  /logo.png
```
---

## 🌐 Acesso à interface

Abra no navegador:

```
http://240.0.0.x
```
Devera procurar o IP do ESP alocado pelo DHCP do roretador do laboratório de Instalações Prediais. A interface carregará os dados em tempo real.


---

## 📂 SPIFFS (Sistema de Arquivos)

## 📂 Estrutura de Software do ESP32 WROOM

```
quadro_de_chamadas/
├── quadro_de_chamadas.ino
└── data/
    ├── index.html
    ├── style.css
    ├── script.js
    └── logo.png
```

---

## 🔧 Como Usar

1. Abra `quadro_de_chamadas.ino` na IDE do Arduino.
2. Instale as bibliotecas necessárias:
   - `WiFi` 📡
   - `WebServer` 🔹
   - `DHT sensor library` 🌡️
   - `Adafruit Unified Sensor`
3. Envie os arquivos da pasta `data/` para o SPIFFS (plugin ESP32 Sketch Data Upload).
4. Faça upload do código para o ESP32.
5. Acesse o IP do ESP32 no navegador 🔍.

---

## 📡 Exemplo de Resposta JSON

```
GET /status.json
{
  "temperatura": 24.5,
  "umidade": 60.0,
  "buzzer": false,
  "entrada1": true,
  "entrada2": false,
  "entrada3": true,
  "entrada4": false
}
```

---

## 💾 O que é SPIFFS?

**SPIFFS.h** é a biblioteca utilizada no ESP32 e ESP8266 para armazenar e gerenciar arquivos na memória flash da placa, como um mini "pendrive" interno 📥.

> **SPIFFS** = *SPI Flash File System*

É um sistema de arquivos leve e eficiente, ideal para microcontroladores.

> 📘 **Referência:**  
> Consulte o [Guia de uso do SPIFFS no ESP32](https://github.com/Epaminondaslage/quadro_de_chamadas/blob/main/spiffs_esp32_guia.md) para mais detalhes sobre o sistema de arquivos SPIFFS.


---


---
