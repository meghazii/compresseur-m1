#ifndef FILE_READER_H
#define FILE_READER_H

#include "./converter.h"
#include "./algoCompress.h"

/**
 * Renvoie la taille de fichier pointé par le descripteur passé en paramètre
 */
long size_file (FILE*);


/**
 * Lit le fichier filepath et le stocke dans le tableau buf
 * Renvoie un ptr vers ce tableau
 */
char* read_file (char*);


/**
 * Ouvre le fichier filepath 
 * Renvoie le descripteur de fichier vers filepath 
 * NULL si erreur
 */
FILE* open_file (char*);


/**
 * Lit n bytes du descripteur de fichier fd et les stockes dans le tableau buf
 * Renvoie le nombre de bytes lus
 */
int read_n_bytes (FILE*, int, char*);

#endif
