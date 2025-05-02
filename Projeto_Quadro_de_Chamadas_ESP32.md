# Projeto: Quadro de Chamadas (ESP32- WROOM)

Este projeto desenvolve um painel de chamadas interativo baseado no microcontrolador ESP32 🔌, integrando funcionalidades de automação, conectividade e monitoramento em tempo real. O sistema permite a ativação de chamadas por meio de botões tipo pera e sinaliza a solicitação através de arandelas luminosas controladas por relés. Além disso, disponibiliza uma interface web moderna, acessível via Wi-Fi, para visualização do status das chamadas, monitoramento de temperatura e umidade, e controle do buzzer de alerta.
A estrutura modular e a programação flexível do ESP32 garantem escalabilidade, permitindo futuras expansões como notificações remotas e integração com redes de automação predial.

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
## 🌐 Funcionalidades

- 🔢 Exibição da temperatura e umidade em tempo real (acessível por Wi-Fi 📡)
- 🔹 Indicadores visuais de entrada (bolinhas cinza e verde 🔘)
- 💔 Botão para desativar o buzzer por 1 minuto
- 🌍 Logotipo do **CEFET-MG** exibido via SPIFFS
- 🔄 Atualizações automáticas da página usando AJAX
- 🖥️ Interface web responsiva hospedada no ESP32

---

## Porque o ESP32?

O ESP32 foi escolhido para o projeto do Quadro de Chamadas por oferecer conexão Wi-Fi integrada, múltiplos pinos de entrada e saída digitais, alto poder de processamento e ampla memória flash. Essas características permitem a criação de um sistema de monitoramento via navegador, com atualização em tempo real e possibilidade de armazenamento de páginas web (HTML, CSS, JS) diretamente na memória da placa, utilizando SPIFFS. Além disso, o ESP32 é compatível com a plataforma Arduino IDE, facilitando o aprendizado e a programação para alunos do curso técnico.

<img src="https://github.com/Epaminondaslage/quadro_de_chamadas/blob/main/img/esp32wroom32.png" alt="esp32" width="300">

Sua estrutura robusta, baixo custo e grande suporte da comunidade o tornam ideal para projetos educacionais que exigem confiabilidade e flexibilidade. A utilização do ESP32 possibilita ainda futuras expansões do sistema, como integração com controle remoto via MQTT, monitoramento por smartphones e atualizações OTA, preparando os alunos para tecnologias modernas de automação e conectividade.

<img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/pinout.png" alt="Pinout ESP32" width="500">

- 🔹 4 entradas digitais (botões de chamada)
- 🔹 4 saídas digitais (LEDs e relés para cargas em 127V)
- 🔹 Buzzer 🔊 com controle de desativação temporária (mute)
- 🌡️ Sensor de temperatura e umidade **DHT11**
- 🖥️ Interface web moderna, servida via **SPIFFS**

## 📡 Conexão Wi-Fi

Para acessar a interface web do Quadro de Chamadas, é necessário primeiro se conectar à rede Wi-Fi do Laboratório de Instalações Prediais utilizando as seguintes credenciais:

```cpp
SSID "DEE-Prediais"
PASSWORD "prediais123"
```
Cada celular ou tablet irá obter um endereço IP dinâmico conforme este exemplo abaixo.

<img src="https://github.com/Epaminondaslage/quadro_de_chamadas/blob/main/img/wifi.jpg" alt="esp32" width="150">

Após a conexão, basta abrir o navegador em seu dispositivo (computador, tablet ou smartphone) e digitar o IP do ESP32 para acessar o painel de chamadas, visualizar o status das entradas e saídas e monitorar as informações de temperatura e umidade em tempo real.

---
## 🌐 Acesso à interface

Devera procurar o IP do ESP alocado pelo DHCP do roretador do laboratório de Instalações Prediais. A interface carregará os dados em tempo real.
Abra no navegador:

```
http://10.240.240.x
```

<img src="https://github.com/Epaminondaslage/quadro_de_chamadas/blob/main/img/tela_www.jpg" alt="box" width="400">

---

## 🔔 Modulo Relé 3.3V

O módulo relé 2 canais 3.3V é um dispositivo que permite controlar dois circuitos de corrente alternada (AC) ou contínua (DC) por meio de sinais de baixa tensão, sendo compatível com microcontroladores como o ESP32, ESP8266 e Raspberry Pi. Cada canal possui um relé eletromecânico com contatos NO (normalmente aberto), NC (normalmente fechado) e COM (comum), suportando até 10A em 250V AC ou 30V DC. O módulo é acionado por nível lógico baixo (LOW), conta com optoacopladores para isolamento elétrico entre a carga e o circuito de controle, e possui LEDs indicadores para sinalizar o estado de cada relé.

<img src="https://github.com/Epaminondaslage/quadro_de_chamadas/blob/main/img/rele.jpg" alt="rele" width="150">

---
## 🌡 Sensor DHT11

O DHT11 é um sensor digital de baixo custo usado para medir temperatura e umidade relativa do ar. Ele é amplamente utilizado em projetos educacionais, hobby e sistemas de automação residencial devido à sua simplicidade de uso e integração fácil com microcontroladores como Arduino, ESP32 e ESP8266.

<img src="https://github.com/Epaminondaslage/quadro_de_chamadas/blob/main/img/DHT11.png" alt="dht11" width="150">

- Ligado ao GPIO 15
- Mostra temperatura e umidade no display e na interface web
- Se não estiver conectado: mostra `Ind`

---

## 🔔 Controle de Buzzer

O Buzzer é um dispositivo eletrônico utilizado para gerar sinais sonoros. Ele é muito comum em projetos de automação, sistemas de alarme, interfaces de usuário e aplicações educacionais. Existem duas versões principais: o buzzer ativo e o buzzer passivo, cada um com características específicas.

<img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/buzzer.png" alt="buzzer" width="150">

- Ativado por qualquer uma das 4 entradas digitais
- Desligado por:
  - Botão físico no GPIO 27
  - Botão na interface web
- Fica desativado por 60 segundos

---
 ## 📂 Diagrama de conexões do sistema

O projeto consiste em um sistema embarcado de sinalização e monitoramento baseado no microcontrolador ESP32, voltado para aplicações didáticas e automação predial. A arquitetura foi concebida para garantir confiabilidade, flexibilidade e baixo custo, utilizando recursos nativos do ESP32, como conectividade Wi-Fi e suporte a sistemas de arquivos SPIFFS, permitindo a disponibilização de uma interface web responsiva acessível via navegador. O sistema conta com 4 entradas digitais para acionamento por botões físicos e 4 saídas digitais destinadas ao controle de cargas ou sinalização visual por LEDs e relés, operando inclusive em tensões de 127V~. Inclui ainda um buzzer piezoelétrico com controle de silenciamento temporário e um sensor DHT11, responsável pela leitura de temperatura e umidade relativa.

Veja a definição dos pinos no .INO:

```
#define DHTPIN 15
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);
const int entradas[4] = {32, 33, 25, 26};
const int saidas[4] = {4, 5, 18, 19};
const int buzzerPin = 21;
const int botaoMute = 27;
```

### 📌 Pinos utilizados na parte superior da placa  (com USB à esquerda)

| Ordem na placa | Nome na placa  | GPIO     | Sua utilização     |
|----------------|----------------|-----------|-------------------|
| 1              | VIN            | 5V        | Alimentação In    |
| 2              | GND            | GND       | Terra comum       |
| 6              | D27            | GPIO27    | **Botão Mute**    |
| 7              | D26            | GPIO26    | **Entrada 4**     |
| 8              | D25            | GPIO25    | **Entrada 3**     |
| 9              | D33            | GPIO33    | **Entrada 2**     |
| 10             | D32            | GPIO32    | **Entrada 1**     |

---

### 📌 Pinos usados na parte inferior da Placa (com USB à esquerda)

| Ordem na placa | Nome na placa | GPIO real | Sua utilização     |
|----------------|----------------|-----------|-------------------|
| 1              | 3.3            | 3.3       | Alimentação Saída |
| 2              | GND            | GND       | Terra comum       |
| 3              | D15            | GPIO15    | **DHT11**         |
| 5              | D04            | GPIO04    | **Saída 1**       |
| 8              | D05            | GPIO05    | **Saída 2**       |
| 9              | D18            | GPIO18    | **Saída 3**       |
| 10             | D19            | GPIO19    | **Saída 4**       |
| 11             | D21            | GPIO21    | **Buzzer**        |


<img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/pinagem.png" alt="buzzer" width="300">


A integração com redes sem fio permite a expansão natural do sistema para aplicações de Internet das Coisas (IoT), com publicação de eventos em tempo real por meio do protocolo MQTT, possibilitando o envio de dados para servidores locais ou em nuvem. Essa funcionalidade viabiliza o monitoramento remoto por dashboards web ou aplicações móveis, além de facilitar a integração com sistemas supervisórios ou plataformas de automação predial. A estrutura modular e o uso de tecnologias abertas tornam o projeto ideal para o ensino técnico de sistemas embarcados, protocolo de comunicação, lógica de controle e aplicações conectadas.

<img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/quadro_de_chamadas_fritzing.jpg" alt="buzzer" width="800">
 
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

## 🔧 Como Usar os códigos

1. Abra `quadro_de_chamadas.ino` na IDE do Arduino.
2. Instale as bibliotecas necessárias:
   - `WiFi` 📡
   - `WebServer` 🔹
   - `DHT sensor library` 🌡️
3. Faça upload do código para o ESP32.
4. Envie os arquivos da pasta `data/` para o SPIFFS. Veja o tutorial: [Guia de uso do SPIFFS no ESP32](https://github.com/Epaminondaslage/quadro_de_chamadas/blob/main/spiffs_esp32_guia.md) para mais detalhes sobre o sistema de arquivos SPIFFS e como fazer upload no ˜ESP32.
5. Acesse o IP do ESP32 no navegador 🔍.

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
