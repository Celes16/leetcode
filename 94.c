#include <stdio.h>
#include <stdlib.h>

// definition for a binary tree node 
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode * right;
};

//helper function for inorder traversal 

void helper (struct TreeNode* root, int* ans, int* index) {
    if (root == NULL) {
        return;
    }
    helper (root -> left, ans, index);
    ans [(*index)++] = root -> val;
    helper (root -> right, ans, index);

}

//function to perform inorder traversal 

int* inorderTraversal (struct TreeNode* root, int* returnSize) {
    int* ans = (int*) malloc (100* sizeof (int)); // allocate mamory 

    *returnSize = 0;
    helper (root, ans, returnSize);
    return ans;
}

//example usage

int main () {
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {2, NULL, NULL};
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n4 = {4, NULL, NULL};
    struct TreeNode n5 = {5, NULL, NULL};
    struct TreeNode n6 = {6, NULL, NULL};
    struct TreeNode n7 = {7, NULL, NULL};
    struct TreeNode n8 = {8, NULL, NULL};
    struct TreeNode n9 = {9, NULL, NULL};

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n5.left = &n6;
    n5.right = &n7;
    n3.right = &n8;
    n8.left = &n9; 

    int returnSize;
    int* result = inorderTraversal (&n1, &returnSize);

    printf ("Inorder Traversal:");
    for (int i = 0; i < returnSize; i++){
        printf ("%d", result [i]);
    }
    printf ("\n");

    free (result);
    return 0;
    
}