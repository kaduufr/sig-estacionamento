//
// Created by Kadu on 18/05/2021.
//

#ifndef EDPROVA1_FUNCIONARIOS_H
#define EDPROVA1_FUNCIONARIOS_H

int id = 1;

void adicionarFuncionarios(Funcionario *funcionarios, char *nomeA, int idA, int idadeA, bool info) {
  if (semFuncionarios(funcionarios)) {
    funcionarios->prox = novoFuncionario(nomeA, idA, idadeA, info);
  } else if (funcionarioJaExiste(funcionarios, idA)) {
    return;
  } else {
    Funcionario *tmp = funcionarios->prox;
    while (tmp->prox != NULL) {
      tmp = tmp->prox;
    }
    tmp->prox = novoFuncionario(nomeA, idA, idadeA, info);
  }
}

Funcionario *novoFuncionario(char *nomeA, int idA, int idadeA, bool info) {

  Funcionario *novo = (Funcionario *) malloc(sizeof(Funcionario));

  if (nomeA != NULL && idA != 0 && (void *) idadeA != NULL) {
    novo->id = idA;
    novo->idade = idadeA;
    novo->prox = NULL;
    novo->nome = nomeA;
  } else if (nomeA != NULL && idA == 0) {
    novo->nome = nomeA;
    novo->prox = NULL;
    novo->idade = idadeA;
    novo->id = id;
  } else {
    int idade = rand() % 50;
    while (idade < 18 || idade >= 50) {
      idade = rand() % 50;
    }
    novo->id = id;
    novo->idade = idade;
    novo->prox = NULL;
    char *nome = malloc(sizeof(char) * 4);
    snprintf(nome, sizeof(char) * 4, "X%d", id);
    novo->nome = nome;
  }
  if (info) {
    printf("Funcionario de nome %s (ID = %d, Idade = %d) cadastrado\n", novo->nome, novo->id, novo->idade);
    char *log = malloc(sizeof(char) * 100);
    snprintf(log, sizeof(char) * 100, "Funcionario de nome %s (ID = %d, Idade = %d) cadastrado", novo->nome, novo->id,
             novo->idade);
    addLog(log);
  }
  id++;
  return novo;
}

void imprimirFuncionarios(Funcionario *funcionarios) {
  if (semFuncionarios(funcionarios)) {
    puts("Sem funcionarios cadastrados");
    return;
  }
  Funcionario *tmp = funcionarios->prox;
  while (tmp != NULL) {
    printf("ID: %d \t Nome: %s \t Idade: %d \n", tmp->id, tmp->nome, tmp->idade);
    tmp = tmp->prox;
  }
}

bool semFuncionarios(Funcionario *funcionarios) {
  return funcionarios->prox == NULL;
}

void ordenarPorNome(Funcionario *functionarios) {

  Funcionario *aux = functionarios, *t;
  char s[100];

  while (aux != NULL) {
    t = aux->prox;
    while (t != NULL) {
      if (strcmp(aux->nome, t->nome) > 0) {
        Funcionario tmp = *t;

//        strcpy(t->nome, aux->nome);
        t->nome = aux->nome;
        t->id = aux->id;
        t->idade = aux->idade;

//        strcpy(aux->nome, tmp.nome);
        aux->nome = tmp.nome;
        aux->id = tmp.id;
        aux->idade = tmp.idade;
      }
      t = t->prox;
    }
    aux = aux->prox;
  }
  addLog("Ordenacao usada: NOME");
}

void ordenarPorIdade(Funcionario *funcionarios) {

  Funcionario *aux = funcionarios, *t;

  while (aux != NULL) {
    t = aux->prox;
    while (t != NULL) {
      if (aux->idade > t->idade) {
        Funcionario tmp = *t;

        t->nome = aux->nome;
        t->id = aux->id;
        t->idade = aux->idade;

//        strcpy(aux->nome, tmp.nome);
        aux->nome = tmp.nome;
        aux->id = tmp.id;
        aux->idade = tmp.idade;
      }
      t = t->prox;
    }
    aux = aux->prox;
  }
  addLog("Ordenacao usada: IDADE");
}

void ordenarPorId(Funcionario *funcionarios) {

  Funcionario *aux = funcionarios, *t;

  while (aux != NULL) {
    t = aux->prox;
    while (t != NULL) {
      if (aux->id > t->id) {
        Funcionario tmp = *t;

//        strcpy(t->nome, aux->nome);
        t->nome = aux->nome;
        t->id = aux->id;
        t->idade = aux->idade;

//        strcpy(aux->nome, tmp.nome);
        aux->nome = tmp.nome;
        aux->id = tmp.id;
        aux->idade = tmp.idade;
      }
      t = t->prox;
    }
    aux = aux->prox;
  }
  addLog("Ordenacao usada: ID");
}

void ordenar(Funcionario *funcionarios, int tipo) {

  if (semFuncionarios(funcionarios)) {
    puts("Sem funcionarios!!");
    return;
  } else {

    if (funcionarios == NULL || (funcionarios)->prox == NULL) return;
    switch (tipo) {
//    1: ordenar pelo id
      case 1:
        ordenarPorId(funcionarios);
        break;
//    2: ordenar pelo nome
      case 2:
        ordenarPorNome(funcionarios);
        break;
//    3: ordenar pelo idade
      case 3:
        ordenarPorIdade(funcionarios);
        break;
      default:
        ordenarPorId(funcionarios);
        break;
    }
  }

}

void removerFuncionario(Funcionario *funcionarios) {
  if (semFuncionarios(funcionarios)) {
    puts("Sem funcionarios cadastrados");
    return;
  } else {
    Funcionario *tmp = funcionarios->prox;
    funcionarios->prox = tmp->prox;
  }
}

bool funcionarioJaExiste(Funcionario *funcionarios, int id) {
  Funcionario *tmp = funcionarios->prox;
  while (tmp != NULL) {
    if (tmp->id == id) {
      return true;
    }
    tmp = tmp->prox;
  }
  return false;
}

void resetarIdFuncionarios() {
  id = 1;
}

#endif //EDPROVA1_FUNCIONARIOS_H
