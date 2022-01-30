#include <time.h>

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

int TabelaUm(){
  printf("\n\nGestor de tarefas\n");
  printf("\n1. Insira uma Tarefa");
  printf("\n2. Dar uma tarefa como concluida");
  printf("\n3. Consulta geral");
  printf("\n4. Tarefas nao concluidas, dada uma importancia");
  printf("\n5. Resumo do estado das Tarefas");
  printf("\n6. Guardar Dados\n");
  printf("\n7. Sair do Programa\n\n");
}

int TabelaDois(){
  printf("Insira o nome da tarefa(1), a sua importancia(2) e a data limite(3):\n");
  printf("A importancia deve ser introduzida com numeros de 1 a 3 sendo que:\n\n");
  printf("1: Alta\n");
  printf("2: Media\n");
  printf("3: Baixa\n");
  printf("\nA data limite deve ser introduzida no formato dia-mes-ano (ex: 24-03-2022)\n");
}

int TabelaTres(){
  printf("-------------------- Tarefas nao concluidas, dada uma importancia --------------------");
  printf("\n\nInsira a importancia da tarefa:");
  printf("\n1: Alta\n");
  printf("2: Media\n");
  printf("3: Baixa\n");
}

int diaHoje(){
    time_t t = time(NULL);
    struct tm tms = *localtime(&t);
    return tms.tm_mday;
}

int mesHoje(){
    time_t t = time(NULL);
    struct tm tms = *localtime(&t);
    return tms.tm_mon + 1;
}

int anoHoje(){
    time_t t = time(NULL);
    struct tm tms = *localtime(&t);
    return tms.tm_year + 1900;
}

int VerificarSeTarefaEstaAtrasada(int dias, int mes, int ano){

}
