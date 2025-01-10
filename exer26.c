#include <stdio.h>

int removeDuplicates (int* nums, int numsSize){
    if (numsSize == 0) { 
        return 0;
    }

   int c = 1;
   for (int i = 0; i < numsSize; i++){
    if (nums [i] != nums [c - 1]){
        nums [c] = nums [i];
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