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
