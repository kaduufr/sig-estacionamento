//
// Created by Kadu on 18/05/2021.
//

#ifndef EDPROVA1_LOGS_H
#define EDPROVA1_LOGS_H

void criarArquivos () {
  fopen("logs-sem-reforma.txt", "w");
  fopen("logs-com-reforma.txt", "w");
};

void lerLogs(bool reformado) {
  char Linha[100];
  char *result;
  FILE *arquivo;

  if (!reformado) {
    arquivo = fopen("logs-sem-reforma.txt", "r");
  } else {
    arquivo = fopen("logs-com-reforma.txt", "r");
  }

  if (arquivo == NULL) {
    printf("Problemas na abertura do arquivo\n");
    return;
  }
  puts("--- LOGS ---");

  while (!feof(arquivo)) {
    result = fgets(Linha, 100, arquivo);  // o 'fgets' lê até 99 caracteres ou até o '\n'
    if (result)  // Se foi possível ler
      printf("%s",Linha);
  }
  fclose(arquivo);
}

void addLog(char *log) {
  bool reformado = estacionamento->reformado;
  FILE *arquivo;

  if (reformado) {
    arquivo = fopen("logs-com-reforma.txt", "a");
  } else {
    arquivo = fopen("logs-sem-reforma.txt", "a");
  }

  if (arquivo != NULL) {
    fputs(log, arquivo);
    fputs("\n", arquivo);
    fclose(arquivo);
  }
}

#endif //EDPROVA1_LOGS_H
