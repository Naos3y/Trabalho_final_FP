#include <stdio.h>
#include <time.h>
#include "funcoes.h"

void TabelaUm(){
  printf("\n\nGestor de tarefas\n");
  printf("\n1. Insira uma Tarefa");
  printf("\n2. Dar uma tarefa como concluida");
  printf("\n3. Consulta geral");
  printf("\n4. Tarefas nao concluidas, dada uma importancia");
  printf("\n5. Resumo do estado das Tarefas");
  printf("\n6. Guardar Dados\n");
  printf("\n7. Sair do Programa\n\n");
}
char* ConvertImportanciaParaPalavra( int imp ){
  switch( imp ){
    case 1 : return "Alta";
    case 2 : return "Media";
    case 3 : return "Baixa";
  }
  // Como a importancia esta definido entre 1 e 3, a função nunca vai retornar "valor"
  return "-----";
}
char* ConvertEstadoEmPalavra( int estado ){
  switch( estado ){
    case 0 : return "Por Fazer";
    case 1 : return "Concluida";
  }
  // Como o estado esta definido entre 0 e 1, a função nunca vai retornar "estado"
  return "estado";
}
struct tm DataHoje(){
  time_t t = time(NULL);
  struct tm hoje = *localtime(&t);
  hoje.tm_mon = hoje.tm_mon + 1;
  hoje.tm_year = hoje.tm_year + 1900;
  return hoje;
}
int VerificarSeTarefaEstaAtrasada(int dia, int mes, int ano){
  struct tm dataHoje = DataHoje();
  // tm_year so é usado no dataHoje pois a função DataHoje retorna uma data "inteira", logo nao é um
  // int. Desta forma seleciona apenas o ano/ mes / dia que queremos comprar.
  if(dataHoje.tm_year > ano){
    return 0;
  }else if(dataHoje.tm_year < ano){
    return 1;
  }else{
    if(dataHoje.tm_mon > mes){
      return 0;
    }else if(dataHoje.tm_mon < mes){
      return 1;
    }else{
      if(dataHoje.tm_mday > dia){
        return 0;
      }else{
        return 1;
      }
    }
  }
}
void TabelaDois(){
  printf("Insira o nome da tarefa(1), a sua importancia(2) e a data limite(3):\n");
  printf("A importancia deve ser introduzida com numeros de 1 a 3 sendo que:\n\n");
  printf("1: Alta\n");
  printf("2: Media\n");
  printf("3: Baixa\n");
  printf("\nA data limite deve ser introduzida no formato dia-mes-ano (ex: 24-03-2022)\n");
}
void TabelaTres(){
  printf("-------------------- Tarefas nao concluidas, dada uma importancia --------------------");
  printf("\n\nInsira a importancia da tarefa:");
  printf("\n1: Alta\n");
  printf("2: Media\n");
  printf("3: Baixa\n");
}