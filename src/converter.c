#include "../include/converter.h"

int
bitset_to_int (bitset* bt)
{
  int tmp = 0;

  for (size_t i = 0; i < bt->n; i++)
    tmp += (pow (2, bt->n - (i+1)) * bt->bits[i]);
  
  return tmp;
}

bitset*
bytes_to_bitset (char bytes)
{
  bitset* bt = (bitset*) malloc (sizeof (bitset));
  bt->bits = (char*) malloc (8 * sizeof (char));

  if (bt == NULL || bt->bits == NULL)
    {
      fprintf (stderr, "Erreur : Echec lors de l'allocation de mémoire.\n");   
      exit (EXIT_FAILURE);
    }
  bt->n = 8;
  
  for (int i = 7; i >= 0; i--)
    {
      bt->bits[7 - i] = READ_BIT(bytes, i);
    }
  
  return bt;
}

char
bitset_to_bytes (bitset* bt)
{
  int tmp = 0;
  char buf = 0;
  
  if (bt->n == 8)
    {
      tmp = bitset_to_int (bt);
      printf ("%d\n", tmp);
      buf = (char) tmp;
    }
  else
    {
      fprintf (stderr, "Erreur : Impossible d'effectuer la conversion bitset to char\n");
      exit (EXIT_FAILURE);
    }
  
  return buf;
}

/*
int
main ()
{
  bitset* slt = bytes_to_bitset('a');
  char test;
  
  for (int i = 0; i < 8; i++)
    printf ("%d", slt->bits[i]);
  printf("\n");

  test = bitset_to_bytes (slt);
  printf ("%c\n", test);
  
  free (slt->bits);
  free (slt);
  exit (EXIT_SUCCESS);
}

*/
