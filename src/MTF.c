#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
#define TAILLE_MAX 10000

int position(char x, char* alphabet) { 
  for (size_t i = 0; i < strlen(alphabet); i++) { 
    if (alphabet[i] == x) { 
      return i; 
    } 
  } 
  return -1;
} 

  
void moveToFront(int index, char* alphabet) { 
  char* copie = (char*)malloc(sizeof(char) * 26); 
  strcpy(copie, alphabet); 
  strncpy(alphabet + 1, copie, index); 
  alphabet[0] = copie[index]; 
} 
  
void MTFEncodage(char text[], int taille, char* alphabet) { 
  int i; 
  int* tab = (int*)malloc(taille * sizeof(int)); 
  
  for (i=0; i<taille; i++) { 
    tab[i] = position(text[i], alphabet); 
    printf("%d ", tab[i]); 
    moveToFront(tab[i],alphabet); 
  } 
} 

void MTFDecodage(int motcode[], int taille) { 
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz"; 
  int i; 
  for (i=0; i<taille; i++) { 
    printf("%c", alphabet[motcode[i]]); 
    moveToFront(motcode[i], alphabet); 
  } 
} 
  
int main() { 
  char text[] = {'p', 'a', 'n', 'a', 'm', 'a'};
  //char* text = "panama"; 
  int taille = strlen(text); 
  char* alphabet = (char*)malloc(sizeof(char) * 26); 
  strcpy(alphabet, "abcdefghijklmnopqrstuvwxyz"); 
  
  printf("    Texte de départ : %s", text); 
  printf("\n    Move to Front Transformation : "); 
  MTFEncodage(text, taille, alphabet);

  // ------

  int motcode[] = {15, 1, 14, 1, 14, 1}; 
  int t = sizeof(motcode)/sizeof(motcode[0]); 
  printf("\n    Décodage : "); 
  MTFDecodage(motcode,t);
  printf("\n");

  return 0; 

} 
