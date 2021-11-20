void swap(int *vec, int i, int j)
{
  int aux = vec[i];
  vec[i] = vec[j];
  vec[j] = aux;
}

void merge(int *v, int *aux, int siz, int ini)
{
  int mei = (siz+1)/2 + ini;
  int fim = siz       + ini;
  int dir = mei;
  int esq = ini;
  
  int i = ini;
  while ((esq < mei) && (dir < fim))
  {
    if (v[esq] < v[dir])
      aux[i++] = v[esq++];
    else
      aux[i++] = v[dir++];
  }
  while (dir < fim)
    aux[i++] = v[dir++];
  while (esq < mei)
    aux[i++] = v[esq++];

  for(i = ini; i < (siz+ini); i++)
    v[i] = aux[i];
}

void selection_sort(int *vetor, int size)
{
	int ordenado = 0;
  for (int i = 0; i < size-1; i++)
  { 
		for (int j = i + 1; j < size; j++ )    
			if (vetor[i] > vetor[j])
			{
				ordenado = 0;
				swap(vetor, i, j);
			}
	}
}

void bubble_sort(int *vetor, int size)
{
	int ordenado = 0;
  for (int i = 0; i < size-1; i++)
	{
    for(int j = 0; j < size-1-i; j++)
			if(vetor[j] > vetor[j+1])
    	{
				ordenado = 0;
        swap(vetor, j, j+1);
  	  }
	}
}

void merge_sort(int *vetor, int *aux, int siz, int ini)
{
  if (siz == 1)
    return;

  merge_sort(vetor, aux, (siz+1)/2, ini);
  merge_sort(vetor, aux, siz/2, ini+(siz+1)/2);
  merge(vetor, aux, siz, ini);
}