#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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



int main(){
  #define NUM_TAREFAS 100
  #define PALAVRAS 50

  int dias[NUM_TAREFAS];
  int import[NUM_TAREFAS];
  int meses[NUM_TAREFAS];
  int anos[NUM_TAREFAS];

   //Toda tarefa deve ser criada com o estado de não concluída
   //Desta forma é possível colocar 0 (por fazer) em todos os elementos do vetor
  int estados[NUM_TAREFAS] = {0};

  char nomes[NUM_TAREFAS][PALAVRAS];
  int task_index = 0;

  int imptc;
  int lista;
  int i = 1;

  int importancia;
  int dia;
  int mes;
  int ano;

  int contaImpAltaFazer = 0;
  int contaImpMediaFazer = 0;
  int contaImpBaixaFazer = 0;
  int contaImpAltaConc = 0;
  int contaImpMediaConc = 0;
  int contaImpBaixaConc = 0;

  ////////////////////// (DEVELOP CODE) - REMOVER ANTES DE ENTREGAR ////////////
  import[task_index]  = 1;
  dias[task_index]    = 12;
  meses[task_index]   = 12 ;
  anos[task_index]    = 2021 ;
  strcpy(nomes[task_index], "TAREFAS 1");

  task_index++;

  import[task_index]  = 2;
  dias[task_index]    = 23;
  meses[task_index]   = 11 ;
  anos[task_index]    = 2021 ;
  strcpy(nomes[task_index], "TAREFAS 2");

  task_index++;

  import[task_index]  = 1;
  dias[task_index]    = 21;
  meses[task_index]   = 12 ;
  anos[task_index]    = 2021 ;
  strcpy(nomes[task_index], "TAREFAS 3");

  task_index++;

  import[task_index]  = 1;
  dias[task_index]    = 21;
  meses[task_index]   = 12 ;
  anos[task_index]    = 2021 ;
  strcpy(nomes[task_index], "TAREFAS 4");
  estados[task_index] = 1;

  task_index++;
  ///////////////// (DEVELOP CODE) - REMOVER ANTES DE ENTREGAR - FIM ///////////
  while(i == 1){

    TabelaUm();
    scanf("%d", &lista);
    fflush(stdin); // para limpar o buffer para nao passar uma linha a frente
    system("cls"); // limpar o menu, funciona apenas em windows

    switch (lista){

      case 1:
        TabelaDois();
        printf("\nNome:");
        fgets(nomes[task_index], PALAVRAS, stdin);

        if (nomes[task_index][0] == '\0' || nomes[task_index][0] == '\n') {
          printf("Tarefa Invalida\n");
        }
        else {
          printf("\nImportancia:");
          scanf("%d", &importancia);
          if(importancia > 3 || importancia < 0){
            printf("Importancia Invalida\n");
          } else{
            printf("\nData:");
            scanf("%d-%d-%d", &dia, &mes, &ano);
            if(dia < 0 || dia > 31 || mes < 0 || mes > 12){
              printf("Data Invalida\n");
            }
          }

          while (getchar() != '\n'); //para nao correr os varios scanf e nao repetir 3 vezes por causa da data

          dias[task_index] = dia;
          import[task_index] = importancia;
          meses[task_index] = mes;
          anos[task_index] = ano;

          task_index++;

          system("cls");
        }
        break;

      case 2:
        printf("Introduza o identificador da tarefa que quer dar como concluida");
        int identificador;
        for( int j = 0 ; j < task_index; j++ ){
          printf("\n\nTarefa %d: ", (j+1));
          printf("%s",nomes[j]);
        }
        scanf("%d", &identificador);
        if(identificador > 0 && identificador <= task_index){
          estados[identificador - 1] = 1;
        }
        break;

      case 3:
        printf("-------------------------------- Consulta geral -------------------------------------");
        printf("\n\n");
        printf("--- Identif ---     Data     ---   Importancia   ---   Estado   ---   Descricao   ---");
        for( int j = 0 ; j < task_index; j++ ){
          printf("\n       %d         %d-%d-%d            %s           %s       %s",
          (j+1),dias[j], meses[j], anos[j],ConvertImportanciaParaPalavra(import[j]),
          ConvertEstadoEmPalavra(estados[j]),nomes[j] );
        }

        break;

      case 4:
        TabelaTres();
        scanf("%d", &imptc);
        if(imptc > 3 || imptc < 0){
          printf("Importancia Invalida\n");
        }else{
          printf("--- Identif ---     Data     ---   Importancia   ---   Estado   ---   Descricao   ---");
          for( int j = 0 ; j < task_index; j++ ){
            if(estados[j] == 0){
              if(import[j] == imptc){
                printf("\n       %d         %d-%d-%d            %s           %s       %s",
                (j+1),dias[j], meses[j], anos[j],ConvertImportanciaParaPalavra(import[j]),
                ConvertEstadoEmPalavra(estados[j]),nomes[j]);
              }
            }
          }
        }
        break;

      case 5:
        printf("\nResumo das Tarefas");

        for( int j = 0 ; j < task_index; j++ ){
          if(import[j] == 1){
            if(estados[j] == 0){
              contaImpAltaFazer = contaImpAltaFazer + 1;
            }else{
              contaImpAltaConc = contaImpAltaConc + 1;
            }
          }else if(import[j] == 2){
            if(estados[j] == 0){
              contaImpMediaFazer = contaImpMediaFazer + 1;
            }else{
              contaImpMediaConc = contaImpMediaConc + 1;
            }
          }else if (import[j] == 3) {
            if(estados[j] == 0){
              contaImpBaixaFazer = contaImpBaixaFazer + 1;
            }else{
              contaImpBaixaConc = contaImpBaixaConc + 1;
            }
          }
        }
        printf("\n-- Importancia --- PorFazer --- Atrasadas --- Concluidas --");
        printf("\n--   Alta      ---    %d     ---           ---     %d      --",contaImpAltaFazer, contaImpAltaConc);
        printf("\n--   Media     ---    %d     ---           ---     %d      --",contaImpMediaFazer,contaImpMediaConc);
        printf("\n--   Baixa     ---    %d     ---           ---     %d      --",contaImpBaixaFazer,contaImpBaixaConc);
        printf("\n\n");
        break;

      case 6: ;
         FILE *DadosGuardados;

         // use appropriate location if you are using MacOS or Linux
         DadosGuardados = fopen("DadosGuardados","a+");

         if(DadosGuardados == NULL)
         {
            printf("Nao foi possível abrir o ficheiro");
            exit(1);
         }else{
           for( int j = 0 ; j < task_index; j++ ){
             fprintf(DadosGuardados,"\n\nIdentificador: %d | Data: %d-%d-%d | Importancia: %s | Estado: %s | Descricao: %s",
             (j+1),dias[j], meses[j], anos[j],ConvertImportanciaParaPalavra(import[j]),
             ConvertEstadoEmPalavra(estados[j]),nomes[j] );
           }
           fclose(DadosGuardados);
           printf("Dados Guardados com Sucesso!");
         }
        break;

      case 7: printf("Clique ENTER para fechar");
        i = 0;
        break;

      default:
        if (lista > 7){
          printf("Invalido, por favor escolha um numero de 1 a 7\n\n\n");
        }
        break;
    }
  }
 return 0;
}
