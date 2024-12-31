// ROMAN VALUES
// I = 1
// V = 5
// X = 10
// L = 50 
// C = 100
// D = 500 
// M = 1000

// example: XX (10 + 10) + V (5) + II (1 + 1) = XXVII (27)
// Roman numerals are usually written largest to smallest - from left to right 

// we subtract 

// I = IV (4) and IX (9) 
// X = XL (40) and XC (90)
// C = CD (400) and CM (900)

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {
    int roman_map[256] = {0};

    // Mapping Roman numerals to their integer values
    roman_map['I'] = 1;
    roman_map['V'] = 5;
    roman_map['X'] = 10;
    roman_map['L'] = 50;
    roman_map['C'] = 100;
    roman_map['D'] = 500;
    roman_map['M'] = 1000;

    int result = 0;
    int i = 0;

    // Buffer for explanation
    char explanation[256] = "";
    char temp[32];

    while (s[i] != '\0') {
        if (s[i + 1] != '\0' && roman_map[s[i]] < roman_map[s[i + 1]]) {
            // Subtraction case
            sprintf(temp, "%c%c = %d", s[i], s[i + 1], roman_map[s[i + 1]] - roman_map[s[i]]);
            result += roman_map[s[i + 1]] - roman_map[s[i]]; // Add the full subtraction value
             i++; // Skip the next character
        } else {
            // Addition case
            sprintf(temp, "%c = %d", s[i], roman_map[s[i]]);
            result += roman_map[s[i]];
        }

        // Append the current explanation to the buffer
        strcat(explanation, temp);
        if (s[i + 1] != '\0') { // Add a comma and space unless it's the last element
            strcat(explanation, ", ");
        }

        i++;
    }

    // Print the explanation
    printf("Explanation: %s\n", explanation);

    return result;
}

int main() {
    char roman[] = "LVIII"; // Example Roman numeral
    int result = romanToInt(roman);

    printf("INPUT: s = \"%s\"\n", roman);
    printf("OUTPUT: %d\n", result);

    return 0;
}
