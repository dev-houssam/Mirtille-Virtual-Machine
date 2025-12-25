/*
    Author : Houssam BACAR
    Project Name : Mirtille Virtual Machine
    Description : C Heap
    Date : 04/12/2025
*/

#ifndef __ME_HEAP_H__
#define __ME_HEAP_H__

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>


// Un Agent est une donnée, un agent est comme un fichier, un agent est comme objet, et un agent peut etre un pointeurs

typedef union {
    void * osAgent; // volume agentique : contient un model de reseau de neuronne contenant les données latentes
    void * osData;
    void * osObject;
    void * osSelfAddress;
    void * osFamily;
} Mirtille_Heap_type;

typedef struct {
    Mirtille_Heap_type agent;
    void * channelIN;
    void * channelOUT;
    void * plugIn;
    void * autoStack; // Chaque agent peut etre utiliser sur different niveau ==> different etats, un agent change d'état global/local
} Mirtille_HeapAgent;


// Structure to represent a Heap (Max Heap)
typedef struct Mirtille_Heap
{
    Mirtille_HeapAgent *agentSpace;
    int nature; //Utilité : capteurs / Mouvement / Stockage uniquement /....
    int location; // Niveau spatiale : profondeur / Largeur / Etat d'existence /etc...
    int size;
    int saturationCapacity;
} Mirtille_Heap;

// Function to create a heap
Mirtille_Heap *me_create_MirtilleHeap(int capacity);

// Function to swap two Mirtille_HeapAgents
void me_swap(Mirtille_HeapAgent *a, Mirtille_HeapAgent *b);

// Function to heapify the node at index i
void me_heapify(Mirtille_Heap *heap, int i);

// Function to build a max heap from an existing array
void me_buildHeap(Mirtille_Heap *heap);

// Function to increase the value at a given index
void me_increaseKey(Mirtille_Heap *heap, int index, Mirtille_HeapAgent newValue);

// Function to insert a new value into the heap
void me_insertHeap(Mirtille_Heap *heap, Mirtille_HeapAgent value);

// Function to extract the root (maximum element)
int me_extractMax(Mirtille_Heap *heap);

// Function to print the heap
void me_printHeap(Mirtille_Heap *heap);

// Function to delete an element at a given index
void me_deleteKey(Mirtille_Heap *heap, int index);

void me_destroy_Heap(Mirtille_Heap * heap);

#endif