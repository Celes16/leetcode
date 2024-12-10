#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *stack1;   // Pilha principal
    int *stack2;   // Pilha auxiliar
    int top1;      // Topo da pilha 1
    int top2;      // Topo da pilha 2
    int capacity;  // Capacidade 
} MyQueue;

// Função para criar uma fila
MyQueue* myQueueCreate(int capacity) {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue -> stack1 = (int*)malloc(capacity * sizeof(int));
    queue -> stack2 = (int*)malloc(capacity * sizeof(int));
    queue -> top1 = -1;
    queue -> top2 = -1;
    queue -> capacity = capacity;
    return queue;
}

// Função para adicionar um elemento na fila
void myQueuePush(MyQueue* obj, int x) {
    obj -> stack1 [++(obj->top1)] = x; // Adiciona na pilha 1
}

// Função para remover o elemento da frente

int myQueuePop(MyQueue* obj) {
    if ( obj -> top2 == -1 ) { // Se a pilha 2 estiver vazia, transfira da pilha 1
        while ( obj -> top1 != -1 ) {
            obj -> stack2 [++ (obj -> top2) ] = obj -> stack1 [ (obj -> top1 ) --];
        }
    }
    return obj->stack2[(obj->top2)--]; // Remove o topo da pilha 2
}

// Função para obter o elemento da frente sem removê-lo
int myQueuePeek(MyQueue* obj) {
    if (obj -> top2 == -1) {             // Se a pilha 2 estiver vazia, transfira da pilha 1
        while (obj -> top1 != -1) {
            obj -> stack2 [++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
    return obj->stack2[obj->top2]; // Retorna o topo da pilha 2
}

