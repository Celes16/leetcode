#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)
        return ""; // Se não houver strings, retorna uma string vazia.

    // Aloca memória para o prefixo (strlen(strs[0]) + 1 para o '\0').
    char* prefix = (char*)malloc(strlen(strs[0]) + 1);
    
    int i = -1; // Inicializa o índice i para -1, ele será incrementado antes do uso.
    
    do {
        i++; // Incrementa o índice.
        prefix[i] = strs[0][i]; // 

        // Compara o caractere nas outras strings.
        for (int j = 1; j < strsSize; j++) {
            if (!strs[j][i] || prefix[i] != strs[j][i]) {  // se a string 1 não tiver um primeiro prefixo, o primeiro caracter retorna vazio e se não tiver o prefixo i da primeira string (usada como comparação) na segunda string na mesma posição do i com o mesmo caractere tambem volta vazio.   
                prefix[i] = '\0'; // Se houver diferença ou fim da string, define '\0' no prefixo.
                break; // Sai do loop, pois o prefixo foi truncado.
            }
        }
    } while (prefix[i]); // Continua até encontrar o fim do prefixo.

    return prefix; // Retorna o prefixo comum.
}

int main() {
    char* strs[] = {"flower", "flow", "flight"};
    int strsSize = 3;
    printf("Longest Common Prefix: %s\n", longestCommonPrefix(strs, strsSize)); // Saída: "fl"
    
    char* strs2[] = {"dog", "racecar", "car"};
    int strsSize2 = 3;
    printf("Longest Common Prefix: %s\n", longestCommonPrefix(strs2, strsSize2)); // Saída: ""
    
    return 0;
}
