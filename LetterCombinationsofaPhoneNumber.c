#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* digitToLetters[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

int calculateTotalCombinations(const char* digits) {
    int total = 1;
    for (int i = 0; digits[i] != '\0'; i++) {
        int digit = digits[i] - '0';
        if (digit >= 2 && digit <= 9) {
            total *= strlen(digitToLetters[digit]);
        }
    }
    return total;
}

void generateCombinations(const char* digits, char** result, int* index, char* current, int depth) {
    if (digits[depth] == '\0') {
        current[depth] = '\0'; // Adiciona o terminador nulo
        result[*index] = strdup(current); // Salva a combinação atual
        (*index)++;
        return;
    }

    int digit = digits[depth] - '0';
    const char* letters = digitToLetters[digit];
    for (int i = 0; letters[i] != '\0'; i++) {
        current[depth] = letters[i];
        generateCombinations(digits, result, index, current, depth + 1);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    if (*digits == '\0') {
        *returnSize = 0;
        return NULL;
    }

    int totalCombinations = calculateTotalCombinations(digits);
    char** result = (char**)malloc(totalCombinations * sizeof(char*));
    char* current = (char*)malloc(strlen(digits) + 1); 
    int index = 0;

    generateCombinations(digits, result, &index, current, 0);

    *returnSize = totalCombinations;
    free(current); 
    return result;
}


int main() {
    char digits[] = "23";
    int returnSize;
    char** combinations = letterCombinations(digits, &returnSize);

    printf("Combinations for \"%s\":\n", digits);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", combinations[i]);
        free(combinations[i]); 
    }
    free(combinations); 
    return 0;
}
