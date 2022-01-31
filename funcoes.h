#ifndef FUNCOES_H
#define FUNCOES_H

void TabelaUm();
char* ConvertImportanciaParaPalavra(int imp);
char* ConvertEstadoEmPalavra( int estado );
struct tm DataHoje();

// 1 - Nao esta atrasado    0 - Atrasado
int VerificarSeTarefaEstaAtrasada(int dia, int mes, int ano);
void TabelaDois();
void TabelaTres();

#endif // FUNCOES_H
