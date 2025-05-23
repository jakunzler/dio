# Desafio

Neste desafio, você deve criar um programa que simule o auxílio de vendas de um site de catálogos de cogumelos utilizando inteligência artificial. O intuito é oferecer aos clientes sugestões de cogumelos que estão em promoção. Dessa forma, o programa deve permitir que o usuário informe o nome de um cogumelo desejado e, com base nessa informação, deve sugerir até dois cogumelos adicionais da lista, cujos valores sejam iguais ou menores que o do cogumelo selecionado pelo cliente. No caso de não haver sugestões disponíveis, ou seja, se o cogumelo escolhido for o mais caro, o programa deve exibir uma mensagem indicando que não há sugestões.

A baixo apresentamos a lista de cogumelos oferecidos pela loja com todos os seus valores. Considere que essa lista já está ordenada por prioridade, ou seja, você deve oferecer como alternativas nessa ordem:

| Cogumelo | Valor                                                |
|---------|------------------------------------------------------|
| Shitake | 10 |
| Portobello|  8 |
| Shimeji|  6 |
| Champignon | 12 |
| Funghi | 16 |
| Porcini | 16 |

## Entrada

A entrada será uma string representando o nome do cogumelo desejado pelo usuário.

## Saída

Uma lista com no máximo 2 sugestões de cogumelos mais baratos do que o enviado como entrada. Lembrando que a sugestão das alternativas deve considerar a lista de cogumelos na ordem descrita na tabela supracitada neste desafio.

IMPORTANTE: Considere que cada saída (cogumelo selecionado) deve está em linhas diferentes.

## Exemplos

A tabela abaixo apresenta exemplos com alguns dados de entrada e suas respectivas saídas esperadas. Certifique-se de testar seu programa com esses exemplos e com outros casos possíveis.

| Entrada | Saída                                                |
|---------|------------------------------------------------------|
| Shitake | Portobello - Valor: 8; Shimeji - Valor: 6 |
| Champignon | Shitake - Valor: 10; Portobello - Valor: 8 |
| Portobello | Shimeji - Valor: 6 |
| Shimeji | Desculpe, não há sugestões disponíveis.  |
