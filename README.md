

# Projeto: Quadro Sinalizador de Chamadas

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

---
Desenvolvido para ESP32 com foco em aplicações didáticas e de automação leve.

