#include "../include/fileReader.h"

/*
int
main ()
{
  read("./test/test1", 60);
}*/

/**
 * Lit n bytes dans le fichier filepath et les stockes dans le tableau buf
 * Renvoie un ptr vers ce tableau
 */
char*
read (char* filepath, int n)
{
  printf ("Lecture du fichier : %s\n", filepath);
  int charLus = 0;
  char* buf = NULL;
  FILE* fd = NULL;
  
  fd = open_file (filepath, fd);
  if (fd == NULL)
    exit(EXIT_FAILURE);

  buf = (char*) malloc (n * sizeof (char));
 
  charLus = read_n_bytes (fd, n, buf);
  printf ("%d caractere lus\n", charLus);
  
  printf ("--%s--\n", buf);
  
  return buf;
  
}

/**
 * Ouvre le fichier filepath 
 * Renvoie le descripteur de fichier vers filepath 
 * NULL si erreur
 */
FILE*
open_file (char* filepath, FILE* fd)
{
  fd = fopen (filepath, "r");
  if (fd == NULL)
    {
      perror ("Erreur ");
      return NULL;
    }

  return fd;
}


/**
 * Lit n bytes du descripteur de fichier fd et les stockes dans le tableau buf
 * Renvoie le nombre de bytes lus
 */
int
read_n_bytes (FILE* fd, int n, char* buf)
{
  char c;
  int tmp = 0;
  
  while (tmp < n)
    {
      c = fgetc (fd);
      if (c == EOF)
	break;
      buf[tmp++] = c;
    }
  return tmp;
}
