// cópia de elementos
int *copy_array(int *vetor, int tam)
{
    int *aux = (int*)malloc(sizeof(int)*tam);
    for(int i = 0; i < tam; i++)
        aux[i] = vetor[i];
    return aux;
}

// move de uma str para outra do ponto vec1[i++] para vec[j++], cortando vec1
char *strcrop(unsigned int i, unsigned int j, char *vec1, char *vec2)
{ 
  int size = 4;
  vec2 = (char*)realloc(vec2, sizeof(char)*size);
  while(vec1[i]!=';')
  {
    vec2[j++] = vec1[i++];
    if( size == j)
    {
      size+=4; //alocamos + 4 de espaço a cada vez
      vec2 = (char*)realloc(vec2, sizeof(char)*size);
    } 
  } 
  //realoca o espaço certo
  vec2 = (char*)realloc(vec2, sizeof(char)*(j+1));
  vec2[j] = '\0'; // coloca ponto de parada
  return vec2;
}

// move uma quantidade prédeterminada de elementos para o vetor 1 do vetor 2.
void strmov(unsigned int i, char *vec1, char *vec2)
{
  int j = 0;
  while( j <= i )
  {
    vec1[j] = vec2[j];
    j++;
  } 
  
}

int match_string(char *palavra1, char *palavra2)
{
    int i = 0;
    do
    {
        if(palavra1[i] != palavra2[i])
            return 0; // retorna falso
        
    } while( (palavra1[i] != '\0') && (palavra2[i++] != '\0') );

    return 1;
}

unsigned return_unsigned(char *palavra1)
{
    int count = 0, size = 0;
    for(int i = 0; palavra1[i] != 0; i++)
        size += 1;

    for(int j = 1; size >= j; j++)
        count += (palavra1[size-j] - 48) * int_podniesc(10, j-1);

    return count;
}

int return_integer(char *palavra1)
{
    // retorna o valor em inteiros da palavra
    int count = 0, size = 0;

    int negativo = 0;
    if(palavra1[0] == '-')
        negativo = 1;
 
    for(int i = 0; palavra1[i] != 0; i++)
        size += 1;

    for(int j = 1; size >= j+negativo; j++)
        count += (palavra1[size-j] - 48) * int_podniesc(10, j-1);

    if(negativo)
        return -count;
    
    return count;
}