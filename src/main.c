#include "../include/main.h"

int
main (int argc, char* argv[])
{
  if (argc != 2)
    {
      fprintf (stderr, "Erreur : Nombre d'arguments invalide\n");
      exit (EXIT_FAILURE);
    }

  int fileType = 1;  
  
  if (fileType == 1) // fichier texte
    {
      textFile (argv[1]);
    }
  else if (fileType == 2) //fichier image
    {
      imageFile ();
    }

}

void
textFile (char* filepath)
{
  char* file = NULL;

  file = read_file (filepath);

  printf ("%s\n", file);

  if (file != NULL)
    free (file);
}



void
imageFile ()
{
}
