#include "../include/fileReader.h"

long
size_file (FILE* fd)
{
  long tmp = 0;
  if (fseek (fd, 0, SEEK_END) == -1)
    {
      perror ("Error ");
      exit (EXIT_FAILURE);
    }
  tmp = ftell (fd);
  if (fseek (fd, 0, SEEK_SET) == -1)
    {
      perror ("Error ");
      exit (EXIT_FAILURE);
    }
  return tmp;
}

char*
read_file (char* filepath)
{
  printf ("Lecture du fichier : %s\n", filepath);
  int charLus = 0;
  char* buf = NULL;
  FILE* fd = NULL;
  long size = 0;
  
  fd = open_file (filepath);
  if (fd == NULL)
    exit(EXIT_FAILURE);

  
  size = size_file (fd);
  buf = (char*) malloc (size * sizeof (char));
 
  charLus = read_n_bytes (fd, size, buf);
  printf ("%d caractere lus\n", charLus);
  
  printf ("--%s--\n", buf);

  fclose (fd);
  return buf;
}

FILE*
open_file (char* filepath)
{
  FILE* fd = fopen (filepath, "r");
  if (fd == NULL)
    {
      perror ("Erreur ");
      return NULL;
    }

  return fd;
}

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
