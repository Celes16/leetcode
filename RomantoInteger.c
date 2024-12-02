#include <stdio.h>
#include <string.h>

int romanToValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0; 
    }
}

int romanToInt(char* s) {
    int total = 0;
    int prevValue = 0;

    for (int i = strlen(s) - 1; i >= 0; i--) {
        int currentValue = romanToValue(s[i]);
        
        if (currentValue < prevValue) {
            total -= currentValue;
        } else {
            total += currentValue;
        }

        prevValue = currentValue;
    }

    return total;
}

int main() {
    char roman[20];

    printf("Digite um numeral romano: ");
    scanf("%s", roman);

    int result = romanToInt(roman);

    printf("O valor inteiro é: %d\n", result);

    return 0;
}
