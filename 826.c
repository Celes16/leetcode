#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int difficulty;
    int profit;
} Job;

int compare_jobs(const void *a, const void *b) {
    return ((Job *)a)->difficulty - ((Job *)b)->difficulty;
}


int compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxProfitAssignment(const int *difficulty, int difficultySize, const int *profit, int profitSize, int *worker, int workerSize) {
    Job jobs[difficultySize];  

    for (int i = 0; i < difficultySize; i++) {
        jobs[i].difficulty = difficulty[i];
        jobs[i].profit = profit[i];
    }

    qsort(jobs, difficultySize, sizeof(Job), compare_jobs);
    qsort(worker, workerSize, sizeof(int), compare_int);

    int total = 0;
    int maxProfit = 0;
    int j = 0;

    for (int i = 0; i < workerSize; i++) {
        while (j < difficultySize && jobs[j].difficulty <= worker[i]) {
            if (jobs[j].profit > maxProfit) {
                maxProfit = jobs[j].profit;
            }
            j++;
        }
        total += maxProfit;
    }

    return total;
}

int main() {
    int difficulty[] = {2, 4, 6, 8, 10};
    int profit[] = {10, 20, 30, 40, 50};
    int worker[] = {4, 5, 6, 7};
    int difficultySize = sizeof(difficulty) / sizeof(difficulty[0]);
    int workerSize = sizeof(worker) / sizeof(worker[0]);

    int result = maxProfitAssignment(difficulty, difficultySize, profit, difficultySize, worker, workerSize);
    printf("Lucro máximo: %d\n", result);

    return 0;
}


trabalhos(dificuldade x lucro)

dificuldades: [2, 4, 6, 8, 10]

lucros: [10, 20, 30, 40, 50]

[(2, 10), (4, 20), (6, 30), (8, 40), (10, 50)]

Trabalhadores:

Capacidades o: [4, 5, 6, 7]


Processo de Atribuição:

Para o trabalhador com capacidade 4:

Trabalhos considerados: (2, 10) e (4, 20).

Lucro máximo: 20.

Para o trabalhador com capacidade 5:

Trabalhos considerados: (2, 10), (4, 20).

Lucro máximo: 20.

Para o trabalhador com capacidade 6:

Trabalhos considerados: (2, 10), (4, 20), (6, 30).

Lucro máximo: 30.

Para o trabalhador com capacidade 7:

Trabalhos considerados: (2, 10), (4, 20), (6, 30).

Lucro máximo: 30.

Lucro Total:

20
+
20
+
30
+
30
=
100
20+20+30+30=100.