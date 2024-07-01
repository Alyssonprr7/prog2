# Trabalho de Programação II - Algoritmos de Ordenação
### Universidade Federal Fluminense (UFF) - Sistemas de Informação

## Descrição
Este projeto implementa três algoritmos de ordenação: Selection Sort, Bubble Sort e Merge Sort. As implementações são feitas tanto para arrays quanto para listas simplesmente encadeadas.

## Integrantes
- Alysson Rocha
- Guilherme Mendes
- Daniel Nery

## Estrutura do Projeto
O projeto está estruturado da seguinte forma:
````
├── main.c
├── sort_trabalho.c
├── sort_trabalho.h
├── lista
│ ├── lista.c
│ └── lista.h
└── README.md
````

- `main.c`: Arquivo principal que contém a função `main`.
- `sort_trabalho.c` e `sort_trabalho.h`: Implementações e declarações dos algoritmos de ordenação.
- `lista/lista.c` e `lista/lista.h`: Implementações e declarações das operações em listas simplesmente encadeadas.

## Compilação e Execução
Para compilar e executar o código, utilize o seguinte comando:

```sh
gcc -o main ./main.c ./sort_trabalho.c ./lista/lista.c && ./main
