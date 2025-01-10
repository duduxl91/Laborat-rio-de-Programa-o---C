#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MX 100

int main() {
    int n;
    int *matriz;
    int soma = 0;

    printf("Digite a dimensão da matriz (n x n): ");
    scanf("%d", &n);

    matriz = (int *)malloc(n * n * sizeof(int));
    if (matriz == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    srand(time(NULL));

    printf("Matriz gerada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(matriz + i * n + j) = rand() % MX;

            printf("%3d ", *(matriz + i * n + j));

            if (i == j) {
                soma += *(matriz + i * n + j);
            }
        }
        printf("\n");
    }

    printf("\nSomatório da diagonal principal: %d\n", soma);

    free(matriz);

    return 0;
}
