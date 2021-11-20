void fill_array(int *vetor, int tam, int max, int min)
{
  int intervalo = max - min + 1;
  for (size_t i = 0; i < tam; i++)
    vetor[i] = (rand()%intervalo) + min;
  
}

int best_mult(int num, int min, int max)
{
  // extrai o melhor número para as operações abaixo
  // (ou elas podem entrar em conflito, feio)
  int j = min;
  for(int i = min; i < max ; i+=4)
  {
    if( num % i == 0)
      j = i;
  }

  return j;
}

void print_simplified(int *vetor, int tam)
{
  // simplifica o vetor em apenas 8, 16 ou 32
  // espaços (tirando a média, moda ou mediana
  // entre eles), isto para ser possível printar.
  int size;
  if (tam < 16)
    size = tam;

  else if (tam <= 32)
    size = best_mult(tam, 4, 8);

  else if (tam <= 128)
   size = best_mult(tam, 4, 16);

  else if (tam <= 256) 
    size = best_mult(tam, 8, 32);

  else if (tam <= 512) 
    size = best_mult(tam, 8, 64);
 
  else 
    size = best_mult(tam, 8, 128);

  int count = 1;
  int jump = tam/size;
  float *aux = (float*) malloc(sizeof(float)*(size));
  aux[0] = 0;
  for(int i = 0, j = 0;; i++, count++)
  {
    if(i == tam)
    {
      //break
      aux[j] /= count;
      break;
    }
    else 
    {

      aux[j] += vetor[i];
      if(i % jump == jump - 1)
      {
      	// fim de uma contagem
        // tira a divisão
        aux[j] /= count;
        
        // avança para o próximo bloco
        j++;
        aux[j] = 0;
        count  = 0;
      }

      // incrementa a contagem
    }
  }

  printf("\n %d dígitos simplificados em %d", tam, size);
  for(int i = 0; i < size; i++)
  {
    if(i%4 == 0)
      printf("\n\033[31m %.3d-%.3d: \033[0m", i,i+4);
    printf("%.2f ", aux[i]);
  }

  free(aux);
}
