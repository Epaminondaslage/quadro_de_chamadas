# Guia: Usando `SPIFFS.h` no ESP32 

# 📦 O que é `SPIFFS.h`?

A biblioteca `SPIFFS.h` permite utilizar a memória **flash interna do ESP32** como um **sistema de arquivos**, possibilitando **armazenar e servir arquivos como HTML, CSS, JavaScript e imagens diretamente da placa**.

---

### ✅ Significado

**SPIFFS** = *SPI Flash File System*  
Sistema de arquivos leve, ideal para microcontroladores com memória flash limitada.

---

## ✅ Para que serve?

Com `SPIFFS`, é possível:

- Criar páginas web embarcadas (HTML/CSS/JS)
- Salvar imagens, logos ou ícones
- Armazenar configurações e logs
- Evitar hardcoding de textos HTML no `.ino`

---

## ✅ Exemplo de uso no código

```cpp
#include "SPIFFS.h"

void setup() {
  SPIFFS.begin(true); // Monta o sistema de arquivos
  server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");
}
```

---

# 📦 Instalar Python 3, mkspiffs e enviar SPIFFS para ESP32 com MSYS2 (Arduino IDE 2.x)

Guia para instalar **Python 3**, `esptool.py`, `mkspiffs` e configurar o **MSYS2 MinGW 64-bit** para trabalhar com o ESP32.

---

## ✅ Etapa 1: Instalar Python 3 e pip

### ✅ 1. Baixar Python 3

[Baixe aqui](https://www.python.org/downloads/)

Marque **"Add Python 3.x to PATH"** na instalação.

### ✅ 2. Verificar instalação

```bash
python --version
pip --version
```

### ✅ 3. Instalar `esptool.py`

```bash
pip install esptool
esptool.py --help
```

---

## ✅ Etapa 2: Instalar o MSYS2

### ✅ 1. Baixar MSYS2

[Baixar aqui](https://www.msys2.org)

Instale em `C:\msys64`.

### ✅ 2. Abrir terminal correto

```
MSYS2 MinGW 64-bit
```

### ✅ 3. Atualizar sistema

```bash
pacman -Syu
```

### ✅ 4. Instalar ferramentas de compilação

```bash
pacman -S mingw-w64-x86_64-toolchain python-pip
```

---

## ✅ Etapa 3: Baixar o mkspiffs

[Download oficial do mkspiffs](https://github.com/earlephilhower/mkspiffs/releases)

Extraia para:

```
C:\esp32tools\mkspiffs.exe
```

---

## ✅ Etapa 4: Preparar o projeto

Estrutura recomendada:

```
meu_projeto/
├── meu_projeto.ino
└── data/
    ├── index.html
    ├── style.css
    └── script.js
```

---

## ✅ Etapa 5: Gerar a imagem SPIFFS

No terminal MSYS2 MinGW 64-bit:

```bash
cd /c/Users/SeuUsuario/Documents/Arduino/meu_projeto
/c/esp32tools/mkspiffs.exe -c data -b 4096 -p 256 -s 0x150000 spiffs.bin
```

---

## ✅ Etapa 6: Enviar a imagem para o ESP32

Identifique a porta COM do seu ESP32 e execute:

```bash
esptool.py --chip esp32 --port COM5 --baud 460800 write_flash 0x290000 spiffs.bin
```

---

## ✅ Endereço da partição SPIFFS

| Esquema de Particionamento            | Endereço |
|----------------------------------------|----------|
| Default 4MB with spiffs (1.2MB app)    | 0x290000 |
| No OTA (2MB APP/2MB SPIFFS)            | 0x290000 |

Verifique em:

> Arduino IDE > Ferramentas > Partition Scheme

---

## ✅ Etapa 7: Servir os arquivos SPIFFS

```cpp
#include "SPIFFS.h"

void setup() {
  SPIFFS.begin(true);
  server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");
}
```

---

## ✅ Etapa 8: Testar no navegador

Acesse o IP do ESP32 no navegador para testar.

---

## ✅ Ambiente pronto!

Sistema configurado para enviar SPIFFS ao ESP32 usando Python 3, mkspiffs e MSYS2 na Arduino IDE 2.x.

---

# 💾 Arquivo BAT para Compilar e Enviar para o ESP32

## 🌟 Objetivo do arquivo `.bat`

Automatizar:

1. Geração da imagem SPIFFS (`spiffs.bin`)
2. Upload da imagem SPIFFS para o ESP32

## 📂 Comandos usados:

### 1. Geração do spiffs.bin

```bash
mkspiffs.exe -c quadro_de_chamadas\quadro_de_chamadas\data -b 4096 -p 256 -s 0x150000 spiffs.bin
```

Parâmetros:
- `-c`: caminho dos arquivos
- `-b 4096`: tamanho do bloco
- `-p 256`: tamanho da página
- `-s 0x150000`: tamanho reservado para SPIFFS

### 2. Upload para ESP32

```bash
python -m esptool --chip esp32 --port COM8 --baud 460800 write_flash 0x290000 spiffs.bin
```

Parâmetros:
- `--chip esp32`: define o chip
- `--port COM8`: porta serial
- `--baud 460800`: velocidade de gravação
- `write_flash 0x290000`: endereço de gravação

---

## 📚 Resumo Simplificado

| Etapa | Ação |
|:-----|:-----|
| 1️⃣ | Gerar imagem SPIFFS |
| 2️⃣ | Gravar SPIFFS no ESP32 |

Ao executar o `.bat`, todo o processo é automático! 

---

## 📦 Arquivos e Ferramentas

| Arquivo/Ferramenta | Função |
|--------------------|---------|
| `mkspiffs.exe`      | Gera imagem SPIFFS |
| `esptool.py`        | Envia imagem para ESP32 |
| `spiffs.bin`        | Imagem dos arquivos |
| `.bat`              | Automatiza processo |

---

