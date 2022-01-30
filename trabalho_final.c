#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trabalho_final.h"
#include "trabalho_final_variaveis.h"


int main(){

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
