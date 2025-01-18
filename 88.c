#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if (n == 0) return; // return the function without merge it, we dont have the nums2 array for add with nums1, just mantain nums1 array without update it
    
    int end_idx = m + n - 1;

    while (n > 0 && m > 0) { //compare the arrays that have elements on both 
        if (nums2[n-1] >= nums1[m-1]){
            nums1 [end_idx] = nums2[n-1];
            n--;
        } else {
            nums1 [end_idx] = nums1 [m-1];
            m--;
        }
        end_idx--;
    }
    while (n > 0) { // if i have no elements on nums2 array
        nums1 [end_idx] = nums2[n-1];
        n--;
        end_idx--;
    }
}

int main() {
    int nums1[10] = {1,2,3,0,0,0}; // 10 for more space if necessary 
    int nums2[3] = {2,5,6};
    int m = 3;
    int n = 3;

    merge (nums1, 10,n,  nums2, 3, n);

    printf ("new array: {");
    for (int i=0; i < m +n ; i++){
        printf("%d", nums1[i]);

        if (i < m + n - 1) {    // Adding "," if it is not the last number
            printf(", ");
        }
    }
    
    printf("}\n");

    return 0;

}