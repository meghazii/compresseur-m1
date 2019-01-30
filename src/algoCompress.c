#include "../include/algoCompress.h"

  
/**
* Associe à un caractère sa fréquence dans la structure Noeud 
*/
struct Noeud*
creerNoeud(char c, unsigned freq) 
{ 
  struct Noeud* tmp = (struct Noeud*) malloc (sizeof(struct Noeud)); 
  
  tmp->left = tmp->right = NULL; 
  tmp->c = c; 
  tmp->freq = freq; 
  
  return tmp; 
} 
  
/**
* initialise un arbre d'une capacité donnée
*/
struct Arbre*
creerArbre(unsigned capacite)  
{ 
  struct Arbre* Arbre = (struct Arbre*)malloc(sizeof(struct Arbre)); 
  
  Arbre->size = 0; 
  Arbre->capacite = capacite; 
  Arbre->array = (struct Noeud**)malloc(Arbre-> capacite * sizeof(struct Noeud*)); 
  return Arbre; 
} 
  
/**
* Echange 2 noeuds (caractère, fréquence et fils gauche et droit)
*/
void
echangerNoeud(struct Noeud** a, struct Noeud** b) 
{ 
  struct Noeud* t = *a; 
  *a = *b; 
  *b = t; 
} 
  
//minHeapify standard
void
minHeapify(struct Arbre* Arbre, int index) 
{ 
  int min = index; 
  int left = 2 * index + 1; 
  int right = 2 * index + 2; 
  
  if (left < (int) Arbre->size && Arbre->array[left]-> freq < Arbre->array[min]->freq) 
    min = left; 
  
  if (right < (int) Arbre->size && Arbre->array[right]->freq < Arbre->array[min]->freq) 
    min = right; 
  
  if (min != index){ 
      echangerNoeud(&Arbre->array[min], &Arbre->array[index]); 
      minHeapify(Arbre, min); 
    } 
} 
  
/**
* return true si l'arbre est de taille 1
*/
int
isSizeOne (struct Arbre* Arbre) 
{ 
  return (Arbre->size == 1); 
} 
  
/**
*  trouve et extrait le noeud de fréquence min
*/
struct Noeud*
noeudMin (struct Arbre* Arbre) 
{ 
  
  struct Noeud* tmp = Arbre->array[0]; 
  Arbre->array[0] = Arbre->array[Arbre->size - 1]; 
  
  --Arbre->size; 
  minHeapify(Arbre, 0); 
  
  return tmp; 
} 
  
/**
* Insère Noeud dans Arbre
*/
void
insererNoeud (struct Arbre* Arbre, struct Noeud* Noeud)   
{ 
  ++Arbre->size; 
  int i = Arbre->size - 1; 
  
  while (i && Noeud->freq < Arbre->array[(i - 1) / 2]->freq)
    { 
      Arbre->array[i] = Arbre->array[(i - 1) / 2]; 
      i = (i - 1) / 2; 
    } 
  
  Arbre->array[i] = Noeud; 
} 
  
/**
* Création de l'arbre
*/
void
construireArbre (struct Arbre* Arbre) 
{ 
  int n = Arbre->size - 1; 
  int i; 
  
  for (i = (n - 1) / 2; i >= 0; --i) 
    minHeapify(Arbre, i); 
} 
  

void
afficherCode (int arr[], int n) 
{ 
  int i; 
  for (i = 0; i < n; ++i) 
    printf("%d", arr[i]); 
  
  printf("\n"); 
} 
  
/**
* return true si root est une feuille
*/ 
int
estFeuille (struct Noeud* root) 
{ 
  return ! (root->left) && ! (root->right); 
} 
  
/**
* Creer un arbre de capacité égale à size et insère tous les caractère de c[]
*/ 
struct Arbre*
remplirArbre (char c[], int freq[], int size) 
{ 
  struct Arbre* a = creerArbre(size); 
  
  for (int i = 0; i < size; ++i) 
    a->array[i] = creerNoeud(c[i], freq[i]); 
  
  a->size = size; 
  construireArbre(a); 
  
  return a; 
} 
  
/**
* 
*/
struct Noeud*
creerArbreHuffman (char c[], int freq[], int size) 
{ 
  struct Noeud *left, *right, *n; 
  struct Arbre* Arbre = remplirArbre(c, freq, size); 
  
  while (!isSizeOne(Arbre)) {  
//on trouve les 2 Noeuds de fréquence min
    left = noeudMin(Arbre); 
    right = noeudMin(Arbre); 
  
    // Création d'un nouveau noeud n étiquetté "$" de fréquence égale à la somme des fréquences des 2 noeuds min (qui deviennent les noeuds fils) 
    n = creerNoeud('$', left->freq + right->freq); 
    n->left = left; 
    n->right = right; 
  
    insererNoeud(Arbre, n); //on l'insère dans l'arbre 
  } 
  
  // On retourne le dernier noeud restant , qui est la racine de l'arbre complet
  return noeudMin(Arbre); 
} 
  
// Affichage des codes de huffman optenus et stockage dans arr[]
void
creerCodes(struct Noeud* a, int arr[], int top) 
{ 
  // On assigne la valeur 0 aux branche gauches 
  if (a->left) { 
    arr[top] = 0; 
    creerCodes(a->left, arr, top + 1); 
  } 
  
  // et 1 aux branches droites
  if (a->right) { 
    arr[top] = 1; 
    creerCodes(a->right, arr, top + 1); 
  } 
  
  // quand on est descendu jusqu'à une feuille on affiche le caractère, ainsi que le code de huffman correspondant
  if (estFeuille(a)) { 
    printf("%c: ", a->c); 
    afficherCode(arr, top); 
  } 
} 
  

void
codageHuffman (char c[], int freq[], int size) 
{ 
  // Construction arbre de huffman
  struct Noeud* a = creerArbreHuffman(c, freq, size); 
  
  // Affochages de codes obtenu grace à l'arbre
  int arr[MAX_TREE_HT], top = 0; 
  creerCodes(a, arr, top); 
} 
  

int
main() 
{ 
  char arr[] = { 'a', 'b', 'c'}; 
  int freq[] = { 5, 9, 12 }; 
  
  int size = sizeof(arr) / sizeof(arr[0]); 
  
  codageHuffman(arr, freq, size); 
  
  return 0; 
} 
