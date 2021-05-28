//
// Created by Kadu on 18/05/2021.
//

#ifndef EDPROVA1_ESTACIONAMENTO_H
#define EDPROVA1_ESTACIONAMENTO_H

bool jaAvisou = false;

void iniciarEstacionamento() {
  estacionamento->aberto = true;
  estacionamento->carros->prox = NULL;
  estacionamento->reformado = false;
  estacionamento->funcionarios->prox = NULL;
  estacionamento->dinheiro = 0;
  estacionamento->max = MAX_VEICULOS;
  estacionamento->total_carros = 0;

  char *log = malloc(sizeof(char) * 100);
  snprintf(log, sizeof(char) * 100, "Abertura do Estacionamento ( lotacao maxima = %d )", MAX_VEICULOS);
  addLog(log);
}

bool estacionamentoSemCarros() {
  return estacionamento->total_carros == 0;
}

void reformarEstacionamento() {
  if (estacionamento->reformado) {
    puts("Este estacionamento ja foi reformado!");
    return;
  }
  if (estacionamento->dinheiro >= 300) {
    lerLogs();

    puts("Reformando estacionamento");

    Funcionario *funcionarios = (Funcionario *) malloc(sizeof(Funcionario));
    Carro *carros = (Carro *) malloc(sizeof(Carro));

    estacionamento->dinheiro = estacionamento->dinheiro - 300;
    estacionamento->reformado = true;
    estacionamento->funcionarios = funcionarios;
    estacionamento->carros = carros;
    estacionamento->aberto = true;
    estacionamento->max = MAX_VEICULOS;
    estacionamento->total_carros = 0;
    estacionamento->carros->prox = NULL;
    estacionamento->funcionarios->prox = NULL;

    resetarIdCarros();
    resetarIdFuncionarios();

    puts("Estacionamento Aberto");
    char *log = malloc(sizeof(char) * 100);
    snprintf(log, sizeof(char) * 100, "Abertura do Estacionamento ( lotacao maxima = %d )", MAX_VEICULOS);
    addLog(log);
  }
}

void verificarValorArrecadado() {
  if (estacionamento->dinheiro >= 300 && jaAvisou == false) {
    puts("Valor do Portao obtido! Nenhum carro pode entrar!");
    addLog("Valor do Portao obtido! Nenhum carro pode entrar!");
    estacionamento->aberto = false;
    jaAvisou = true;
  }
}

#endif //EDPROVA1_ESTACIONAMENTO_H
