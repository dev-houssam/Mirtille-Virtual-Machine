/*
    Author : Houssam BACAR
    Project Name : Mirtille Virtual Machine
    Description : C Heap
    Date : 04/12/2025
*/

#include "../include/me_heap.h"

// Function to create a heap
Mirtille_Heap *me_create_MirtilleHeap(int capacity)
{
    Mirtille_Heap *heap = (Mirtille_Heap *)malloc(sizeof(Mirtille_Heap));
    heap->size = 0;
    heap->saturationCapacity = capacity;
    heap->nature = 0;
    heap->location = 0;
    heap->agentSpace = (Mirtille_HeapAgent *)malloc(heap->saturationCapacity * sizeof(Mirtille_HeapAgent));
    if (heap->agentSpace == NULL)
    {
        return NULL;
    }
    return heap;
}

// Function to swap two Mirtille_HeapAgents
void me_swap(Mirtille_HeapAgent *a, Mirtille_HeapAgent *b)
{
    Mirtille_HeapAgent temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the node at index i
void me_heapify(Mirtille_Heap *heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    /*
    if (left < heap->size && heap->agentSpace[left] > heap->agentSpace[largest])
        largest = left;

    if (right < heap->size && heap->agentSpace[right] > heap->agentSpace[largest])
        largest = right;

    if (largest != i)
    {
        me_swap(&heap->agentSpace[i], &heap->agentSpace[largest]);
        me_heapify(heap, largest);
    }
    */
}

// Function to build a max heap from an existing array
void me_buildHeap(Mirtille_Heap *heap)
{
    int n = heap->size;
    for (int i = (n - 1) / 2; i >= 0; i--)
        me_heapify(heap, i);
}

// Function to increase the value at a given index
void me_increaseKey(Mirtille_Heap *heap, int index, Mirtille_HeapAgent newValue)
{
    /*
    if (index >= heap->size || heap->agentSpace[index] >= newValue)
    {
        printf("Invalid index or new value is not greater\n");
        return;
    }*/

    //heap->agentSpace[index] = newValue;
    /*while (index != 0 && heap->agentSpace[(index - 1) / 2] < heap->agentSpace[index])
    {
        me_swap(&heap->agentSpace[index], &heap->agentSpace[(index - 1) / 2]);
        index = (index - 1) / 2;
    }*/
}

// Function to insert a new value into the heap
void me_insertHeap(Mirtille_Heap *heap, Mirtille_HeapAgent value)
{
    /*
    if (heap->size == heap->saturationCapacity)
    {
        printf("Heap overflow\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->agentSpace[i] = value;
    */
    // Fix the heap property if it is violated
    /*while (i != 0 && heap->agentSpace[(i - 1) / 2] < heap->agentSpace[i])
    {
        me_swap(&heap->agentSpace[i], &heap->agentSpace[(i - 1) / 2]);
        i = (i - 1) / 2;
    }*/
}

// Function to extract the root (maximum element)
int me_extractMax(Mirtille_Heap *heap)
{
    /*if (heap->size <= 0)
        return INT_MIN;
    if (heap->size == 1)
    {
        heap->size--;
        return heap->agentSpace[0];
    }

    int root = heap->agentSpace[0];
    heap->agentSpace[0] = heap->agentSpace[heap->size - 1];
    heap->size--;
    me_heapify(heap, 0);
    
    return root;
    */
    return 0;
}

// Function to print the heap
void me_printHeap(Mirtille_Heap *heap)
{
    for (int i = 0; i < heap->size; ++i){
        //printf("%d ",  (heap->agentSpace[i]));
        printf("agent----\n");
    }
    printf("\n");
}

// Function to delete an element at a given index
void me_deleteKey(Mirtille_Heap *heap, int index)
{
    if (index >= heap->size)
    {
        printf("Invalid index\n");
        return;
    }

    if (index == heap->size - 1)
    {
        heap->size--;
        return;
    }

    heap->agentSpace[index] = heap->agentSpace[heap->size - 1];
    heap->size--;
    me_heapify(heap, index);
}


void me_destroy_Heap(Mirtille_Heap * heap){
	free(heap->agentSpace);
    free(heap);
}

/*
int test_main()
{
    Mirtille_Heap *heap = me_create_MirtilleHeap(10);

    me_insertHeap(heap, 3);
    me_insertHeap(heap, 2);
    me_insertHeap(heap, 15);
    me_insertHeap(heap, 5);
    me_insertHeap(heap, 4);
    me_insertHeap(heap, 45);

    printf("Max Heap array: ");
    me_printHeap(heap);

    printf("Extracted max value: %d\n", me_extractMax(heap));
    printf("Max Heap array after extraction: ");
    me_printHeap(heap);

    me_destroy_System(heap);

    return 0;
}
*/