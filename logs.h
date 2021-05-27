//
// Created by Kadu on 18/05/2021.
//

#ifndef EDPROVA1_LOGS_H
#define EDPROVA1_LOGS_H

void incluirLogPreReforma(char *log) {
  FILE *arquivo;

  // Esta é a função de abertura de arquivos. Com modo 'w'(Abrir um arquivo texto para gravação. Se o arquivo não existir, ele será criado.
  // Se já existir, o conteúdo anterior será destruído.)
  arquivo = fopen("logs-iniciais.txt", "a");
//  D:\Kadu\Documents\projetos\EdProva1\logs-iniciais
  //Se o arquivo for não-vazio
  if (arquivo != NULL) {

    // Escreve uma string(da variável 'texto') num arquivo.
    fputs(log, arquivo);
    fputs("\n", arquivo);
    fclose(arquivo);
  }
}

void lerLogs(char *log) {
  puts("Antes da reforma do estacionamento");
  char Linha[100];
  char *result;
  FILE *arquivo;
  if (arquivo == NULL) {
    printf("Problemas na abertura do arquivo\n");
    return;
  }

  while (!feof(arquivo)) {
    result = fgets(Linha, 100, arquivo);  // o 'fgets' lê até 99 caracteres ou até o '\n'
    if (result)  // Se foi possível ler
      printf("%s",Linha);
  }
  fclose(arquivo);
}

void addLog(char *log, Estacionamento *estacionamento) {
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
