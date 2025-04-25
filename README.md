# Projeto: Quadro Sinalizador de Chamadas de Enfermagem

## 📢 O que é um sistema de chamada de enfermagem?

Um **sistema de chamada de enfermagem**, também conhecido como **campainha hospitalar**, é um conjunto de dispositivos eletrônicos que permite que pacientes, acamados ou não, acionem um **sinal sonoro 🔊 e/ou luminoso 🔦** para chamar a atenção da equipe de saúde quando necessitam de assistência.

Esse sinal é enviado para uma **central de monitoramento** 🛋️, localizada em local visível a todos os profissionais.

Além disso, o sistema permite que os profissionais de saúde **registrem a sua presença no leito** do paciente que gerou a chamada, sinalizando ao restante da equipe que o **atendimento está em andamento**.

## 🔧 Como funciona um sistema de chamada de enfermagem?

Um **sistema de chamada de enfermagem** é composto por diferentes dispositivos, adaptados às necessidades do ambiente hospitalar:

### 🛉 Estação de Chamada de Enfermagem

Dispositivos fixados na parede ou painéis de gases medicinais, acessíveis por um **cordão com pera sensível ao toque 🌟**.

### 🔦 Sinaleiro de Porta

Indicadores visuais fixados **acima das portas** para alertar sobre chamadas em andamento, utilizando diferentes **cores 🟥**.

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

---



