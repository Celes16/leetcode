#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* criarNo(int val) {
    struct TreeNode* novoNo = malloc(sizeof(struct TreeNode));
    novoNo->val = val;
    novoNo->left = NULL;
    novoNo->right = NULL;
    return novoNo;
}

int altura(struct TreeNode* node) {
    if (node == NULL) {
        return -1;
    }

    int alturaEsquerda = altura(node->left);

    int alturaDireita = altura(node->right);

    if (alturaEsquerda > alturaDireita) {
        return 1 + alturaEsquerda; 
    } else {
        return 1 + alturaDireita;  
    }
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    int alturaEsquerda = altura(root->left);
    int alturaDireita = altura(root->right);

    // se as alturas forem iguais, o nó atual é a raiz da menor subárvore
    if (alturaEsquerda == alturaDireita) {
        return root;
    }
    // se a subárvore esquerda for mais alta, a raiz está à esquerda
    else if (alturaEsquerda > alturaDireita) {
        return subtreeWithAllDeepest(root->left);
    }
    // se a subárvore direita for mais alta, a raiz está à direita
    else {
        return subtreeWithAllDeepest(root->right);
    }
}
int main() {
    
    struct TreeNode* root = criarNo(3);
    root->left = criarNo(5);
    root->right = criarNo(1);
    root->left->left = criarNo(6);
    root->left->right = criarNo(2);
    root->right->left = criarNo(0);
    root->right->right = criarNo(8);
    root->left->right->left = criarNo(7);
    root->left->right->right = criarNo(4);

    struct TreeNode* result = subtreeWithAllDeepest(root);

    printf("Menor subárvore com todos os nós mais profundos: %d\n", result->val);

    return 0;
}