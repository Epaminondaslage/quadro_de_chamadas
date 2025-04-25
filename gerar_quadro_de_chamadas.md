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

---

## 📂 SPIFFS (Sistema de Arquivos)

### Estrutura esperada da pasta:

```
quadro_de_chamadas/
├─ quadro_de_chamadas.ino
└─ quadro_de_chamadas/
   └─ data/
      ├─ index.html
      ├─ style.css
      ├─ script.js
      └─ logo.png
```

---

## 🛠 Geração da imagem SPIFFS

Use o seguinte comando:

```cmd
mkspiffs.exe -c quadro_de_chamadas\quadro_de_chamadas\data -b 4096 -p 256 -s 0x150000 spiffs.bin
```

Confirme a saída com:

```
/index.html
/style.css
/script.js
/logo.png
```

---

## 📤 Envio do SPIFFS para o ESP32

```cmd
python -m esptool --chip esp32 --port COM8 --baud 460800 write_flash 0x290000 spiffs.bin
```

---

## 🔍 Monitor Serial

Após reiniciar o ESP32, o monitor deve exibir:

```
WiFi conectado
IP atribuído: 10.0.2.101
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
http://10.0.2.101
```

A interface carregará os dados em tempo real.

---

## 🧩 Problemas comuns

- **"Not found:"** → o SPIFFS não foi gravado corretamente
- **SPIFFS vazio:** verifique se os arquivos estão na pasta `data/` antes de gerar
- **Baudrate ou porta errada:** confirme `COM8` e ajuste se necessário

---

## 🟢 Finalização

- Todos os arquivos devem estar no SPIFFS
- `index.html` deve ser o ponto de entrada
- Use `server.serveStatic("/", SPIFFS, "/")` + `onNotFound` para servir todos os arquivos
