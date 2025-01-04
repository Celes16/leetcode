#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
struct ListNode {
    int val;
    struct ListNode* next;
};

// Função para criar uma lista encadeada a partir de um array
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;

    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* current = head;

//O ponteiro head é criado inicialmente como o primeiro nó da lista.
//É usado para armazenar a referência ao início da lista encadeada. Essa referência é essencial, pois ao final do processo de criação, precisamos retornar o início da lista para poder acessá-la depois.

    for (int i = 0; i < size; i++) {
        current->val = arr[i];
        if (i < size - 1) {
            current->next = malloc(sizeof(struct ListNode));
            current = current->next;
        } else {
            current->next = NULL;
        }
    }

    return head;
}

// Função para imprimir uma lista encadeada
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

// Função principal: Soma dois números representados como listas encadeadas
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode)); // Nó sentinela
    struct ListNode* temp = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        temp->next = malloc(sizeof(struct ListNode));
        temp->next->val = sum % 10;
        temp->next->next = NULL;
        temp = temp->next;
    }

    struct ListNode* result = dummy->next;
    free(dummy); // Liberar o dummy após guardar o próximo nó
    return result;
}

// Função para liberar a memória de uma lista encadeada
void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* next = current->next;
        free(current);
        current = next;
    }
}

// Função principal (main)
int main() {
    int arr1[] = {2, 4, 3}; // Representa o número 342
    int arr2[] = {5, 6, 4}; // Representa o número 465

    struct ListNode* l1 = createList(arr1, 3);
    struct ListNode* l2 = createList(arr2, 3);

    printf("Lista 1: ");
    printList(l1);

    printf("Lista 2: ");
    printList(l2);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Resultado da soma: ");
    printList(result);

    // Liberar memória
    freeList(l1);
    freeList(l2);
    freeList(result);

    return 0;
}
