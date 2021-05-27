//
// Created by Kadu on 27/05/2021.
//

#ifndef EDPROVA1_MENU_H
#define EDPROVA1_MENU_H

enum options {
  Sair = 0,
  AdicionarFuncionario = 1,
  OrdenarPorID = 2,
  OrdenarPorNome = 3,
  OrdenarPorIdade = 4,
  ListarFuncionarios = 5,
  AdicionarCarro = 6,
  RetirarCarro = 7,
  Reformar = 8
};
int menu (Estacionamento * estacionamento) {
  puts("Bem Vindo ao Sistemas do Estacionamento");
  puts("Escolha uma das opçoes desejadas");
  printf("Dinheiro Total: %d\n", estacionamento->dinheiro);



  puts("1 - Adicionar Funcionario");
  puts("2 - Ordenar Funcionarios Por ID");
  puts("3 - Ordenar Funcionarios Por Nome");
  puts("4 - Ordenar Funcionarios Por Idade");
  puts("5 - Listar Funcionarios");
  puts("6 - Adicionar Carro");
  puts("7 - Retirar Carro");
  puts("8 - Reformar Estacionamento");
  puts("0 - Sair");

  int opcao = 0, idade = 0, tempo_gasto = 0;
  scanf("%d", &opcao);
  char *nome, *placa;

  switch (opcao) {
    case AdicionarFuncionario:
      puts("Nome do Funcionario:");
      nome = malloc(sizeof(char) * 5);
      scanf("%s",nome);
      fflush(stdin);
      puts("Idade do funcionario");
      scanf("%d", &idade);
      fflush(stdin);
      adicionarFuncionarios(estacionamento->funcionarios, nome, 0, idade, true);
      break;
    case ListarFuncionarios:
      imprimirFuncionarios(estacionamento->funcionarios);
      break;
    case OrdenarPorID:
      ordenar(estacionamento->funcionarios->prox, 1);
      break;
    case OrdenarPorNome:
      ordenar(estacionamento->funcionarios->prox, 2);
      break;
    case OrdenarPorIdade:
      ordenar(estacionamento->funcionarios->prox, 3);
      break;
    case AdicionarCarro:
      puts("Informe a placa do Veiculo:");
      placa = malloc(sizeof(char) * 5);
      scanf("%s",placa);
      fflush(stdin);
      adicionarCarros(estacionamento, placa, true);
      break;
    case RetirarCarro:
      puts("Informe a placa do Veiculo:");
      placa = malloc(sizeof(char) * 5);
      scanf("%s",placa);
      fflush(stdin);
      puts("Quantas horas?");
      scanf("%d", &tempo_gasto);
      retirarCarro(estacionamento, tempo_gasto, placa);
    case Reformar:
      estacionamento->aberto = false;
      reformarEstacionamento(estacionamento);
      break;
    default:
      return 1;
  }
  return 0;
}

#endif //EDPROVA1_MENU_H
