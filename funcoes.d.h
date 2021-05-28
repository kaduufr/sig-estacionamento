//
// Created by Kadu on 18/05/2021.
// arquivo para definicação das funções
//

#ifndef EDPROVA1_FUNCOES_D_H
#define EDPROVA1_FUNCOES_D_H

#define NUM_FUNCIONARIOS 3

// funções do estacionamento
void iniciarEstacionamento();
bool estacionamentoSemCarros();
void reformarEstacionamento();
void verificarValorArrecadado();

//funções do funcionario
void imprimirFuncionarios(Funcionario *funcionarios);
void adicionarFuncionarios(Funcionario *, char *nomeA, int idA, int idadeA, bool);
Funcionario *novoFuncionario(char *nomeA, int idA, int idadeA, bool);
bool semFuncionarios(Funcionario * funcionarios);
void removerFuncionario(Funcionario *funcionarios);
bool funcionarioJaExiste(Funcionario *funcionarios, int id);
void resetarIdFuncionarios();

void ordenar(Funcionario *funcionarios, int tipo);
void ordenarPorId(Funcionario *funcionarios);
void ordenarPorIdade(Funcionario *funcionarios);
void ordenarPorNome(Funcionario *funcionarios);

// funções do carro
void adicionarCarros(char *placa, bool, int id);
Carro *novoCarro(char *placa, int id);
void retirarCarroPelaEntrada( Funcionario *funcionario, Carro *carros, int tempo, char *placa);
void retiraCarroPelaSaida( Funcionario *funcionario, Carro *carros, int tempo, char *placa);
bool semCarros(Carro *carros);
void retirarCarro( int tempo, char *placa);
int buscarPosicaoDoCarro(Carro *carros, char *placa);
void resetarIdCarros();

// funções de log
void criarArquivos();
void addLog(char *log);
void lerLogs();
#endif //EDPROVA1_FUNCOES_D_H
