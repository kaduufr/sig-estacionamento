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
#include "menu.h"

int main() {
  Estacionamento *estacionamento = (Estacionamento *) malloc(sizeof(Estacionamento));
  Funcionario *funcionarios = (Funcionario *) malloc(sizeof(Funcionario));
  Carro *carros = (Carro *) malloc(sizeof(Carro));

  estacionamento->funcionarios = funcionarios;
  estacionamento->carros = carros;

  iniciarEstacionamento(estacionamento);
  int rodar = 0;
  while (rodar == 0) {
    rodar = menu(estacionamento);
    puts("");
  }
//  puts("Adicionando Funcionarios");
//  adicionarFuncionarios(estacionamento->funcionarios, NULL, NULL, NULL);
//  puts("");
//  ordenar(estacionamento->funcionarios->prox, 1);
////  imprimirFuncionarios(estacionamento->funcionarios);
//
//  adicionarCarros(estacionamento, "A1", true);
//  adicionarCarros(estacionamento, "A2", true);
//  adicionarCarros(estacionamento, "A3", true);
//  adicionarCarros(estacionamento, "A4", true);
//
//  retirarCarro(estacionamento, 12, "A2");
//  retirarCarro(estacionamento, 15, "A3");
//  retirarCarro(estacionamento, 20, "A1");

//  if (estacionamentoSemCarros(estacionamento)) puts("Estacionamento vazio!");
  return 0;
}
