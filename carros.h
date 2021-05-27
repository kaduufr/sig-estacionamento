//
// Created by Kadu on 18/05/2021.
//

#ifndef EDPROVA1_CARROS_H
#define EDPROVA1_CARROS_H

int id_carros = 1;

void adicionarCarros(Estacionamento *estacionamento, char *placa) {
  Carro *carros = estacionamento->carros;
  if (!estacionamento->aberto) {
    puts("Estacionamento Fechado");
  } else if (estacionamento->total_carros >= 3) {
    printf("Estacionamento cheio!!!");
    return;
  } else if (semCarros(carros)) {
    carros->prox = novoCarro(placa);
    estacionamento->total_carros++;
  } else {
    Carro *tmp = carros->prox;
    while (tmp->prox != NULL) {
      tmp = tmp->prox;
    }
    tmp->prox = novoCarro(placa);
    estacionamento->total_carros++;
  }
}

Carro *novoCarro(char *placa) {
  Carro *novo = (Carro *) malloc(sizeof(Carro));
  novo->id = id_carros;
  strcpy(novo->placa, placa);
  novo->prox = NULL;
}

void retirarCarro(Estacionamento *estacionamento, int tempo, char *placa) {
  if (estacionamento->reformado) {
    int posicao = buscarPosicaoDoCarro(estacionamento->carros, placa);
    if (posicao <= 0) {
      puts("Carro não encontrado");
    } else {
      if (posicao >= (int) (id_carros / 2)) {
        retirarCarroPelaSaida(estacionamento,estacionamento->funcionarios, estacionamento->carros, tempo, placa);
      } else {
        retirarCarroPelaEntrada(estacionamento->funcionarios, estacionamento->carros, tempo, placa);
      }
    }
  } else {
    retirarCarroPelaSaida(estacionamento,estacionamento->funcionarios, estacionamento->carros, tempo, placa);
  }
  estacionamento->dinheiro = tempo * 12;
  estacionamento->total_carros--;
}

void retirarCarroPelaSaida(Estacionamento *estacionamento, Funcionario *funcionario, Carro *carros, int tempo, char * placa) {

  Carro *carrosRetirados[MAX_VEICULOS] = {};
  Funcionario *funcionariosRetirados[NUM_FUNCIONARIOS] = {};
  int i = 0, f = 0;

  if (semCarros(carros)) {
    printf("Sem Carros");
    return;
  } else {

    bool kame = false;

    while (kame == false) {
      Carro *ultimo = carros->prox, *penultimo = carros;
      while (ultimo->prox != NULL) {
        penultimo = ultimo;
        ultimo = ultimo->prox;
      }
      if (strcmp(ultimo->placa, placa) == 0) {
        printf("Carro %s retirado pelo funcionario %s\n", ultimo->placa, funcionario->prox->nome);
        penultimo->prox = NULL;
        funcionariosRetirados[f] = funcionario->prox;
        removerFuncionario(funcionario);
        adicionarFuncionarios(estacionamento->funcionarios, funcionariosRetirados[f]->nome, funcionariosRetirados[f]->id, funcionariosRetirados[f]->idade);
        f++;
        estacionamento->total_carros--;
        kame = true;
      } else {
        printf("Carro %s retirado pelo funcionario %s\n", ultimo->placa, funcionario->prox->nome);
        carrosRetirados[i] = ultimo;
        funcionariosRetirados[f] = funcionario->prox;
        removerFuncionario(funcionario);
        adicionarFuncionarios(estacionamento->funcionarios, funcionariosRetirados[f]->nome, funcionariosRetirados[f]->id, funcionariosRetirados[f]->idade);
        f++;
        i++;
        estacionamento->total_carros--;
        penultimo->prox = NULL;
      }
    }

    f = 0;
    *funcionariosRetirados = NULL;

    for (int j = i; 0 < j; --j) {
      adicionarCarros(estacionamento, carrosRetirados[j-1]->placa);
      funcionariosRetirados[f] = funcionario->prox;
      printf("Carro %s voltou pelo funcionario %s\n", carrosRetirados[j-1]->placa, funcionariosRetirados[f]->nome);
      removerFuncionario(funcionario);
      adicionarFuncionarios(estacionamento->funcionarios, funcionariosRetirados[f]->nome, funcionariosRetirados[f]->id, funcionariosRetirados[f]->idade);
      f++;
    }
  }
}

void buscandoRemovendo( Carro *carros, char * placa) {
  if (semCarros(carros)) {
    puts("Sem carros");
    return;
  }
  Carro *ultimo = carros->prox, *penultimo = carros;
  while (ultimo->prox != NULL) {
    penultimo = ultimo;
    ultimo = ultimo->prox;
  }
  if (strcmp(ultimo->placa, placa) == 0) {
    penultimo->prox = NULL;
  } else {
    penultimo->prox = NULL;
    buscandoRemovendo(carros, placa);
  }
}

void retirarCarroPelaEntrada(Funcionario *funcionario, Carro *carros, int tempo, char *placa) {
  Funcionario funcionarioTemp = *funcionario;

  if (semCarros(carros)) {
    printf("Sem Carros");
    return;
  } else {
    Carro *ultimo = carros->prox, *penultimo = carros;

    while (ultimo->prox != NULL) {
      penultimo = ultimo;
      ultimo = ultimo->prox;
    }

    penultimo->prox = NULL;

  }
}

bool semCarros(Carro *carros) {
  return carros->prox == NULL;
}

bool estacionamentoCheio(Carro *carros) {

}

int buscarPosicaoDoCarro(Carro *carros, char *placa) {
  Carro *tmp = carros->prox;
  while (tmp != NULL) {
    if (strcmp(placa, tmp->placa) > 0) {
      return tmp->id;
    }
    tmp = tmp->prox;
  }
  return 0;
}

#endif //EDPROVA1_CARROS_H
