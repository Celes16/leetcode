#include <stdio.h>
#include <stdlib.h>

// row 0 has 1 element [1]
// row 1 has 2 elements [1, 1]
// row 2 has 3 elements [1, 2, 1] ...

//firts we input parameters:
// int numRows: this will be the number of rows in Pascal's Triangle
// int **returnColumnSizes: the number of elements that are stored on 1 row. if we have 5 rows we have an array:[0, 1 , 2 , 3, 4]
// the elements for each row will be index + 1. so, for row 0 has 1 elementes for 1 has 2 elements ....
// number of elements (columns) -> returnColumnSizes = [1, 2, 3, 4, 5]
// returnSize: will store the total number of rows (columns), which will be the same as numRows.


// second: the firts and last elements of each row are always 1.
// the middle elements  are calculated as the sum of the two elements directly above them.

int ** generate (int numRows, int** returnColumnSizes, int * returnSize) {
    //initialize returnSize and returnColumnSizes
    *returnSize = numRows;

    //Allocate memory for triangle (a 2D array where each row is dynamically allocated).
    //Allocate memory for returnColumnSizes (an array that will store the size of each row).
    //For each row, allocate the necessary number of elements based on the row index.

    int** triangle = (int**) malloc (numRows * sizeof(int*));
    *returnColumnSizes = (int*) malloc (numRows * sizeof (int));

    for (int i = 0; i < numRows; i++){

         // Allocate memory for each row based on the row index
        triangle [i] = (int*) malloc ((i+1) * sizeof (int)); 

        
        // Store the size of the [current] row (i+1)
        (*returnColumnSizes) [i] = i + 1;

        triangle [i] [0] = 1;  // First element of each row is 1
        triangle [i] [i] = 1;  // Last element of each row is 1

        // Fill the middle elements (sum of two elements from the previous row)
        for (int j = 1; j < i; j++) {
            triangle [i] [j] = triangle [i - 1] [j - 1] + triangle [i-1][j];

        }
    }
    return triangle;
}

void printTriangle (int **triangle, int numRows, int *returnColumnSizes) {
    printf ("[");
    for (int i = 0; i < numRows; i++) {
        printf("[");
        for (int j = 0 ; j < returnColumnSizes[i]; j++){
            printf ("%d", triangle[i][j]);
            if ( j < returnColumnSizes[i] - 1){
                printf (",");
            }
        }
        printf("]");
        if (i < numRows - 1) {
           printf (",");

        }
    }
    printf("]\n");
}

void freeMemory (int** triangle, int numRows, int* returncolumnSizes){
    
    for (int i = 0; i < numRows ; i++) {
        free (triangle[i]); // free each row
    }
    free (triangle); 
    free (returncolumnSizes); 
}

int main(){
    int Rows = 5;
    int* returnColumnSizes = NULL; //stores the number of elements in each row.
    int  returnSize = 0;

  // Generate the Pascal's Triangle
    int **triangle = generate(Rows, &returnColumnSizes, &returnSize);

    // Print the Pascal's Triangle
    printTriangle(triangle, returnSize, returnColumnSizes);

    // Free the allocated memory
    freeMemory(triangle, returnSize, returnColumnSizes);

    return 0;
}