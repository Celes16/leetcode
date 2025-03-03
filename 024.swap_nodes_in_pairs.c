#include <stdio.h>
#include <stdlib.h>
// list structure

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* swapPairs (struct ListNode* head){ 
    if (head == NULL || head->next == NULL){
        return head; //if there are less than 2 nodes, then return the list as is
    }
    struct ListNode* dummy = (struct ListNode*)malloc (sizeof(struct ListNode));
    dummy -> next = head;
    struct ListNode* prev = dummy;
    struct ListNode* current = head;

    while (current != NULL && current->next != NULL){
        prev -> next = current -> next;
        current -> next = prev -> next -> next;
        prev -> next -> next  = current;

        prev = current;
        current = current -> next;
    }
    struct ListNode* newHead = dummy -> next;
    free (dummy);
    return newHead;
}

//funtion to create a new ListNode

struct ListNode* createNode (int val) {
    struct ListNode* newNode = (struct ListNode*) malloc (sizeof (struct ListNode));

    newNode -> val = val;
    newNode -> next = NULL;
    return newNode;
}

//function to print the linked list 

void printList ( struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current -> val);
        current = current -> next;
    }
    printf ("NULL\n");
}

//main function 

int main () {
    struct ListNode* head = createNode (1);
    head -> next = createNode (2);
    head -> next -> next = createNode (3);
    head -> next -> next -> next = createNode (4);

    printf("original list: ");
    printList (head);

    // swap pairs in the linked list

    head = swapPairs (head);

    printf("list aftr swapping pairs:");
    printList(head);

    //free the allocated memory 
    struct ListNode* temp;
    while (head != NULL){
        temp = head;
        head = head -> next;
        free(temp);
    }
    return 0;
}