#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int uniqueIndex = 0; 

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[uniqueIndex]) { 
            uniqueIndex++;        
            nums[uniqueIndex] = nums[i]; 
        }
    }

    return uniqueIndex + 1; 
}

int main() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int newSize = removeDuplicates(nums, numsSize);

    printf("Novo comprimento: %d\n", newSize);
    printf("Array sem duplicatas: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
