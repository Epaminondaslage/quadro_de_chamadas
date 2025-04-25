# Projeto: quadro_de_chamadas (ESP32- WROOM)

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

## 📡 Conexão Wi-Fi

```cpp
#define SSID "DEE-Prediais"
#define PASSWORD "prediais123"
```

---

## 🌡 Sensor DHT11

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


## 🌐 Acesso à interface

Abra no navegador:

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

 Todos os programas desenvolvidos estão disponibilidados para livre acesso e utilização como modelo para outras aplicações e estao neste repodiório na para Qaudro_de_chamada

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

- **JSON** é apenas **texto estruturado** em pares **chave: valor**.
- O navegador entende e usa facilmente essas informações.

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


---
