#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função para criar um novo nó
struct TreeNode* createNewNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    if (!newNode) {
        printf("Erro ao alocar memória!\n");
        return NULL;
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função auxiliar para construir a BST balanceada
struct TreeNode* helper(int* nums, int s, int e) {
    if (s > e)
        return NULL;
    
    int mid = s + (e - s) / 2;
    struct TreeNode* node = createNewNode(nums[mid]);
    node->left = helper(nums, s, mid - 1);
    node->right = helper(nums, mid + 1, e);
    
    return node;
}

// Função principal para converter array ordenado em BST balanceada
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return helper(nums, 0, numsSize - 1);
}

// Função para imprimir a árvore em ordem
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

// Função para encontrar o menor valor na subárvore direita
struct TreeNode* findMin(struct TreeNode* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Função para deletar um nó na BST
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Função principal para testar
int main() {
    int nums[] = {-10, -3, 0, 5, 9};
    int size = sizeof(nums) / sizeof(nums[0]);
    
    struct TreeNode* root = sortedArrayToBST(nums, size);
    
    printf("Árvore BST em ordem: [");
    inorderTraversal(root);
    printf("]\n");
    
    root = deleteNode(root, 0);
    printf("Árvore BST após deletar 0: [");
    inorderTraversal(root);
    printf("]\n");
    
    return 0;
}
