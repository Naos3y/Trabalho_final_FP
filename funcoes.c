#include <stdio.h>

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
