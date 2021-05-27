//
// Created by Kadu on 18/05/2021.
//

#ifndef EDPROVA1_ESTACIONAMENTO_H
#define EDPROVA1_ESTACIONAMENTO_H

bool jaAvisou = false;

void iniciarEstacionamento(Estacionamento *estacionamento) {
  estacionamento->aberto = true;
  estacionamento->carros->prox = NULL;
  estacionamento->reformado = false;
  estacionamento->funcionarios->prox = NULL;
  estacionamento->dinheiro = 0;
  estacionamento->max = MAX_VEICULOS;
  estacionamento->total_carros = 0;
}

bool estacionamentoSemCarros(Estacionamento *estacionamento) {
  return estacionamento->carros == 0;
}

bool estacionamentoSemFuncionarios(Estacionamento *estacionamento) {
  return estacionamento->funcionarios->prox == NULL;
}

void reformarEstacionamento(Estacionamento *estacionamento) {
  if (estacionamento->dinheiro >= 300) {
    puts("Reformando estacionamento");
    estacionamento->dinheiro = estacionamento->dinheiro - 300;

  }
}

void verificarValorArrecadado(Estacionamento *estacionamento) {
  if (estacionamento->dinheiro >= 300 && jaAvisou == false) {
    puts("Valor do Portao obtido! Nenhum carro pode entrar!");
    estacionamento->aberto = false;
    jaAvisou = true;
  }
}

#endif //EDPROVA1_ESTACIONAMENTO_H
