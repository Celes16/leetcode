#include <stdio.h>

int removeDuplicates (int* nums, int numsSize){
    if (numsSize == 0) { 
        return 0;
    }

   int c = 1;
   for (int i = 0; i < numsSize; i++){
    if (nums [i] != nums [c - 1]){
        nums [c] = nums [i]; //ele vai colocar o elemento diferente (que não se repete) na posição do seguinte numero unico que teremos no array que é o numero de endereço i que foi diferente nas comparações. exemplo: [1,1,1,3] ele vai modificar para [1,3,1,3] e o loop terminaria ai porque o i teria chegado ao ultimo endereço de comparação e o contador teria encerrado.
        c++;
    }
   }
   return c;
}

int main(){
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int numsSize = sizeof (nums) / sizeof (nums[0]);

    int uniqueCount = removeDuplicates (nums, numsSize);

    printf("%d, nums=[", uniqueCount);
    for (int i = 0; i < numsSize; i++){
        if (i < uniqueCount){
            printf ("%d", nums[i]);
        } else {
            printf("_");
        }
        if (i < numsSize - 1){
            printf (", "); 
        }
    }

    printf("]");
    return 0;
}