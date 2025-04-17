
# Guia Completo: Usando `SPIFFS.h` no ESP32 com Arduino

## 📦 O que é `SPIFFS.h`?

A biblioteca `SPIFFS.h` permite que você use a memória **flash interna do ESP32** como um **sistema de arquivos**. Isso significa que você pode **armazenar e servir arquivos como HTML, CSS, JavaScript e imagens diretamente da placa**.

---

## 🧠 Significado

**SPIFFS** = *SPI Flash File System*  
É um sistema de arquivos leve, ideal para microcontroladores com memória flash limitada.

---

## 🔧 Para que serve?

Com `SPIFFS`, você pode:

- Criar páginas web embarcadas (HTML/CSS/JS)
- Salvar imagens, logos ou ícones
- Armazenar configurações e logs
- Evitar hardcoding de textos HTML no seu `.ino`

---

## ⚙️ Exemplo de uso no código:

```cpp
#include "SPIFFS.h"

void setup() {
  SPIFFS.begin(true); // Monta o sistema de arquivos
  server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");
}
```
