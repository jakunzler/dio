# Desafio

Imagine que você está desenvolvendo um programa de inteligência artificial capaz de classificar animais de acordo com algumas características que o usuário informa. Esse programa deve pedir para o usuário informar as seguintes características do animal:

- Peso em kg
- Altura em cm
- Se tem pelos?
- Se é mamífero?

Com base nessas características, o programa deve classificar o animal em uma das seguintes categorias:

- Elefante (Peso maior igual a 2000kg e altura maior igual a 300cm);
- Cavalo (Tem pelos. É mamífero e a altura igual a 150cm );
- Cachorro (É mamífero. Tem pelos e altura menos igual a 100);
- Serpente (Não tem pelos e não é mamífero);
- Tartaruga (É mamífero e não tem pelos).

Seu programa deve exibir na tela a classificação do animal ou informar que não foi possível classificar o animal com base nas informações fornecidas.

## Entrada

A entrada deve receber os valores abaixo:

- Peso: o peso do animal em Kg (usar o tipo float);
- Altura: a altura do animal em cm (usar o tipo float);
- Pelos: se possui pelos (usar o tipo char para 's' ou 'n', sim e não respectivamente);
- Mamifero: se é um mamífero (usar o tipo char para 's' ou 'n', sim e não respectivamente).

## Saída

O código deverá receber as informações fornecidas acima, após isso, deverá retornar uma mensagem (string) informando a classificação do animal de acordo com as características fornecidas pelo usuário. A mensagem será diferente de acordo com a categoria do animal, e pode ter a seguinte forma:

- O animal é um elefante!

Caso o peso seja maior que 2000kg e a altura maior que 300cm;

- O animal é um cavalo!

Caso o animal seja mamífero, tenha pelos e altura igual a 150cm;

- O animal é um cachorro!

Caso o animal seja mamífero, tenha pelos e altura menor ou igual a 100cm;

- O animal é uma serpente!

Caso o animal não seja mamífero e não tenha pelos;

- O animal é uma tartaruga!

Caso o animal seja mamífero e não tenha pelos;

- Não foi possível classificar o animal!

Caso o animal não contemple nenhuma das condições fornecidas acima.

## Exemplos

A tabela abaixo apresenta exemplos com alguns dados de entrada e suas respectivas saídas esperadas. Certifique-se de testar seu programa com esses exemplos e com outros casos possíveis.

| Entrada | Saída                                                |
|---------|------------------------------------------------------|
| P=1500, A=200, temPelos=s, ehMamifero=s       | O animal é um cachorro! |
| P=500, A=80, temPelos=s, ehMamifero=s      | Não foi possível classificar o animal! |
| P=2500, A=200, temPelos=s, ehMamifero=s       | O animal é um elefante! |
