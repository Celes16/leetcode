#include <stdio.h>
#include <stdlib.h>

//definição da estrutura do nó da árvore 

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNewNode (int val) {
    struct TreeNode* newNode = (struct TreeNode*) malloc (sizeof(struct TreeNode));
    
    if (!newNode) {
        printf ("Erro o alocar memória! \n");
        return NULL;
    }

    newNode-> val = val;
    newNode-> left = NULL;
    newNode-> right = NULL;
    
    return newNode;
}

struct TreeNode* helper (int* nums, int s, int e){
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;
    struct TreeNode* node = createNewNode (nums [mid]);
    node -> left = helper (nums, s, mid - 1);
    node -> right = helper (nums, mid + 1, e );
    
    return node;
}

struct  TreeNode* sortedArrayToBST (int* nums, int numsSize) {
    return helper (nums, 0, numsSize-1);
}

void inorderTraversal (struct TreeNode* root){
    if (root == NULL)
        return;

    inorderTraversal (root -> left);
    printf ("%d", root->val);
    inorderTraversal (root -> right);

}


int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    int size = sizeof(nums) / sizeof (nums[0]);

    struct TreeNode* root = sortedArrayToBST (nums, size);

    printf("Árvore BST em ordem:");
    inorderTraversal (root);
    printf("\n");

    return 0;
}
