#include <stdio.h>

int strStr(char* str, char* substr){
    int substr_len = 0;
    while (substr[substr_len] != '\0'){
        substr_len++;
    }
    int i, j;

    for (i = 0; str[i] != '\0'; i++){
        for (j = 0; j < substr_len && str [i + j] == substr[j]; j++);
        if (j == substr_len){
            return i;
        }
    }
    return -1;
}


int main() {
    char str[] = "happyandhappy";
    char substr[] = "happy";

    int index = strStr(str, substr);
    if (index != -1) {
        printf("The first occurrence of '%s' in '%s' starts at index %d.\n", substr, str, index);
    } else {
        printf("'%s' was not found in '%s'.\n", substr, str);
    }

    return 0;
}