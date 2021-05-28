//
// Created by Kadu on 18/05/2021.
//

#ifndef EDPROVA1_STRUCTS_H
#define EDPROVA1_STRUCTS_H

#define MAX_VEICULOS 3

// fila
typedef struct funcionario {
  int id;
  char *nome;
  int idade;
  struct funcionario *prox;
} Funcionario;

// Pilha e Lista
typedef struct carro {
  int id;
  char placa[2];
  struct carro *prox;
} Carro;

typedef struct estacionamento {
  bool aberto;
  int total_carros;
  int max;
  int dinheiro;
  bool reformado;
  Funcionario *funcionarios;
  Carro *carros;
} Estacionamento ;

Estacionamento *estacionamento;

#endif //EDPROVA1_STRUCTS_H
