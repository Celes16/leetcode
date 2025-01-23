#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//function to perform inorder traversal 
void inorderTraversal(struct Node* root){

//empty tree

if (root == NULL)
    return;

//recurtion on the left subtree
inorderTraversal (root -> left);

//visit the current node

printf ("%d", root -> data);

//recur on the right subtree

inorderTraversal(root -> right);

}

//funtion to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc (sizeof(struct Node));

    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

int main() {
    struct Node* root = newNode (1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode (4);
    root -> left -> right = newNode (5);
    root -> right -> right = newNode (6);
    printf ("inorder traversal: ");
    inorderTraversal (root);
    printf ("\n");

    return 0;
}