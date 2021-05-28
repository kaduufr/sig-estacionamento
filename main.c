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
  estacionamento = (Estacionamento *) malloc(sizeof(Estacionamento));
  Funcionario *funcionarios = (Funcionario *) malloc(sizeof(Funcionario));
  Carro *carros = (Carro *) malloc(sizeof(Carro));

  criarArquivos();

  estacionamento->funcionarios = funcionarios;
  estacionamento->carros = carros;

  iniciarEstacionamento(estacionamento);
  int rodar = 0;
  while (rodar == 0) {
    rodar = menu(estacionamento);
    puts("");
  }

  lerLogs(estacionamento->reformado);

  return 0;
}
