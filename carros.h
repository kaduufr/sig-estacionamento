//
// Created by Kadu on 18/05/2021.
//

#ifndef EDPROVA1_CARROS_H
#define EDPROVA1_CARROS_H

int id_carros = 1;

void adicionarCarros( char *placa, bool info, int idC) {
  Carro *carros = estacionamento->carros;
  char *log = malloc(sizeof(char) * 100);
  if (!estacionamento->aberto) {
    puts("Estacionamento Fechado");
    return;
  } else if (estacionamento->total_carros >= MAX_VEICULOS) {
    puts("Estacionamento Lotado!!!");
    addLog("Estacionamento Lotado");
    return;
  } else if(buscarPosicaoDoCarro(estacionamento->carros, placa) > 0) {
    return;
  } else if (semFuncionarios(estacionamento->funcionarios)) {
    puts("Sem funcionarios não é possivel cadastrar um veiculo!!");
    return;
  } else if (semCarros(carros)) {
    carros->prox = novoCarro(placa, idC);
    estacionamento->total_carros++;
    if (info) {
      printf("Carro %s entrou. Total = %d\n", placa, estacionamento->total_carros);
      snprintf(log, sizeof(char) * 100, "Carro %s entrou. Total = %d", placa, estacionamento->total_carros);
      addLog(log);
    }
  } else {
    Carro *tmp = carros->prox;
    while (tmp->prox != NULL) {
      tmp = tmp->prox;
    }
    tmp->prox = novoCarro(placa, idC);
    estacionamento->total_carros++;
    if (info) {
      printf("Carro %s entrou. Total = %d\n", placa, estacionamento->total_carros);
      snprintf(log, sizeof(char) * 100, "Carro %s entrou. Total = %d", placa, estacionamento->total_carros);
      addLog(log);
    }
  }
}

Carro *novoCarro(char *placa, int idC) {
  Carro *novo = (Carro *) malloc(sizeof(Carro));
  if (idC != 0) {
    novo->id = idC;
  } else {
    novo->id = id_carros;
    id_carros++;
  }
  strcpy(novo->placa, placa);
  novo->prox = NULL;
  return novo;
}

void retirarCarro( int tempo, char *placa) {
  if (semCarros(estacionamento->carros)) {
    puts("Estacionamento Vazio");
    return;
  } else {
    int posicao = buscarPosicaoDoCarro(estacionamento->carros, placa);
    if (posicao <= 0) {
      puts("Carro não encontrado");
      return;
    } else if (estacionamento->reformado) {
      if (posicao > (MAX_VEICULOS / 2)) {
        retiraCarroPelaSaida(estacionamento->funcionarios, estacionamento->carros, tempo, placa);
      } else {
        retirarCarroPelaEntrada(estacionamento->funcionarios, estacionamento->carros, tempo, placa);
      }
    } else {
      retirarCarroPelaEntrada(estacionamento->funcionarios, estacionamento->carros, tempo, placa);
    }
    estacionamento->dinheiro = estacionamento->dinheiro + (tempo * 12);
    verificarValorArrecadado(estacionamento);
    if (estacionamentoSemCarros(estacionamento) && !estacionamento->aberto && !estacionamento->reformado) {
      puts("Aguardado a saida de todos os veiculos para iniciar a reforma");
    } else if (estacionamentoSemCarros(estacionamento) && !estacionamento->aberto && estacionamento->reformado) {
      puts("Fechamento do estacionamento");
      addLog("Fechamento do estacionamento");
    }
  }
}

void retirarCarroPelaEntrada( Funcionario *funcionario, Carro *carros, int tempo, char *placa) {

  Carro *quemSaiu;
  Carro *carrosRetirados[MAX_VEICULOS] = {};
  Funcionario *funcionariosRetirados[NUM_FUNCIONARIOS] = {};
  int i = 0, f = 0;

  if (semCarros(carros)) {
    printf("Sem Carros");
    return;
  } else {
    printf("Carro %s devera sair (estadia = %d reais)\n", placa, tempo * 12);
    char *log = malloc(sizeof(char) * 100);
    snprintf(log, sizeof(char) * 100, "Carro %s devera sair (estadia = %d reais)", placa, tempo * 12);
    addLog(log);

    bool kame = false;

    while (kame == false) {
      Carro *ultimo = carros->prox, *penultimo = carros;
      while (ultimo->prox != NULL) {
        penultimo = ultimo;
        ultimo = ultimo->prox;
      }
      if (strcmp(ultimo->placa, placa) == 0) {
        quemSaiu = ultimo;
        printf("Carro %s retirado pelo funcionario %s\n", ultimo->placa, funcionario->prox->nome);
        snprintf(log, sizeof(char) * 100, "--- Carro %s retirado pelo funcionario %s", ultimo->placa, funcionario->prox->nome);
        addLog(log);
        penultimo->prox = NULL;
        funcionariosRetirados[f] = funcionario->prox;
        removerFuncionario(funcionario);
        adicionarFuncionarios(estacionamento->funcionarios, funcionariosRetirados[f]->nome,
                              funcionariosRetirados[f]->id, funcionariosRetirados[f]->idade, false);
        f++;
        estacionamento->total_carros--;
        kame = true;
      } else {
        printf("Carro %s retirado pelo funcionario %s\n", ultimo->placa, funcionario->prox->nome);
        snprintf(log, sizeof(char) * 100, "--- Carro %s retirado pelo funcionario %s", ultimo->placa, funcionario->prox->nome);
        addLog(log);
        carrosRetirados[i] = ultimo;
        penultimo->prox = NULL;
        funcionariosRetirados[f] = funcionario->prox;
        removerFuncionario(funcionario);
        adicionarFuncionarios(estacionamento->funcionarios, funcionariosRetirados[f]->nome,
                              funcionariosRetirados[f]->id, funcionariosRetirados[f]->idade, false);
        f++;
        i++;
        estacionamento->total_carros--;
        penultimo->prox = NULL;
      }
    }

    f = 0;
    *funcionariosRetirados = NULL;

    for (int j = i; 0 < j; --j) {
      adicionarCarros(carrosRetirados[j - 1]->placa, false, carrosRetirados[j - 1]->id);
      funcionariosRetirados[f] = funcionario->prox;
      printf("Carro %s voltou pelo funcionario %s\n", carrosRetirados[j - 1]->placa, funcionariosRetirados[f]->nome);
      snprintf(log, sizeof(char) * 100, "--- Carro %s voltou pelo funcionario %s", carrosRetirados[j - 1]->placa, funcionariosRetirados[f]->nome);
      addLog(log);
      removerFuncionario(funcionario);
      adicionarFuncionarios(estacionamento->funcionarios, funcionariosRetirados[f]->nome, funcionariosRetirados[f]->id,
                            funcionariosRetirados[f]->idade, false);
      f++;
      estacionamento->total_carros++;
    }

    printf("Carro %s saiu! Total = %d\n", quemSaiu->placa, estacionamento->total_carros);
    snprintf(log, sizeof(char) * 100, "Carro %s saiu! Total = %d", quemSaiu->placa, estacionamento->total_carros);
    addLog(log);
  }
}

void retiraCarroPelaSaida(Funcionario *funcionario, Carro *carros, int tempo, char *placa) {
  Carro *quemSaiu;
  Carro *carrosRetirados[MAX_VEICULOS] = {};
  Funcionario *funcionariosRetirados[NUM_FUNCIONARIOS] = {};
  char *log = malloc(sizeof(char) * 100);

  int i = 0, f = 0;

  if (semCarros(carros)) {
    puts("Sem Carros");
    return;
  } else {
    Carro *primeiro = carros->prox, *anterior = carros;
    printf("Carro %s devera sair pelo portao novo (estadia = %d reais)\n", placa, tempo * 12);
    snprintf(log, sizeof(char) * 100, "Carro %s devera sair pelo portao novo (estadia = %d reais)", placa, tempo * 12);
    addLog(log);

    bool parada = false;

    while (!parada) {
      if (primeiro != NULL ){
        if (strcmp(primeiro->placa, placa) == 0) {
          quemSaiu = primeiro;
          printf("Carro %s retirado pelo funcionario %s\n", primeiro->placa, funcionario->prox->nome);
          snprintf(log, sizeof(char) * 100, "--- Carro %s retirado pelo funcionario %s", primeiro->placa, funcionario->prox->nome);
          addLog(log);
          anterior->prox = primeiro->prox;
          funcionariosRetirados[f] = funcionario->prox;
          removerFuncionario(funcionario);
          adicionarFuncionarios(estacionamento->funcionarios, funcionariosRetirados[f]->nome,
                                funcionariosRetirados[f]->id, funcionariosRetirados[f]->idade, false);
          f++;
          estacionamento->total_carros--;
          parada = true;
          break;
        } else {
          printf("Carro %s retirado pelo funcionario %s\n", primeiro->placa, funcionario->prox->nome);
          snprintf(log, sizeof(char) * 100, "--- Carro %s retirado pelo funcionario %s", primeiro->placa, funcionario->prox->nome);
          addLog(log);
          funcionariosRetirados[f] = funcionario->prox;
          carrosRetirados[i] = primeiro;
          removerFuncionario(funcionario);
          adicionarFuncionarios(estacionamento->funcionarios, funcionariosRetirados[f]->nome,
                                funcionariosRetirados[f]->id, funcionariosRetirados[f]->idade, false);
          f++;
          i++;
          estacionamento->total_carros--;
        }

        anterior = primeiro;
        primeiro = primeiro->prox;
      }
      else {
        parada = true;
      }
    }
    for (int j = 0; j < i; ++j) {
      adicionarCarros(carrosRetirados[j]->placa, false, carrosRetirados[j]->id);
      funcionariosRetirados[f] = funcionario->prox;
      printf("Carro %s voltou pelo funcionario %s\n", carrosRetirados[j]->placa, funcionariosRetirados[f]->nome);
      snprintf(log, sizeof(char) * 100, "--- Carro %s voltou pelo funcionario %s", carrosRetirados[j]->placa, funcionariosRetirados[f]->nome);
      addLog(log);
      removerFuncionario(funcionario);
      adicionarFuncionarios(estacionamento->funcionarios, funcionariosRetirados[f]->nome, funcionariosRetirados[f]->id,
                            funcionariosRetirados[f]->idade, false);
      f++;
      estacionamento->total_carros++;
    }
    printf("Carro %s saiu! Total = %d\n", quemSaiu->placa, estacionamento->total_carros);
    snprintf(log, sizeof(char) * 100, "Carro %s saiu! Total = %d", quemSaiu->placa, estacionamento->total_carros);
    addLog(log);
  }
}

bool semCarros(Carro *carros) {
  return carros->prox == NULL;
}

int buscarPosicaoDoCarro(Carro *carros, char *placa) {
  Carro *tmp = carros->prox;
  int count = 1, position;
  while (tmp != NULL) {
    if (strcmp(placa, tmp->placa) == 0) {
      position = count;
    }
    tmp = tmp->prox;
    count++;
  }
  if (position == 1) return 3;
  if (position == 2) return 2;
  if (position == 3) return 1;
  return 0;
}

void imprimirCarros(Carro * carros){
  Carro *tmp = carros->prox;
  while (tmp != NULL) {
    printf("ID: %d \t Placa: %s\n", tmp->id, tmp->placa);
    tmp = tmp->prox;
  }
}

void resetarIdCarros() {
  id_carros = 1;
}

#endif //EDPROVA1_CARROS_H
