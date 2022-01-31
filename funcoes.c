#include <stdio.h>
#include <time.h>
#include "funcoes.h"

//Trabalho realizado por: Bruno Luís Afonso Lopes
//Unidade Curricular: Fundamentos de Programação 2021/2022

/*
funcoes.c: 

  Como o ficheiro principal estava a ficar muito grande, foi criado um novo ficheiro para guardar as funçoes
e desta forma melhorar a visualizaçao do ficheiro principal bem como reduzir significativamente o seu tamanho.
No entanto a criaçao desde ficheiro nao é suficiente, pois também precisamos de um .h para guardar os prototipos.
A ligaçao entre ambos é feita através de: #include "funcoes.h"

*/


//Recebe um int (importancia), que é introduzido pelo utilizador e tranforma este valor numa palavra
char* ConvertImportanciaParaPalavra( int imp ){
  switch( imp ){
    case 1 : return "Alta";
    case 2 : return "Media";
    case 3 : return "Baixa";
  }
  // Como a importancia esta definido entre 1 e 3, a função nunca vai retornar "valor"
  return "-----";
}
//Converte um int relativo ao estado da tarefa e transforma em uma palavra
char* ConvertEstadoEmPalavra( int estado ){
  switch( estado ){
    case 0 : return "Por Fazer";
    case 1 : return "Concluida";
  }
  // Como o estado esta definido entre 0 e 1, a função nunca vai retornar "estado"
  return "estado";
}

//Obtem a data do dia 
struct tm DataHoje(){
  time_t t = time(NULL);
  struct tm hoje = *localtime(&t);
  hoje.tm_mon = hoje.tm_mon + 1;
  hoje.tm_year = hoje.tm_year + 1900;
  return hoje;
}

//compara a data do dia com a data da tarefa e verifica se esta ou nao atrasada
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


//Tabelas

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

