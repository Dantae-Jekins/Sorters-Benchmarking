// potênciação
int int_podniesc(int num1, int base)
{
    int aux = num1;
    if ((base == 0) || (num1 == 1))
        return 1;

    else if (base == 1)
        return num1;

    while(base > 1)
    {
        aux *= num1;
        base--;
    }

    return aux;
}

int int_log(int base, int num)
{
  int i;
  for (i = 1; num > base; i++)
    num /= base;

  return i;
}

// diferença entre 2 pontos
int int_module(int i, int j)
{
  if (j > i)
  {
    j -= i;
    return j;
  }

  i -= j;
  return i;
}