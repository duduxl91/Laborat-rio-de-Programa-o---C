#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MX 100
int main() {
    int n, soma = 0;
    int **matriz;

    printf("Digite a dimensão da matriz (n x n): ");
    scanf("%d", &n);

    matriz = (int **)malloc(n * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória para a coluna %d.\n", i);
            for (int k = 0; k < i; k++) {
                free(matriz[k]);
            }
            free(matriz);
            return 1;
        }
    }

    srand(time(NULL));

    printf("Matriz gerada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(*(matriz + i) + j) = rand() % MX;

            printf("%3d ", *(*(matriz + i) + j));

            if (i + j == n - 1) {
                soma += *(*(matriz + i) + j);
            }
        }
        printf("\n");
    }

    printf("\nSomatório da diagonal secundária: %d\n", soma);

    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
