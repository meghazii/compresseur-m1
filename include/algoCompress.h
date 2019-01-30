#ifndef ALGO_COMPRESS_H
#define ALGO_COMPRESS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100 

struct Noeud* creerNoeud(char c, unsigned freq);

struct Arbre* creerArbre(unsigned capacite);

void echangerNoeud(struct Noeud** a, struct Noeud** b);

void minHeapify(struct Arbre* Arbre, int index);

int isSizeOne (struct Arbre* Arbre);

struct Noeud* noeudMin (struct Arbre* Arbre);

void insererNoeud (struct Arbre* Arbre, struct Noeud* Noeud);

void construireArbre (struct Arbre* Arbre);

void afficherCode (int arr[], int n); 

int estFeuille (struct Noeud* root); 

struct Noeud* creerArbreHuffman (char c[], int freq[], int size) ; 

struct Arbre* remplirArbre (char c[], int freq[], int size); 

void creerCodes(struct Noeud* a, int arr[], int top); 

void codageHuffman (char c[], int freq[], int size); 

// Noeud Arbre Huffman
struct Noeud { 
  char c;  // caractère
  unsigned freq;  // fréquence
  struct Noeud *left, *right; // fils gauche et fils droit 
} Noeud; 
  
//Arbre de huffman
struct Arbre { 
  unsigned size; 
  unsigned capacite; 
  struct Noeud** array;  // tableau de pointeur de noeuds 
}; 

#endif
