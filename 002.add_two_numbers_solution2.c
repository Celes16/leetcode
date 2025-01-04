#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ListNode structure  
struct ListNode {  
    int val;  
    struct ListNode* next;  
};

struct ListNode* createList(int* arr, int size) {  
    if (size <= 0) return NULL;  

    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));  
    struct ListNode* current = head;  
    
    head->val = arr[0];  
    head->next = NULL;  

    for (int i = 1; i < size; i++) {  
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));  
        current = current->next;  
        current->val = arr[i];  
        current->next = NULL;  
    }  
    return head;  
}  

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* dummyHead = malloc (sizeof(struct ListNode));
  
    dummyHead -> val = 0; // nó criado para iniciar a lista que vai ter a soma de l1 e l2 
    dummyHead -> next = NULL; //o próximo nó após o dummyhead ainda não existe, mas que vai ser a primeira soma depois
    
    //O nó dummyHead atuaria como um cabeçalho ou um ponto de referência para a lista, facilitando operações de inserção e remoção. 
    struct ListNode* curr = dummyHead; //inicialmente o ponteiro curr aponta para a dummyHead, ao longo do loop de soma, curr se move para o próximo nó seguindo a soma sequencial 
    int carry = 0; // variavel inteira, caso o numero inteiro do nó exeder de 9.

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1 -> val : 0; //"Se l1 não é nulo, então x recebe l1->val, caso contrário x recebe 0."
 //uso de operadores ternários, o operador compacta ser:
    //    if(l1 != NULL){ 
    //        x= l1-> val;
    //    } else {
    //    x = 0;
    //    }
       int y = (l2 != NULL) ? l2 -> val : 0;
        int sum = carry + x + y;
        carry = sum / 10;

        curr-> next = malloc (sizeof (struct ListNode)); // Aloca memória para o próximo nó da lista, ainda não foi criado o nó propriamente dito. Para criar o nó propriamente dito, você precisa definir os valores dos membros do nó após a alocação de memória.

        curr-> next -> val = sum % 10; //proximo valor criado, com o valor da soma dividido por 10 para saber se é de 0 a 9.
        curr-> next -> next = NULL;
        curr = curr -> next;

// Define o ponteiro 'next' do nó atual ('curr') para NULL,
// o que significa que o nó seguinte do nó atual não aponta para nenhum outro nó,
// efetivamente isolando o nó atual na lista.

// Atualiza o ponteiro 'curr' para o próximo nó na lista,
// movendo a referência para o próximo elemento após o nó atual.

        if (l1 != NULL) l1 = l1 -> next;
        if (l2 != NULL) l2 = l2 -> next;

//Nesse código, o loop continua até que ambas as listas sejam NULL. Para cada iteração do loop, ele verifica se l1 ou l2 ainda têm elementos e, em caso afirmativo, imprime o valor do nó atual e avança para o próximo nó. Isso garante que todos os elementos de ambas as listas sejam impressos, mesmo que uma lista tenha mais elementos que a outra.
    }
    struct ListNode* result = dummyHead -> next;
//cria um ponteiro chamado result que aponta para o nó que está logo após o nó dummyHead.

    free (dummyHead);
    return result; 
//  o código está limpando a memória utilizada por dummyHead e retornando a lista resultante ou os dados associados ao ponteiro result.
}

void printList(struct ListNode* node) {  
     while (node != NULL) {  
        printf("%d", node->val);  // Print the value of the current node  
        node = node->next;         // Move to the next node  
        if (node != NULL) {        // Check if there is a next node  
            printf(" -> ");        // Print the arrow only if there is a next node  
        }  
    }  
}  

void freeList(struct ListNode* node) {  
    while (node != NULL) {  
        struct ListNode* temp = node;  
        node = node->next;  
        free(temp);  
    }  
}  

int main() {  
    // Example lists: 342 (3 -> 4 -> 2) and 465 (5 -> 6 -> 4)  
    int arr1[] = {2, 4, 8};  
    int arr2[] = {5, 6, 4};  

    struct ListNode* l1 = createList(arr1, 3);  
    struct ListNode* l2 = createList(arr2, 3);  

   struct ListNode* result = addTwoNumbers(l1, l2);  
    
    printList(result); // Should print: 7 -> 0 -> 3 -> NULL  

    // Free the allocated memory  
    freeList(result);  
    freeList(l1);  
    freeList(l2);  
    
    return 0;  
}  