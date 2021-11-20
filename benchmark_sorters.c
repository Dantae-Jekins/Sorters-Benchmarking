#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "j_tools/j_math.h"
#include "j_tools/j_wektory.h"
#include "j_tools/j_statystyka.h"
#include "j_tools/j_sorters.h"

void print_time(clock_t start, clock_t end, char *ops)
{

  clock_t difference = end - start;
  double time =((double) difference / CLOCKS_PER_SEC);
  printf("\n\n Tempo de operação -%s:", ops);
  printf("\n %f \033[32m segundos \033[0m", time);
  printf("\n %f \033[32m milisegundos \033[0m\n", time*1000);
}

int main(int argc, char **argv)
{
  // valores default
  int min = 1; 
  int max = 9; 
  unsigned tam = 32;
  int *vetor; 

  bool print = false;
  bool merge = false;
  bool bubble = false;
  bool selection = false; 
  clock_t poczatek, koniec;
  
  // preparo do rand
  time_t timer;
  srand(time(&timer));
  
  // leitura de argumentos
  if (argc > 1)
  {
    int count = 1; // registra qual o argumento lê
    int type = 1;
    
    while(argc > count) // lê os argumentos
    {
      type = 0;
      int aux1, aux2;
      if (match_string(argv[count], "-r")) //-r range
        type = 1;
      else if (match_string(argv[count], "-a")) //-a amount
        type = 2;
      else if (match_string(argv[count], "-p"))
        type = 3;
      else if (match_string(argv[count], "-bs"))
        type = 4;
      else if (match_string(argv[count], "-ss"))
        type = 5;
      else if (match_string(argv[count], "-ms"))
        type = 6;
      else if (match_string(argv[count], "-h"))
        type = 7;
      switch (type)
      {
      case 0:
        printf("\n Argumento(s) inválido(s): %s", argv[count]);
        break;

      case 1:
        // lê os dois próximos argumentos
        if (count+3 > argc)
        {
          //sem argumentos o suficiente para -r
          printf("\n Argumento inválido: %s, sem valores suficientes");
          break;
        }
        aux1 = return_integer(argv[++count]);
        aux2 = return_integer(argv[++count]);

        // reorganiza os intervalo 
        if (aux1 < aux2)
        {
          min = aux1;
          max = aux2;
        }
        else
        {
          min = aux2;
          max = aux1;
        }
        break;
      
      case 2:
        if (count+2 > argc)
        {
          //sem argumentos o suficiente para -a
          printf("\n Argumento inválido: %s, sem valores suficientes");
          break;
        }
        tam = return_unsigned(argv[++count]);
        break;

      case 3:
        print = 1;
        break;
      
      case 4:
        bubble = 1;
        break;
      
      case 5:
        selection = 1;
        break;

      case 6:
        merge = 1;
        break;
      
      case 7:
        printf("\n Lista de comandos:");
        printf("\n\n \033[31m-r [x] [y] : range [intervalo]\033[0m");
        printf("\n ajusta o intervalo que corres-");
        printf("\n ponde aos números gerados.");
        printf("\n default: 1 - 9");

        printf("\n\n \033[31m-a [x]     : amount   [máximo]\033[0m");
        printf("\n ajusta o número máximo de val-");
        printf("\n lores ao vetor.");
        printf("\n default: 32");
       
        printf("\n\n \033[31m-p         : print\033[0m");
        printf("\n printa o valor ordenado como  ");
        printf("\n prova de ordenação.");

        printf("\n\n \033[31mSeleção de algoritmos \033[0m");
        printf("\n -ms Merge sort");
        printf("\n -bs Bubble sort");
        printf("\n -ss Selection sort"); 
        printf("\n default: todos");
        return 0;
      }
      count++;
    }
  }

  // msg inicial
  {
    printf("\n\n ANÁLISE DE TEMPO DE EXECUÇÕES");
    printf("\n DE ORDENADORES DE VETOR.");
    printf("\n Valores mínimos : %.3d", min);
    printf("\n Valores máximos : %.3d", max); 
    printf("\n\n Tamanho de vetor: %d\n", tam);
  }
  vetor = malloc(sizeof(int)*tam);
  // geração de valores aleatórios 
  {
    poczatek = clock();
    fill_array(vetor, tam, max, min);
    koniec = clock();
    printf("\n Gerado valores aleatórios.\n");
    print_time(poczatek, koniec, " Geração");
    print_simplified(vetor, tam);  
  }

  // se nenhum algoritmo foi selecionado, testa-se todos:
  if (!selection && !bubble && !merge)
  {
    selection = true;
    bubble    = true;
    merge     = true;
  }  
  if(print)
  {
    int sorters = selection + bubble + merge;
    if(sorters > 1)
    {
      printf("\n Por favor selecione apenas um");
      printf("\n algorítmo de ordenação para ");
      printf("\n printar, com -ms, -ss ou -bs");
      print = false;
    }
  }
  // SELECTION
  if (selection)
  {
    int *vetor_auxiliar; // para não perder o vetor original
    vetor_auxiliar = copy_array(vetor, tam);
    poczatek = clock();
    selection_sort(vetor_auxiliar, tam);
    koniec = clock();
    print_time(poczatek, koniec, " Selection_sort");
    if (print)
    {
      printf("\n Valores Ordenados:");
      print_simplified(vetor_auxiliar, tam);
    }
    free(vetor_auxiliar);  
  } printf("\n");

  if (bubble) 
  {
    int *vetor_auxiliar; // para não perder o vetor original
    vetor_auxiliar = copy_array(vetor, tam);
    poczatek = clock();
    bubble_sort(vetor_auxiliar, tam);
    koniec = clock();
    print_time(poczatek, koniec, " Bubble_sort");  
    if (print)
    {
      printf("\n Valores Ordenados:");
      print_simplified(vetor_auxiliar, tam);
    }
    free(vetor_auxiliar);  
  } printf("\n");

  if (merge) 
  {
    int *vetor_auxiliar; // para não perder o vetor original
    vetor_auxiliar = copy_array(vetor, tam);
    poczatek = clock();
    merge_sort(vetor, vetor_auxiliar, tam, 0);
    koniec = clock();
    print_time(poczatek, koniec, " Merge_sort");  
    if (print)
    {
      printf("\n Valores Ordenados:");
      print_simplified(vetor_auxiliar, tam);
    }
    free(vetor_auxiliar); 
  }

  free(vetor);
  return 0;
}
