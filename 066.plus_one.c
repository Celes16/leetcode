#include <stdio.h>
#include <stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for(int i = digitsSize - 1; i>=0; i--){ // read the array (right to left)
        digits[i]++; //adds 1 starting from the last digit

        if(digits[i] < 10){ //if the new digit is less than 10, there's no carryover, and the updated array is returned directly. for example [1,2,3] becomes [1,2,4] when you add 1.
        *returnSize = digitsSize; //ensures that the caller knows the size of the result array, unchanged in this case.
        //example: [1,2,3], digitsSize =3
        //after adding 1: [1,2,4], *returnSize = 3 because the array size didn't change.
        return digits;
        }
        digits[i] = 0; //if carryover occurs it sets the current digit to 0 and continues to the next iteration to add 1 to the previous digit.
    }
    int*result = (int*) malloc ((digitsSize + 1) * sizeof (int)); //if the loop finishes without returning, the number has grown in size 
    //so we allocate a new array of size "digitsSize + 1"

    result [0] = 1; // the first element is set to 1, representing the carryover. all the other elements are set to 0.

    for (int i = 1; i <= digitsSize; i++){
    result [i] = 0;
    }
    *returnSize = digitsSize + 1;
    return result;
}

int main () {
    int digits[] = {9,9,9};
    int digitsSize = sizeof(digits) / sizeof (digits[0]);
    int returnSize;

    int* result = plusOne(digits, digitsSize, &returnSize);

    printf ("resultado: [");
    for (int i = 0; i < returnSize; i++){
        printf("%d", result[i]);
        if (i < returnSize -1){
        printf(", ");
    }
    }
    printf("]\n");


    if (returnSize > digitsSize){
        free(result);
    }
    return 0;
}