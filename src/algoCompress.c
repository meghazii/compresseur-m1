#include "../include/algoCompress.h"

  
/**
 * Associe à un caractère sa fréquence dans la structure Noeud 
 */
Noeud*
creerNoeud (symbole c, unsigned freq) 
{ 
  Noeud* tmp = ( Noeud*) malloc (sizeof( Noeud)); 
  
  tmp->left = tmp->right = NULL; 
  tmp->c = c; 
  tmp->freq = freq; 
  
  return tmp; 
} 
  
/**
 * initialise un arbre d'une capacité donnée
 */
Arbre*
creerArbre(unsigned capacite)  
{ 
  Arbre* arbre = ( Arbre*)malloc(sizeof( Arbre)); 
  
  arbre->size = 0; 
  arbre->capacite = capacite; 
  arbre->array = ( Noeud**)malloc(arbre-> capacite * sizeof( Noeud*)); 
  return arbre; 
} 
  
/**
 * Echange 2 noeuds (caractère, fréquence et fils gauche et droit)
 */
void
echangerNoeud( Noeud** a,  Noeud** b) 
{ 
  Noeud* t = *a; 
  *a = *b; 
  *b = t; 
} 
  
//minHeapify standard
void
minHeapify( Arbre* Arbre, int index) 
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
isSizeOne ( Arbre* Arbre) 
{ 
  return (Arbre->size == 1); 
} 
  
/**
 *  trouve et extrait le noeud de fréquence min
 */
Noeud*
noeudMin ( Arbre* Arbre) 
{ 
  
  Noeud* tmp = Arbre->array[0]; 
  Arbre->array[0] = Arbre->array[Arbre->size - 1]; 
  
  --Arbre->size; 
  minHeapify(Arbre, 0); 
  
  return tmp; 
} 
  
/**
 * Insère Noeud dans Arbre
 */
void
insererNoeud ( Arbre* Arbre,  Noeud* Noeud)   
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
construireArbre ( Arbre* Arbre) 
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
estFeuille ( Noeud* root) 
{ 
  return ! (root->left) && ! (root->right); 
} 
  
/**
 * Creer un arbre de capacité égale à size et insère tous les caractère de c[]
 */ 
Arbre*
remplirArbre (symbole c[], int freq[], int size) 
{ 
  Arbre* a = creerArbre(size); 
  
  for (int i = 0; i < size; ++i) 
    a->array[i] = creerNoeud(c[i], freq[i]); 
  
  a->size = size; 
  construireArbre(a); 

  return a; 
} 

/**
 * 
 */
Noeud*
creerArbreHuffman (symbole c[], int freq[], int size) 
{ 
  Noeud *left, *right, *n; 
  Arbre* Arbre = remplirArbre(c, freq, size); 
  symbole tmp; tmp.sym = (char*) malloc (sizeof(char)); tmp.n = 1;
  
  while (!isSizeOne(Arbre)) {  
    //on trouve les 2 Noeuds de fréquence min
    left = noeudMin(Arbre); 
    right = noeudMin(Arbre); 
  
    // Création d'un nouveau noeud n étiquetté "$" de fréquence égale à la somme des fréquences des 2 noeuds min (qui deviennent les noeuds fils)
    n = creerNoeud(tmp, left->freq + right->freq); 
    n->left = left; 
    n->right = right; 
  
    insererNoeud(Arbre, n); //on l'insère dans l'arbre 
  } 
  
  // On retourne le dernier noeud restant , qui est la racine de l'arbre complet
  return noeudMin(Arbre); 
} 
  
// Affichage des codes de huffman optenus et stockage dans arr[]
void
creerCodes( Noeud* a, int arr[], int top) 
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
    for (size_t i = 0; i < a->c.n; i++){
      printf("%c", a->c.sym[i]);
    }
    printf (": ");
    afficherCode(arr, top); 
  } 
} 
  

void
codageHuffman (symbole c[], int freq[], int size) 
{ 
  // Construction arbre de huffman
  Noeud* a = creerArbreHuffman(c, freq, size); 
  
  // Affochages de codes obtenu grace à l'arbre
  int arr[MAX_TREE_HT], top = 0; 
  creerCodes(a, arr, top); 
} 
/*
int
main() 
{
  symbole s1, s2, s3;
  s1.sym = (char*) malloc (sizeof(char));
  s1.sym = "011";
  s1.n = 3;
  s2.sym = (char*) malloc (sizeof(char));
  s2.sym = "01";
  s2.n = 2;
  s3.sym = (char*) malloc (sizeof(char));
  s3.sym = "011010";
  s3.n = 6;
  
  symbole arr[3];
  arr[0] = s1; arr[1] = s2; arr[2] = s3;
  int freq[] = { 2, 22, 21 }; 
  
  int size = sizeof(arr) / sizeof(arr[0]); 
  
  codageHuffman(arr, freq, size); 
  
  return 0; 
} 
*/
