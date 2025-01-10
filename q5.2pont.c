#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MX 100

int *encontrar_maior(int **matriz, int n);
int main() {
    int n;
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
        }
        printf("\n");
    }

    int *maior = encontrar_maior(matriz, n);

    printf("\nMaior valor: %d\n", *maior);
    printf("Endereço do maior valor: %p\n", (void *)maior);

    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

int *encontrar_maior(int **matriz, int n) {
    int *maior = *matriz;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (*(*(matriz + i) + j) > *maior) {
                maior = *(matriz + i) + j;
            }
        }
    }
    return maior;
}