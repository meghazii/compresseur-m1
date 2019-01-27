#ifndef ALGO_COMPRESS_H
#define ALGO_COMPRESS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100 

struct MinHeapNode* newNode(char data, unsigned freq);

struct MinHeap* createMinHeap(unsigned capacity);

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);

void minHeapify(struct MinHeap* minHeap, int idx);

int isSizeOne (struct MinHeap* minHeap);

struct MinHeapNode* extractMin (struct MinHeap* minHeap);

void insertMinHeap (struct MinHeap* minHeap, struct MinHeapNode* minHeapNode);

void buildMinHeap (struct MinHeap* minHeap);

void printArr (int arr[], int n); 

int isLeaf (struct MinHeapNode* root); 

struct MinHeapNode* buildHuffmanTree (char data[], int freq[], int size) ; 

struct MinHeap* createAndBuildMinHeap (char data[], int freq[], int size); 

void printCodes(struct MinHeapNode* root, int arr[], int top); 

void HuffmanCodes (char data[], int freq[], int size); 

// A Huffman tree node 
struct MinHeapNode { 
  char data;  // One of the input character s
  unsigned freq;  // Frequency of the character
  struct MinHeapNode *left, *right; // Left and right child of this node
  
} MinHeapNode; 
  
// A Min Heap:  Collection of 
// min heap (or Hufmman tree) nodes 
struct MinHeap { 
  
  unsigned size; // Current size of min heap 
  unsigned capacity;  // capacity of min heap 
  struct MinHeapNode** array;  // Attay of minheap node pointers 
}; 

#endif
