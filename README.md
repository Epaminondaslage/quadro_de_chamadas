# Projeto: Quadro Sinalizador de Chamadas

## 📢 O que é um sistema de chamada de enfermagem?

Um **sistema de chamada de enfermagem**, também conhecido como **campainha hospitalar**, é um conjunto de dispositivos eletrônicos que permite que pacientes, acamados ou não, acionem um **sinal sonoro 🔊 e/ou luminoso 🔦** para chamar a atenção da equipe de saúde quando necessitam de assistência.

Esse sinal é enviado para uma **central de monitoramento** 🛋️, localizada em local visível a todos os profissionais.

Além disso, o sistema permite que os profissionais de saúde **registrem a sua presença no leito** do paciente que gerou a chamada, sinalizando ao restante da equipe que o **atendimento está em andamento**.

## 🔧 Como funciona um sistema de chamada de enfermagem?

Um **sistema de chamada de enfermagem** é composto por diferentes dispositivos, adaptados às necessidades do ambiente hospitalar:

### 🛉 Estação de Chamada de Enfermagem

Dispositivos fixados na parede ou painéis de gases medicinais, acessíveis por um **cordão com pera sensível ao toque 🌟**.

### 🔦 Sinaleiro de Porta

Indicadores visuais fixados **acima das portas** para alertar sobre chamadas em andamento, utilizando diferentes **cores 🟥🟢🟦🟧**.

### 🛋️ Central do Posto de Enfermagem

Dispositivo centralizado que **monitora e sinaliza** todas as chamadas ativas.

---

## 🔬 Descrição Técnica do Projeto

Este projeto implementa um painel de chamadas interativo utilizando o microcontrolador **ESP32 🔌**, com os seguintes recursos:

- 🔹 4 entradas digitais (botões de chamada)
- 🔹 4 saídas digitais (LEDs e relés para cargas em 127V)
- 🔹 Buzzer 🔊 com controle de desativação temporária (mute)
- 🌡️ Sensor de temperatura e umidade **DHT11**
- 🖥️ Interface web moderna, servida via **SPIFFS**

---

## 🌐 Funcionalidades

- 🔢 Exibição da temperatura e umidade em tempo real (acessível por Wi-Fi 📡)
- 🔹 Indicadores visuais de entrada (bolinhas cinza e verde 🔘)
- 💔 Botão para desativar o buzzer por 1 minuto
- 🌍 Logotipo do **CEFET-MG** exibido via SPIFFS
- 🔄 Atualizações automáticas da página usando AJAX
- 🖥️ Interface web responsiva hospedada no ESP32

---

## 📂 Estrutura de Software

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

**Veja maiores detalhes no arquivo `spiffs_esp32_guia.md`**.

---



