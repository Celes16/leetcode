#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//node structure
typedef struct Node {
    int data;
    struct Node*next;
} Node;

//stack structure

typedef struct stack
{
    Node* top;
} Stack;

//initialize the Stack

Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack -> top = NULL;
    return stack;
}

//push function

void push (Stack* stack, int data) {
    Node* newNode = (Node*) malloc (sizeof (Node));
    newNode -> data = data;
    newNode -> next = stack -> top;
    stack -> top = newNode;
}

//pop Function

int pop (Stack* stack) {
    if (stack -> top == NULL) {
        printf ("Stack underflow\n");
        return -1; // indicate that the stack is empty

    }
    Node* temp = stack ->top;
    int poppedData = temp -> data;
    stack -> top = stack ->  top -> next;
    free (temp);
    return poppedData;
}

//peek Function 

int peek (Stack* stack){
    if (stack -> top == NULL){
        printf("Stack is empty\n");
        return -1; // empty

    }
    return stack -> top -> data;
}

//check if the stack is Empty 

bool isEmpty  (Stack* stack) {
    return stack -> top == NULL;
}

//main function testing

int main() {
    Stack* stack = createStack ();

    push (stack, 10);
    push (stack, 20);

    printf("Top element is %d\n", peek(stack)); // should print 20, the last element

    printf("Popped element is %d\n", pop (stack)); // should print 20
    printf ("popped element is %d\n", pop (stack)); //should print 10 
    printf ("popped element is %d\n", pop(stack)); //should indicate stack underflow 

    return 0;
}