//
// Created by Kadu on 18/05/2021.
// arquivo para definicação das funções
//

#ifndef EDPROVA1_FUNCOES_D_H
#define EDPROVA1_FUNCOES_D_H

#define NUM_FUNCIONARIOS 3

// funções do estacionamento
void iniciarEstacionamento(Estacionamento *estacionamento);
bool estacionamentoSemCarros(Estacionamento *estacionamento);
void reformarEstacionamento(Estacionamento *estacionamento);

//funções do funcionario
void imprimirFuncionarios(Funcionario *funcionarios);
void adicionarFuncionarios(Funcionario *, char *nomeA, int idA, int idadeA);
Funcionario *novoFuncionario(char *nomeA, int idA, int idadeA);
bool semFuncionarios(Funcionario *);
void removerFuncionario(Funcionario *funcionarios);
bool funcionarioJaExiste(Funcionario *funcionarios, int id);

void ordenar(Funcionario *funcionarios, int tipo);
void ordenarPorId(Funcionario *funcionarios);
void ordenarPorIdade(Funcionario *funcionarios);
void ordenarPorNome(Funcionario *funcionarios);

// funções do carro
void adicionarCarros(Estacionamento *, char *);
Carro *novoCarro(char *);
void retirarCarroPelaSaida(Estacionamento *,Funcionario *, Carro *, int , char*);
void retirarCarroPelaEntrada(Funcionario *, Carro *, int , char *);
bool semCarros(Carro *carros);
bool estacionamentoCheio(Carro *carros);
void retirarCarro(Estacionamento *estacionamento, int tempo, char *placa);
void buscandoRemovendo( Carro *carros, char * placa);
int buscarPosicaoDoCarro(Carro *carros, char *);
#endif //EDPROVA1_FUNCOES_D_H
