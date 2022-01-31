#ifndef FUNCOES_H
#define FUNCOES_H

//Trabalho realizado por: Bruno Luís Afonso Lopes
//Unidade Curricular: Fundamentos de Programação 2021/2022

/*
funcoes.h: 

    Este ficheiro tem como objetivo guardar declaração das funções de cada ficheiro .c, ou seja,
contém apenas os prototipos necessarios para o correto funcionamento do programa.
Não contém código executavel.

*/

//prototipos
void TabelaUm();
char* ConvertImportanciaParaPalavra(int imp);
char* ConvertEstadoEmPalavra( int estado );
struct tm DataHoje();
// 1 - Nao esta atrasado    0 - Atrasado
int VerificarSeTarefaEstaAtrasada(int dia, int mes, int ano);
void TabelaDois();
void TabelaTres();




#endif // FUNCOES_H
