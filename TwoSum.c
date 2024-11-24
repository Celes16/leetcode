#include <stdio.h>
#include <stdlib.h>

int* twoSum (int* nums, int numsSize, int target, int* returnSize) {
    int i, j,
    int *return_array = (int*) malloc (2 * sizeof( int));

    if (return_array == NULL) {
       *returnSize = 0;
       return NULL; 
    }

    for (i = 0; i < numsSize; i++) {
        for( j = i + 1; j < numsSize; j++)  // you may not use the same element twice
        { if (nums [i] + nums [j] == target) {
            *returnSize = 2.
            return_array[0] = i;
            return_array[0] = j;
            return return_array;
        }
        
        }
    }

    *returnSize = 0;
    free (return_array);
    return NULL;

}

int main ()
{
    int a [] = {2, 7, 11, 15},
    int rs; target = 9;
    int *p = NULL,

    p = twoSum (a, sizeof (a) / sizeof (a [0]), target, &rs);

    if (rs == 0) {
        printf ("Target not found\n");
    
    } else {
        printf ("Target found at indices %d and %d\n", p[0], p[1]);
        free (p);
    }
    return 0;
}