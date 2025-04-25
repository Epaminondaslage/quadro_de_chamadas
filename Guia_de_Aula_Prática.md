# Guia de Aula Prática: Montagem do Quadro de Chamadas de Enfermagem

## 🎓 Objetivo da Aula

Capacitar os alunos do **2º ano do Curso de Eletrotécnica** na montagem de um **Quadro de Chamadas de Enfermagem**, a ser instalado na parede externa do **Box 4** do Laboratório de Instalações Prediais.

## 📚 Descrição da Atividade

Cada box terá:
- Um **interruptor tipo pera** para acionar o chamado.
- Uma **arandela vermelha** para sinalizar a solicitação de presença de um profissional de enfermagem.

O quadro central controlará as chamadas via **ESP32**, com registro e monitoramento através de uma **interface web**.

## 🛠️ Materiais Necessários

| Quantidade | Componente                        | Descrição                                 |
|------------|-----------------------------------|---------------------------------------------|
| 1          | Qaudro de Camada de Enfermagem    | Microcontrolador e dispositivos eletronicos internos                 |
| 4          | Interruptor tipo pera             | Acionadores de chamada                     |
| 4          | Arandelas vermelhas (12V ou 127V)  | Indicadores de chamada                     |
| 1          | Fonte 127V (conforme arandela) | Fonte de alimentação das arandelas   |
| Cabos      | Fios para conexões                | Ligação dos dispositivos                  |

## 📊 Esquema de Conexão

- **Interruptores tipo pera** conectados às **entradas digitais** do ESP32 (com resistor de pull-down se necessário).
- **Arandelas** conectadas a **relés**, acionados pelas **saídas digitais** do ESP32.
- **Quandro de Chamadas de Enfermagem** 

## 🔧 Procedimento de Montagem

### 1. Ligação dos Interruptores
- Fixar o interruptor tipo pera em local acessível dentro de cada Box Didático
- Conectar uma extremidade ao GND e a outra a uma entrada digital do ESP32 através do cabo UTP CAT 5 já instalado.

### 2. Ligação das Arandelas
- Instalar a arandela vermelha acima da porta dos Boxes 1 a 4.
- Conectar a arandela a saída de cada um relês.
- O relê será acionado pela saída digital correspondente no ESP32.

### 3. Instalação do Quadro de Chamadas
- Montar todo o circuito na base ( painel ) conectando os condutores conforme esquema que segue.


### 5. Testes Finais
- Acionar cada interruptor e verificar se a respectiva arandela acende.
- Testar o acesso à interface web para monitorar os estados.


## 📊 Atividades Propostas

- Realizar a montagem elétrica completa.
-


