//
// Created by Kadu on 18/05/2021.
//

#ifndef EDPROVA1_FUNCIONARIOS_H
#define EDPROVA1_FUNCIONARIOS_H

// se quiser que sejam mais funcionarios, altere esse valor.

int id = 1;

void adicionarFuncionarios(Funcionario *funcionarios, char *nomeA, int idA, int idadeA) {
  int i=0;
  while (i < NUM_FUNCIONARIOS) {
    if (semFuncionarios(funcionarios)) {
      funcionarios->prox = novoFuncionario(nomeA,idA,idadeA);
    } else if (funcionarioJaExiste(funcionarios, idA)) {
      return;
    } else {
      Funcionario *tmp = funcionarios->prox;
      while (tmp->prox != NULL) {
        tmp = tmp->prox;
      }
      tmp->prox = novoFuncionario(nomeA,idA,idadeA);
    }
    i++;
  }
}

Funcionario* novoFuncionario(char *nomeA, int idA, int idadeA) {

  Funcionario *novo = (Funcionario *) malloc(sizeof(Funcionario));

  if (nomeA != NULL && (void *) idA != NULL && (void *) idadeA != NULL) {
    novo->id = idA;
    novo->idade = idadeA;
    novo->prox = NULL;
    novo->nome = nomeA;
  } else {
    int idade = rand() % 50;
    while (idade< 18 || idade>= 50) {
      idade = rand() % 50;
    }
    novo->id = id;
    novo->idade = idade;
    novo->prox = NULL;
    char *nome = malloc(sizeof(char) * 4);
    snprintf(nome, sizeof(char) * 4, "X%d", id);
    novo->nome = nome;
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
    printf("%s\n", tmp->nome);
    tmp = tmp->prox;
  }
}

bool semFuncionarios(Funcionario *funcionarios) {
  return funcionarios->prox == NULL;
}

#endif //EDPROVA1_FUNCIONARIOS_H


void ordenarPorNome(Funcionario *functionarios) {

  Funcionario *aux = functionarios, *t;
  char s[100];

  while(aux != NULL) {
    t = aux->prox;
    while(t != NULL) {
      if(strcmp(aux->nome, t->nome) > 0) { //se vir depois
        Funcionario tmp = *t;

        strcpy(t->nome, aux->nome);
//        t->nome = aux->nome;
        t->id = aux->id;
        t->idade = aux->idade;

        strcpy(aux->nome, tmp.nome);
//        aux->nome = tmp.nome;
        aux->id = tmp.id;
        aux->idade = tmp.idade;
      }
      t = t->prox;
    }
    aux = aux->prox;
  }
}

void ordenarPorIdade(Funcionario *funcionarios) {

  Funcionario *aux = funcionarios, *t;

  while(aux != NULL) {
    t = aux->prox;
    while(t != NULL) {
      if(aux->idade > t->idade) {
        Funcionario tmp = *t;

        t->nome = aux->nome;
        t->id = aux->id;
        t->idade = aux->idade;

        aux->nome = tmp.nome;
        aux->id = tmp.id;
        aux->idade = tmp.idade;
      }
      t = t->prox;
    }
    aux = aux->prox;
  }
}

void ordenarPorId(Funcionario *funcionarios) {

  Funcionario *aux = funcionarios, *t;

  while(aux != NULL) {
    t = aux->prox;
    while(t != NULL) {
      if(aux->idade > t->idade) {
        Funcionario tmp = *t;

        t->nome = aux->nome;
        t->id = aux->id;
        t->idade = aux->idade;

        aux->nome = tmp.nome;
        aux->id = tmp.id;
        aux->idade = tmp.idade;
      }
      t = t->prox;
    }
    aux = aux->prox;
  }
}

void ordenar(Funcionario *funcionarios, int tipo){
  if(funcionarios == NULL || (funcionarios)->prox == NULL) return;

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