#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = 
      (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL; //setting newNode->next = NULL ensures that the new node is not mistakenly connected to random, uninitialized memory.
    return newNode;
}

// Function to merge two sorted linked lists recursively
struct Node *sortedMerge(struct Node *head1, struct Node *head2) {
  
    // Base cases
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

   //if (head1 == NULL && head2 == NULL)
   //     return NULL;

   // this third condition doesn't cause errors, but it's redundant and unnecessary. 

    // Recursive merging based on smaller value
    if (head1->data <= head2->data) {
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    }
    else {
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}

// Function to print the linked list
void printList(struct Node *curr) {
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr-> next != NULL) { // the condition checks if there is a next node. curr->next its a pointer that points to the next node in the list (the expression gives you the address of the next node, not its value)
            printf(" ");            //to access the value of the next node, you'd need to use curr->next->data
        }
        curr = curr->next;
    }
    printf("\n"); //ensures the output ends with a newline for better formatting
}


int main() {

    // First linked list: 5 -> 10 -> 15
    struct Node *head1 = createNode(5);
    head1->next = createNode(10);
    head1->next->next = createNode(15);

    // Second linked list: 2 -> 3 -> 20
    struct Node *head2 = createNode(2);
    head2->next = createNode(3);
    head2->next->next = createNode(20);

    struct Node *res = sortedMerge(head1, head2);

    printList(res);

    //freeing memory

    struct Node *curr = res; //head of the list
    while (curr != NULL) { //using a loop to visit each node and stop when curr becomes NULL (end of the list)
        struct Node *temp = curr; //store the current node in a temporary pointer (temp)
        curr = curr -> next; //moving to the next node
        free(temp); // pointer (curr) iterate through the list and temporarily hold the address of the node to be freed.
    }   // If you directly free the head pointer (res), you lose the starting point of the list and thus lose access to the rest of the nodes. temp ensures this doesn’t happen.
    

    return 0;
}