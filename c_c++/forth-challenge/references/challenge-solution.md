# Documentação do Programa `serial_read.ino`

## Objetivo do Programa

O objetivo deste programa é acender um LED de acordo com a letra digitada no monitor serial.

## Autor

Jonas Augusto Kunzler

## Data de Criação

15/07/2024

## Descrição

Este programa lê entradas do monitor serial e acende um LED específico com base na letra digitada:

- `R` acende o LED vermelho.
- `G` acende o LED verde.
- `B` acende o LED azul.

## Código Fonte

```cpp
/*
  Nome do programa: serial_read.ino
  Objetivo do programa: Acender um led de acordo com a letra digitada no monitor serial.
  Autor: Jonas Augusto Kunzler
  Data de criação: 15/07/2024
*/

#define r_led 6 // Definindo a porta do LED vermelho
#define g_led 5 // Definindo a porta do LED verde
#define b_led 4 // Definindo a porta do LED azul

char option; // Criando variável chamada option

void setup()
{
  pinMode(r_led, OUTPUT); // Definindo a porta como saída
  pinMode(g_led, OUTPUT); // Definindo a porta como saída
  pinMode(b_led, OUTPUT); // Definindo a porta como saída

  Serial.begin(9600); // Inicializando a comunicação serial
}

void loop()
{
  option = Serial.read(); // Variável recebe a leitura do teclado

  if(option == 'R') // Se o usuário digitou 'R'
    digitalWrite(r_led, HIGH); // Liga o LED vermelho

  if(option == 'G') // Se o usuário digitou 'G'
    digitalWrite(g_led, HIGH); // Liga o LED verde

  if(option == 'B') // Se o usuário digitou 'B'
    digitalWrite(b_led, HIGH); // Liga o LED azul
}
```

## Explicação do Código

### Definição de Portas

```cpp
#define r_led 6
#define g_led 5
#define b_led 4
```

Estas linhas definem as portas do Arduino às quais os LEDs estão conectados.

### Declaração de Variáveis

```cpp
char option;
```

Cria uma variável chamada `option` para armazenar a letra digitada pelo usuário no monitor serial.

### Função `setup()`

```cpp
void setup()
{
  pinMode(r_led, OUTPUT);
  pinMode(g_led, OUTPUT);
  pinMode(b_led, OUTPUT);
  Serial.begin(9600);
}
```

Nesta função, as portas dos LEDs são configuradas como saídas e a comunicação serial é inicializada com uma taxa de transmissão de 9600 bps.

### Função `loop()`

```cpp
void loop()
{
  option = Serial.read();

  if(option == 'R')
    digitalWrite(r_led, HIGH);

  if(option == 'G')
    digitalWrite(g_led, HIGH);

  if(option == 'B')
    digitalWrite(b_led, HIGH);
}
```

A função `loop()` lê a entrada do monitor serial e, dependendo da letra digitada (`R`, `G` ou `B`), acende o LED correspondente.

## Notas Adicionais

- Certifique-se de que os LEDs estão corretamente conectados às portas definidas no código.
- Verifique a conexão GND para o funcionamento adequado dos LEDs.
- Para apagar os LEDs, você pode adicionar mais comandos `digitalWrite(<porta>, LOW)` no código, ou adaptar o código conforme necessário para desligar os LEDs quando uma entrada específica for recebida.

## Conclusão

Este programa é um exemplo simples de como controlar LEDs através de entradas do monitor serial utilizando um Arduino. Ele pode ser expandido para incluir mais funcionalidades ou integrado a projetos maiores.
