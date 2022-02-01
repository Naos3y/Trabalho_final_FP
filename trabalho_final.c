//Trabalho realizado por: Bruno Luís Afonso Lopes
//Unidade Curricular: Fundamentos de Programação 2021/2022
//trabalho_final.c : Ficheiro onde se encontra o código principal, ou seja, onde se encontra a funçao main.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "funcoes.h"

#define NUM_TAREFAS 100
#define PALAVRAS 50

// Variaveis globais
int dias[NUM_TAREFAS];
int import[NUM_TAREFAS];
int meses[NUM_TAREFAS];
int anos[NUM_TAREFAS];
//Toda tarefa deve ser criada com o estado de não concluída
//Desta forma é possível colocar 0 (por fazer) em todos os elementos do vetor
int estados[NUM_TAREFAS] = {0};

char nomes[NUM_TAREFAS][PALAVRAS];
int task_index = 0;

// Prototipos
void SalvarParaFicheiro();

int main()
{

  int imptc;
  int lista;
  int i = 1;

  int importancia;
  int dia;
  int mes;
  int ano;

  ////////////////////// (DEVELOP CODE) - REMOVER ANTES DE ENTREGAR ////////////
  /*
  import[task_index]  = 1;
  dias[task_index]    = 12;
  meses[task_index]   = 12 ;
  anos[task_index]    = 2021 ;
  strcpy(nomes[task_index], "TAREFAS 1");

  task_index++;

  import[task_index]  = 2;
  dias[task_index]    = 23;
  meses[task_index]   = 11 ;
  anos[task_index]    = 2022 ;
  strcpy(nomes[task_index], "TAREFAS 2");

  task_index++;

  import[task_index]  = 1;
  dias[task_index]    = 21;
  meses[task_index]   = 12 ;
  anos[task_index]    = 2023 ;
  strcpy(nomes[task_index], "TAREFAS 3");

  task_index++;

  import[task_index]  = 1;
  dias[task_index]    = 21;
  meses[task_index]   = 12 ;
  anos[task_index]    = 2021 ;
  strcpy(nomes[task_index], "TAREFAS 4");
  estados[task_index] = 1;

  task_index++;
  */
  ///////////////// (DEVELOP CODE) - REMOVER ANTES DE ENTREGAR - FIM ///////////
  while (i == 1)
  {

    TabelaUm();
    scanf("%d", &lista);
    // para limpar o buffer para nao passar uma linha a frente, ou seja, aceita uma nova string
    // sem fflush(stdin), o programa nao consegue ler uma nova tarefa introduzida pelo utilizador pois
    // ao selecionar a opçao 1 e clicar ENTER, a linha gerada por este ENTER vai ser lida pelo fgets
    // ou seja, o nome vai ser nulo, e entao irá ser apresentada uma mensagem de "tarefa invalida"
    fflush(stdin);
    // limpar o menu, funciona apenas em windows, apenas para aspeto visual.

    switch (lista)
    {

    case 1:
      TabelaDois();
      printf("\nNome:");
      fgets(nomes[task_index], PALAVRAS, stdin);

      if (nomes[task_index][0] == '\0' || nomes[task_index][0] == '\n')
      {
        printf("Tarefa Invalida\n");
      }
      else
      {
        printf("\nImportancia:");
        scanf("%d", &importancia);
        if (importancia > 3 || importancia < 0)
        {
          printf("Importancia Invalida\n");
        }
        else
        {
          printf("\nData:");
          scanf("%d-%d-%d", &dia, &mes, &ano);
          if (dia < 0 || dia > 31 || mes < 0 || mes > 12)
          {
            printf("Data Invalida\n");
          }
        }
      }

      while (getchar() != '\n'); //para nao correr os varios scanf e nao repetir 3 vezes por causa da data

      dias[task_index] = dia;
      import[task_index] = importancia;
      meses[task_index] = mes;
      anos[task_index] = ano;

      task_index++;

      break;

    case 2:
      printf("Introduza o identificador da tarefa que quer dar como concluida");
      int identificador;
      for (int j = 0; j < task_index; j++)
      {
        if (estados[j] == 0)
        {
          printf("\n\nTarefa %d: ", (j + 1));
          printf("%s", nomes[j]);
        }
      }
      scanf("%d", &identificador);
      if (identificador > 0 && identificador <= task_index)
      {
        estados[identificador - 1] = 1;
      }
      break;

    case 3:
      printf("-------------------------------- Consulta geral -------------------------------------");
      printf("\n\n");
      printf("--- Identif ---     Data     ---   Importancia   ---   Estado   ---   Descricao   ---\n");
      for (int j = 0; j < task_index; j++)
      {
        printf("       %d         %d-%d-%d            %s           %s       %s",
               (j + 1), dias[j], meses[j], anos[j], ConvertImportanciaParaPalavra(import[j]),
               ConvertEstadoEmPalavra(estados[j]), nomes[j]);
      }

      break;

    case 4:
      TabelaTres();
      scanf("%d", &imptc);
      if (imptc > 3 || imptc < 0)
      {
        printf("Importancia Invalida\n");
      }
      else
      {
        printf("--- Identif ---     Data     ---   Importancia   ---   Estado   ---   Descricao   ---");
        for (int j = 0; j < task_index; j++)
        {
          if (estados[j] == 0)
          {
            if (import[j] == imptc)
            {
              printf("\n       %d         %d-%d-%d            %s           %s       %s",
                     (j + 1), dias[j], meses[j], anos[j], ConvertImportanciaParaPalavra(import[j]),
                     ConvertEstadoEmPalavra(estados[j]), nomes[j]);
            }
          }
        }
      }
      break;

    case 5:
      for (int j = 0; j < task_index; j++)
      {
        if (VerificarSeTarefaEstaAtrasada(dias[j], meses[j], anos[j]) == 0)
        {
          if (estados[j] == 0)
          {
            printf("\nIdentificador: %d | ", (j + 1));
            printf("Nome Tarefa Atrasada: %s", nomes[j]);
          }
        }
      }
      break;

    case 6:
      printf("\nResumo das Tarefas");

      int contaImpAltaFazer = 0;
      int contaImpMediaFazer = 0;
      int contaImpBaixaFazer = 0;
      int contaImpAltaConc = 0;
      int contaImpMediaConc = 0;
      int contaImpBaixaConc = 0;
      int altaAtrasada = 0;
      int mediaAtrasada = 0;
      int baixaAtrasada = 0;

      for (int j = 0; j < task_index; j++)
      {
        if (import[j] == 1)
        {
          if (estados[j] == 0)
          {
            contaImpAltaFazer = contaImpAltaFazer + 1;
            if (VerificarSeTarefaEstaAtrasada(dias[j], meses[j], anos[j]) == 0)
            {
              altaAtrasada = altaAtrasada + 1;
            }
          }
          else
          {
            contaImpAltaConc = contaImpAltaConc + 1;
          }
        }
        else if (import[j] == 2)
        {
          if (estados[j] == 0)
          {
            contaImpMediaFazer = contaImpMediaFazer + 1;
            if (VerificarSeTarefaEstaAtrasada(dias[j], meses[j], anos[j]) == 0)
            {
              mediaAtrasada = mediaAtrasada + 1;
            }
          }
          else
          {
            contaImpMediaConc = contaImpMediaConc + 1;
          }
        }
        else if (import[j] == 3)
        {
          if (estados[j] == 0)
          {
            contaImpBaixaFazer = contaImpBaixaFazer + 1;
            if (VerificarSeTarefaEstaAtrasada(dias[j], meses[j], anos[j]) == 0)
            {
              baixaAtrasada = baixaAtrasada + 1;
            }
          }
          else
          {
            contaImpBaixaConc = contaImpBaixaConc + 1;
          }
        }
      }
      printf("\n-- Importancia --- PorFazer --- Atrasadas --- Concluidas --");
      printf("\n--   Alta      ---    %d     ---    %d     ---      %d     --", contaImpAltaFazer, altaAtrasada, contaImpAltaConc);
      printf("\n--   Media     ---    %d     ---    %d     ---      %d     --", contaImpMediaFazer, mediaAtrasada, contaImpMediaConc);
      printf("\n--   Baixa     ---    %d     ---    %d     ---      %d     --", contaImpBaixaFazer, baixaAtrasada, contaImpBaixaConc);
      printf("\n\n");
      break;

    case 7:;
      SalvarParaFicheiro();
      break;

    case 8:
      printf("Clique ENTER para fechar");
      i = 0;
      break;

    default:
      if (lista > 7)
      {
        printf("Invalido, por favor escolha um numero de 1 a 7\n\n\n");
      }
      break;
    }
  }
  return 0;
}

// Funcoes
void SalvarParaFicheiro()
{
  FILE *DadosGuardados;

  // use appropriate location if you are using MacOS or Linux
  DadosGuardados = fopen(".\\DadosGuardados.txt", "a+");

  if (DadosGuardados == NULL)
  {
    printf("Nao foi possível abrir o ficheiro");
  }
  else
  {

    fprintf(DadosGuardados, "--- Identif ---     Data     ---   Importancia   ---   Estado   ---   Descricao   ---");
    for (int j = 0; j < task_index; j++)
    {
      fprintf(DadosGuardados, "\n       %d         %d-%d-%d            %s           %s       %s",
              (j + 1), dias[j], meses[j], anos[j], ConvertImportanciaParaPalavra(import[j]),
              ConvertEstadoEmPalavra(estados[j]), nomes[j]);
    }

    fclose(DadosGuardados);
    printf("Dados Guardados com Sucesso!");
  }
}
