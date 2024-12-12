//the sum of two integers will be the target, so you need to create an array to put all the integers and return an array of 2 elements indexes 

#include <stdio.h>
#include <stdlib.h>

int* twoSum (int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2; // ele indica que são 2 inteiros, sempre devo ou declarar ou multiplicar no sizeof pela quantidade de inteiros usados
    int *result = (int *) malloc (*returnSize * sizeof(int));
    
    if (result == NULL) { //verifica se a memoria foi alocada com sucesso
        *returnSize = 0;
        return NULL;
    }
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) { // we create a loop to designate the other element to comparate and it need to be different to the inicial element
            if ( nums[i] + nums[j] == target) {
                result [0] = i;
                result [1] = j;
                return result;
            }
        }
    }

    free (result); //libera a memoria alocada
    *returnSize = 0; //atualiza o tamanho de retorno para 0
    return NULL;
}

int main (){
    int nums [] = {2, 7, 11, 15};
    int target = 9;
    int returnSize; // variavel para armazenar o tamanho do array de retorno;

//chamamos a função com
    int *result = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);
// int *result declara um ponteiro para inteiro chamado result, usado para armazenar o endereço 
// do array que a função twoSum retorna. na função temos o nums (elementos do array), sizeof(nums) é o tamanho total do array em bytes e o sizeof (nums[0]) é o tamnho de um unico elemento do array (no caso de inteiros geralmente 4 bytes),
//dividindo o tamanho total pelo tamanho do elemento, voce tem o numero TOTAL DE ELEMENTOS no array
//target é o valor-alvo
//&returnSize passa o endereço da variavel returnSize para a função twoSum, isso permite que a funçãop ATUALIZE o valor de returnSize, indicando quantos elemento estão no array retornado.

if (result != NULL){ //verifica se foi encontrado um par válido
    printf ("indices encontrados; %d e %d\n", result [0], result [1]);
    free (result);
}   else {
    printf("Nenhum par foi encontrado\n");
}
    return 0;
}