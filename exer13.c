#include <stdio.h>
#include <string.h>

//we will use leverages pointers for iteration
int romanToInt(char *s){
    int sum = 0, currentValue = 0, prevValue = 0;

// Directly mapping Roman numerals to their values
    int values[256] = {0};
    values ['I'] = 1; 
    values ['V'] = 5;
    values ['X'] = 10;
    values ['L'] = 50;
    values ['C'] = 100;
    values ['D'] = 500;
    values ['M'] = 1000;
    
    prevValue = values [*s++];
    while (*s) {
        currentValue = values [*s++];
        if (currentValue > prevValue) {
            sum -= prevValue; // Subtract previous value from sum if current value is greater
        } else {
            sum += prevValue;  // Add previous value to sum if current value is less or equal
        }
        
        prevValue = currentValue; // Update prevValue to currentValue for the next iteration
    }
    sum += prevValue; // Add the last value to the sum
    return sum; // Return the total computed value
}

int main (){
    char roman [20];
    printf("Write a roman number:");
    scanf("%s", roman);

    int result = romanToInt (roman); // call the function
    printf ("The corresponding integer is: %d \n", result);
    
    return 0;
}
