# 🔧 Retrofit do Quadro de Chamadas de Enfermagem

## 🔬 O que é Retrofit?

**Retrofit** é o processo de **modernização ou atualização de sistemas, equipamentos ou estruturas existentes**, com o objetivo de aumentar sua eficiência, funcionalidade, segurança e adaptá-los a novas tecnologias, sem a necessidade de substituição completa. É uma **renovação inteligente**: aproveita-se a infraestrutura física existente, mas introduzem-se melhorias técnicas para atender às demandas atuais.

No Laboratório de Instalações Prediais do CEFET-MG temos dois modelos de quadro de chamadas de enfermeiros. 

### 1- Quadro Eletromecânico

Um quadro de chamadas de enfermagem eletromecânico é um sistema simples utilizado em hospitais para indicar que um paciente solicitou ajuda. Cada leito possui um botão que, ao ser pressionado, acende uma luz  e  acionar uma campainha no painel central. O painel, instalado na enfermaria, possui lâmpadas correspondentes a cada leito, e o alarme permanece ativo até ser desligado manualmente.

Esse sistema utiliza componentes como relés, lâmpadas sinalizadoras e fiação dedicada. Apesar de ser robusto, não permite registro digital, priorização de chamados ou visualização remota, tornando-se limitado.
<p align="center">
  <img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/quadro_de_chamadas_eletromecanico.jpg" alt="Painel Eletromecanico" width="40%">
</p>

### 2- Quadro Eletrônico

Um quadro de chamadas de enfermagem eletrônico é um sistema, mais moderno que o eletromecânico, utilizado para indicar que um paciente solicitou atendimento. Cada leito possui um botão de chamada que, ao ser pressionado, envia um sinal elétrico de 12V em corrente contínua (CC), alimentando um LED indicador correspondente no painel central.

O painel, normalmente instalado na enfermaria, contém LEDs sinalizadores para cada leito e uma cigarra sonora (campainha), que é acionada por meio de um relé. O sistema permanece ativo — com o LED aceso e a cigarra tocando — até que o chamado seja cancelado manualmente, geralmente por um botão localizado no leito.

<p align="center">
  <img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/quadro_de_chamadas6.jpeg" alt="Painel atual" width="40%">
</p>

A implementação do retrofit no Quadro de Chamadas de Enfermagem Eletrônico proporciona aos alunos do curso de Eletrotécnica uma experiência prática com tecnologias atuais, promovendo o desenvolvimento de competências em instalações elétricas, automação e Internet das Coisas (IoT).

## 🔧 Aplicação de Retrofit no Quadro de Chamadas de Enfermagem Eletrônico

# 🛠️ Etapas do Retrofit

1. **Avaliação**  
   Inspecionar o sistema existente e identificar falhas e necessidades de atualização.

2. **Definição de Objetivos**  
   Estabelecer metas como modernização, aumento de eficiência ou adequação a normas.

3. **Projeto e Planejamento**  
   Elaborar o novo projeto técnico, selecionar materiais e definir cronograma e orçamento.

4. **Preparação**  
   Desligar e proteger sistemas existentes, remover componentes obsoletos.

5. **Execução**  
   Instalar novos equipamentos e integrar tecnologias modernas.

6. **Testes e Comissionamento**  
   Validar o funcionamento dos novos sistemas e fazer ajustes.

7. **Documentação e Treinamento**  
   Atualizar documentos e treinar os usuários.

8. **Monitoramento Inicial**  
   Acompanhar o desempenho e corrigir eventuais falhas.


No caso do **Quadro de Chamadas de Enfermagem Eletrônico**, o retrofit consistiu em:

- Substituição dos interruptores por tipo  Pera.
- Substituição das arandelas por **Sinalizadores de LEDs** de alta luminosidade**.
- Substituição da campahinha por um sinal audivel eletrônico que pode ser mutado.
- Controle dos chamados utilizando um **microcontrolador ESP32**.
- Atualização do sistema de alimentação para **baixa tensão**, aumentando a segurança e evitando riscos de curtos-circuitos.
- Separacão dos circuitos de controle (ESP32) e de iluminação (LEDs), garantindo maior proteção e robustez.
<table>
  <tr>
    <td align="center">
      <img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/quadro_de_chamadas.jpeg" alt="Detalhe 1" width="70%">
    </td>
    <td align="center">
      <img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/quadro_de_chamadas3.jpeg" alt="Detalhe 2" width="70%">
    </td>
    <td align="center">
      <img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/quadro_de_chamadas5.jpeg" alt="Detalhe 3" width="70%">
    </td>
  </tr>
</table>
  <table>
  <tr>
    <td align="center">
      <img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/quadro_de_chamadas8.jpeg" alt="quadro_de_chamadas" width="70%">
    </td>
    <td align="center">
      <img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/quadro_de_chamadas7.jpeg" alt="quadro_de_chamadas" width="70%">
    </td>
    <td align="center">
      <img src="https://raw.githubusercontent.com/Epaminondaslage/quadro_de_chamadas/main/img/quadro_de_chamadas9.jpeg" alt="quadro_de_chamadas" width="70%">
    </td>
  </tr>
</table>

---

## Benefícios da Modernização do Sistema

A modernização implementada no sistema proporcionou uma série de melhorias relevantes, descritas a seguir:

- **Redução significativa do consumo de energia**  
  A atualização de componentes e a otimização dos circuitos resultaram em um sistema mais eficiente energeticamente, reduzindo o custo operacional e o impacto ambiental.

- **Maior confiabilidade operacional**  
  A substituição de dispositivos obsoletos por equipamentos mais robustos e modernos diminuiu a ocorrência de falhas, aumentando a disponibilidade do sistema e a segurança das operações.

- **Introdução do monitoramento remoto via Wi-Fi**  
  O sistema passou a oferecer acesso remoto em tempo real por meio de uma interface web responsiva, permitindo acompanhamento e gestão das chamadas de forma prática, tanto em dispositivos móveis quanto em computadores.

- **Manutenção da função original de chamada visual**  
  A funcionalidade principal de chamada visual foi preservada, agora utilizando tecnologias mais seguras e duráveis, como LEDs de alta eficiência, garantindo melhor visibilidade e maior vida útil dos componentes.

- **Preparação para futuras expansões**  
  O projeto foi estruturado para permitir novas funcionalidades, como:
  - **Registro de eventos**: Armazenamento de dados de acionamentos para análise e auditoria.
  - **Envio de notificações automáticas**: Alertas enviados por e-mail, SMS ou aplicativos em caso de eventos críticos.
  - **Integração com sistemas de automação predial**: Comunicação com plataformas de automação para controle centralizado de múltiplos sistemas (iluminação, climatização, segurança, etc.).
  - **Implementação de recursos IoT (Internet das Coisas)**:  
    Inclusão de sensores e atuadores inteligentes, com possibilidade de expansão modular e monitoramento integrado à nuvem.
  - **Gravação dos eventos em broker MQTT**:  
    Cada chamada ou evento é registrado em tempo real via protocolo MQTT, permitindo armazenamento seguro, integração com dashboards de monitoramento e acionamento automático de rotinas inteligentes.

---
