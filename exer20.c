#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

// stack structure

typedef struct {
    char arr [MAX];
    int top;
}  Stack;

// initialize stack

void init (Stack *s) {
    s -> top = -1; // -1 = empty
}

//check if the stack is empty

bool isEmpty (Stack *s) {
    return s -> top == -1;
}

//push element from stack 

void push (Stack* s, char c){
    s -> arr [++(s -> top)] = c; // array is push and incremented on the top
}

//pop function 

char pop (Stack* s){
    return s-> arr [(s ->top)--];
}

//peek top element of the stack 

char peek (Stack* s){
    return s -> arr [s -> top];
}

// function for check balanced parentheses in an expression 

bool isValid(const char* s) {
    Stack stack;
    init(&stack);

    for (int i = 0; s[i] != '\0'; i++){
        char ch = s[i];
        
        if (isEmpty (&stack)){
            push (&stack, ch);
        } else if ((peek (&stack) == '(' && ch == ')') ||
                   (peek(&stack) == '{' && ch == '}') || 
                   (peek(&stack) == '[' && ch == ']')) {
            
            //if you found a complete pair and pop it 
            pop(&stack);
        } else {
            // return the character onto stack
            push (&stack, ch);

        }
    }
    // if the stack is empty, brackets are balanced
    return isEmpty (&stack);
}

int main () {
    const char *s = "{()}[]";

    if (isValid(s)) {
        printf ("true\n");
    } else {
        printf("false\n");
    }

    return 0;
    
}
