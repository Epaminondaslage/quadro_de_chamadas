# Projeto: quadro_de_chamadas (ESP32- WROOM)

Este projeto implementa um painel de chamadas interativo utilizando o microcontrolador **ESP32 🔌**, com os seguintes recursos:


<img src="https://github.com/Epaminondaslage/quadro_de_chamadas/blob/main/img/esp32.png" alt="esp32" width="150">

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

## ✅ Visão geral

Este projeto implementa um painel de monitoramento com ESP32 utilizando:

- Conexão Wi-Fi
- Sensor de temperatura e umidade DHT11
- Buzzer
- Quatro entradas digitais
- Quatro saídas digitais
- Interface web (HTML/CSS/JS via SPIFFS)
- Display de status com atualização dinâmica
- Desativação do buzzer por botão físico ou pela web

---
## Porque o ESP32?

O ESP32 foi escolhido para o projeto do Quadro de Chamadas por oferecer conexão Wi-Fi integrada, múltiplos pinos de entrada e saída digitais, alto poder de processamento e ampla memória flash. Essas características permitem a criação de um sistema de monitoramento via navegador, com atualização em tempo real e possibilidade de armazenamento de páginas web (HTML, CSS, JS) diretamente na memória da placa, utilizando SPIFFS. Além disso, o ESP32 é compatível com a plataforma Arduino IDE, facilitando o aprendizado e a programação para alunos do curso técnico.

Sua estrutura robusta, baixo custo e grande suporte da comunidade o tornam ideal para projetos educacionais que exigem confiabilidade e flexibilidade. A utilização do ESP32 possibilita ainda futuras expansões do sistema, como integração com controle remoto via MQTT, monitoramento por smartphones e atualizações OTA, preparando os alunos para tecnologias modernas de automação e conectividade.

<img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/pinout.png" alt="Pinout ESP32" width="300">


## 📡 Conexão Wi-Fi

```cpp
#define SSID "DEE-Prediais"
#define PASSWORD "prediais123"
```

---

## 🌡 Sensor DHT11

<img src="https://github.com/Epaminondaslage/quadro_de_chamadas/blob/main/img/DHT11.png" alt="dht11" width="150">

O DHT11 é um sensor digital de baixo custo usado para medir temperatura e umidade relativa do ar. Ele é amplamente utilizado em projetos educacionais, hobby e sistemas de automação residencial devido à sua simplicidade de uso e integração fácil com microcontroladores como Arduino, ESP32 e ESP8266.

- Ligado ao GPIO 15
- Mostra temperatura e umidade no display e na interface web
- Se não estiver conectado: mostra `Ind`

---

## 🔔 Controle de Buzzer

O Buzzer é um dispositivo eletrônico utilizado para gerar sinais sonoros. Ele é muito comum em projetos de automação, sistemas de alarme, interfaces de usuário e aplicações educacionais. Existem duas versões principais: o buzzer ativo e o buzzer passivo, cada um com características específicas.

<img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/buzzer.png" alt="dht11" width="1500">

- Ativado por qualquer uma das 4 entradas digitais
- Desligado por:
  - Botão físico no GPIO 27
  - Botão na interface web
- Fica desativado por 60 segundos


## 🌐 Acesso à interface

Abra no navegador:

<img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/dht11.png" alt="dht11" width="200">

```
http://240.0.0.x
```
Devera procurar o IP do ESP alocado pelo DHCP do roretador do laboratório de Instalações Prediais. A interface carregará os dados em tempo real.


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

 ## 📂 Códigos de programação e Estrutura de Software do ESP32 WROOM

Todos os programas desenvolvidos encontram-se disponibilizados neste repositório, na pasta **Quadro_de_chamadas**, e podem ser livremente acessados e utilizados como referência para o desenvolvimento de outras aplicações.

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

## 📡 EComunicação entre o sensor o ESP32 e a Pagina HTML:  JSON

O  **JSON** é apenas **texto estruturado** em pares **chave: valor**. O navegador entende e usa facilmente essas informações.

## 🧐 Visão Geral

- O **ESP32** (programa `.ino`) gera um **JSON** com os dados.
- A **página HTML** faz uma **requisição HTTP** para buscar o JSON.
- O **ESP32 responde** com o JSON.
- O **JavaScript da página** interpreta o JSON e **atualiza a interface**.

---

### 1. No ESP32 (.ino)

```cpp
void handleStatus() {
  String json = "{";
  json += "\"temperatura\":24.5,";
  json += "\"umidade\":60.0,";
  json += "\"entrada1\":true,";
  json += "\"entrada2\":false";
  json += "}";
  server.send(200, "application/json", json);
}
```

- O ESP32 cria uma **resposta JSON** e envia para quem acessar `/status.json`.

### 2. No HTML + JavaScript

```html
<script>
function atualizarDados() {
  fetch('/status.json')
    .then(response => response.json())
    .then(data => {
      console.log(data); // Exibe o JSON no console
      document.getElementById('temp').innerText = data.temperatura + ' °C';
      document.getElementById('umid').innerText = data.umidade + ' %';
    })
    .catch(error => console.error('Erro:', error));
}

// Atualiza a cada 5 segundos
setInterval(atualizarDados, 5000);
</script>

<p>Temperatura: <span id="temp">--</span></p>
<p>Umidade: <span id="umid">--</span></p>
```

- `fetch('/status.json')` pede o JSON.
- O JavaScript atualiza o HTML com os dados recebidos.

---

## 💾 Exemplo de JSON recebido

```json

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

## 📝 Resumo do Fluxo

ESP32 gera JSON -> HTML pede JSON -> ESP32 responde -> HTML atualiza tela

| No ESP32 (.ino) | Na Página HTML/JS |
|:---------------|:-------------------|
| Monta e envia o JSON | Faz `fetch` e consome o JSON |
| Usa `server.send(...)` | Usa `fetch('/status.json')` |
| Dados gerados | Dados exibidos |

---

 ## 🔍 Monitor Serial

Após iniciar o ESP32, o monitor serial , conectado a portrta usb do ESP32 e a interface do IDE do arduino pode monitorar e  deve exibir:

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

## 💾 O que é SPIFFS?

**SPIFFS.h** é a biblioteca utilizada no ESP32  para armazenar e gerenciar arquivos na memória flash da placa, como um mini "pendrive" interno 📥.

> **SPIFFS** = *SPI Flash File System*

É um sistema de arquivos leve e eficiente, ideal para microcontroladores.

> 📘 **Referência:**  
> Consulte o [Guia de uso do SPIFFS no ESP32](https://github.com/Epaminondaslage/quadro_de_chamadas/blob/main/spiffs_esp32_guia.md) para mais detalhes sobre o sistema de arquivos SPIFFS.

---
