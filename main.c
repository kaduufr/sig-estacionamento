#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"

#include "structs.h"
#include "funcoes.d.h"
#include "carros.h"
#include "estacionamento.h"
#include "funcionarios.h"
#include "logs.h"

int main() {
  puts("Abrindo estacionamento");
  Estacionamento *estacionamento = (Estacionamento *) malloc(sizeof(Estacionamento));
  Funcionario *funcionarios = (Funcionario *) malloc(sizeof(Funcionario));
  Carro *carros = (Carro *) malloc(sizeof(Carro));

  estacionamento->funcionarios = funcionarios;
  estacionamento->carros = carros;

  iniciarEstacionamento(estacionamento);
  puts("Adicionando Funcionarios");
  adicionarFuncionarios(funcionarios, NULL, NULL, NULL);
  puts("");
  ordenar(estacionamento->funcionarios->prox, 1);
//  imprimirFuncionarios(estacionamento->funcionarios);

  adicionarCarros(estacionamento, "A1");
  adicionarCarros(estacionamento, "A2");
  adicionarCarros(estacionamento, "A3");

  retirarCarro(estacionamento, 12, "A2");

//  if (estacionamentoSemCarros(estacionamento)) puts("Estacionamento vazio!");
  return 0;
}
