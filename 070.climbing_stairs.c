// n steps 
// how many ways can you climb to the top
// 1 <= n <= 45
// n = 

#include <stdio.h>


int climbStairsHelper(int n, int dp[]) {
    if (n <= 1) return 1; // Casos base: 1 maneira para 0 ou 1 degrau.
    if (dp[n] != -1) return dp[n]; // se o numero de maneiras for diferente de -1 retorne o dp[n]

    // Calcula o número de maneiras para n degraus.
    dp[n] = climbStairsHelper(n - 1, dp) + climbStairsHelper(n - 2, dp);

    //dp[2] = dp[1] + dp[0] = 1 + 1 = 2
    //dp[3] = dp[2] + dp[1] = 2 + 1 = 3
    //dp[4] = dp[3] + dp[2] = 3 + 2 = 5

    //no caso de n=4 seria 5 o numero de maneiras possiveis.
   
    return dp[n]; //valor do dp [n] final
}


int climbStairs(int n) {
    if (n <= 1) return 1; // Apenas 1 maneira de subir 0 ou 1 degrau.

    int dp[n + 1]; //numero de i do vetor se tem 5 andares tem 6 endereços 
    for (int i = 0; i <= n; i++) {
        dp[i] = -1; // Inicializa o vetor dp com todos valores sendo -1. Se inicializássemos o array com 0, haveria um problema: não saberíamos distinguir entre valores já calculados e valores que realmente devem ser zero.
    }

    return climbStairsHelper(n, dp);
}

int main() {
    int n;

    printf("Digite o numero de degraus: ");
    scanf("%d", &n);

    int result = climbStairs(n);
    printf("Numero de modos possiveis de subir %d degraus: %d\n", n, result);

    return 0;
}
