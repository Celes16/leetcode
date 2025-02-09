#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do SeatManager com uma min-heap
typedef struct {
    int *heap;
    int size;
    int capacity;
} SeatManager;


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(int *heap, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void heapifyUp(int *heap, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap[index] < heap[parent]) {
        swap(&heap[index], &heap[parent]);
        heapifyUp(heap, parent);
    }
}

SeatManager* createSeatManager(int n) {
    SeatManager *manager = (SeatManager*)malloc(sizeof(SeatManager));
    manager->heap = (int*)malloc(n * sizeof(int));
    manager->size = n;
    manager->capacity = n;

    for (int i = 0; i < n; i++)
        manager->heap[i] = i + 1; // Insere os assentos em ordem crescente

    return manager;
}

int reserve(SeatManager* obj) {
    if (obj->size == 0) return -1; // Nenhum assento disponível

    int seat = obj->heap[0]; // Menor assento
    obj->heap[0] = obj->heap[--(obj->size)]; 
    heapifyDown(obj->heap, obj->size, 0); 

    return seat;
}

void unreserve(SeatManager* obj, int seatNumber) {
    obj->heap[obj->size++] = seatNumber;
    heapifyUp(obj->heap, obj->size - 1);
}

// Liberar memória
void seatManagerFree(SeatManager* obj) {
    free(obj->heap);
    free(obj);
}


int main() {
    // Cria o SeatManager com 5 assentos
    SeatManager* manager = createSeatManager(5);  // Agora chamamos a função createSeatManager com n = 5

    printf("null\n");

    int result;
    
    result = reserve(manager);
    printf("%d\n", result);
    
    result = reserve(manager); 
    printf("%d\n", result);
    
    unreserve(manager, 2); 
    printf("null\n");
    
    result = reserve(manager); 
    printf("%d\n", result);
    
    result = reserve(manager); 
    printf("%d\n", result);
    
    result = reserve(manager); 
    printf("%d\n", result);
    
    result = reserve(manager);  
    printf("%d\n", result);  
    
    unreserve(manager, 5); 
    printf("null\n");
    
    seatManagerFree(manager); 

    return 0;
}
