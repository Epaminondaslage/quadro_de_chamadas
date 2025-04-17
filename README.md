# Projeto: Quadro Sinalizador de Chamadas
## O que é um sistema de chamada de enfermagem?

Um **sistema de chamada de enfermagem**, também conhecido como **campainhas hospitalares**, é um conjunto de dispositivos eletrônicos que permitem que os pacientes, acamados ou não, acionem um **sinal sonoro e/ou luminoso** para chamar a atenção dos profissionais de saúde quando precisam de assistência.

Esse sinal é enviado para uma **central de monitoramento**, também chamada de **central de posto de enfermagem**. Como o próprio nome já sugere, a central fica localizada no posto de enfermagem em **local visível a todos os profissionais**.

O sistema de chamada de enfermagem também permite que os profissionais de saúde **registrem a sua presença no leito do paciente** que gerou a chamada, sinalizando ao restante da equipe que o **atendimento está sendo realizado**.

## Como funciona um sistema de chamada de enfermagem?

Um **sistema de chamada de enfermagem** pode ser composto por diferentes tipos de dispositivos, dependendo das necessidades e das características do ambiente de saúde.

Com uma aplicação já tradicional em clínicas, hospitais e centros de saúde nas últimas décadas, em geral, os principais componentes são:

### Estação de Chamada de Enfermagem
Conhecidos como **acionadores** ou **campainhas**, são dispositivos fixados na parede ou em painéis de gases medicinais, e ficam diretamente ao alcance dos pacientes por meio de um **cordão com pera de acionamento altamente sensível ao toque**.

Eles permitem que os pacientes acionem o sistema de chamada, ativando os **sinalizadores de porta** e da **central do posto de enfermagem**, sendo acessíveis mesmo quando há **dificuldades de locomoção e força**.

### Sinaleiro de Porta
Estes dispositivos, fixados **acima da porta do quarto/apartamento**, possuem **sinalização luminosa** com a função de indicar visualmente a existência de uma chamada. Eles podem ter **cores diferentes**, variando entre as tonalidades de **vermelho, azul, verde ou branco**.

### Central de Posto de Enfermagem
A **central de posto de enfermagem** é o dispositivo localizado na recepção ou no próprio posto de enfermagem. Ele é responsável por **sinalizar todas as chamadas em andamento** e o **status do atendimento**.

Este painel pode ser **totalmente personalizável** e permite que **todos os pacientes da unidade sejam monitorados por até um único profissional**.

## Descrição
Este projeto implementa um painel de chamadas interativo com ESP32, utilizando:

- 4 entradas digitais (botões)
- 4 saídas digitais (LEDs)
- Buzzer com controle de desativação temporária
- Sensor de temperatura e umidade DHT22
- Interface Web moderna servida via SPIFFS

## Funcionalidades

- Exibição da temperatura e umidade em tempo real
- Indicadores de entrada ON/OFF (bolinhas vermelhas e verdes)
- Botão para desativar o buzzer por 1 minuto
- Logotipo exibido via arquivo local
- Atualizações automáticas sem recarregar a página (via AJAX)

## Estrutura

```
quadro_de_chamadas/
├── quadro_de_chamadas.ino
└── data/
    ├── index.html
    ├── style.css
    ├── script.js
    └── logo.png
```

## Como Usar

1. Abra o `.ino` na IDE do Arduino.
2. Instale as bibliotecas:
   - WiFi
   - WebServer
   - DHT sensor library
   - Adafruit Unified Sensor
3. Envie os arquivos da pasta `data/` ao SPIFFS usando o plugin ESP32 Sketch Data Upload.
4. Faça upload do código.
5. Acesse o IP do ESP32 no navegador (veja no Serial Monitor).

## Exemplo de resposta JSON

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
## O que é SPIFFS.h?

SPIFFS.h é a biblioteca usada no ESP32 (e também ESP8266) para trabalhar com arquivos salvos na memória flash da placa, como se fosse um mini "pendrive" embutido.
🧠 O que significa SPIFFS?

### SPIFFS = SPI Flash File System

É um sistema de arquivos leve desenvolvido especialmente para microcontroladores que usam memória flash.

**Veja maiores detalhes em spiffs_esp32_guia.md** 

---
Desenvolvido para ESP32 com foco em aplicações didáticas e de automação leve.

