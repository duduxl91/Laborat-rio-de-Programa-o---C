#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MX 100

void somaPares(int *vetor, int tamanho, int *resultado);
int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Memoria insuficiente\n");
        return 1;
    }

    srand(time(NULL));
    printf("Vetor gerado: ");
    for (int i = 0; i < n; i++) {
        *(vetor + i) = rand() % MX;
        printf("%d ", *(vetor + i));
    }
    printf("\n");

    int resultado;
    somaPares(vetor, n, &resultado);

    printf("Somatório dos números pares: %d\n", resultado);

    free(vetor);

    return 0;
}

void somaPares(int *vetor, int tamanho, int *resultado) {
    *resultado = 0;

    for (int *ptr = vetor; ptr < vetor + tamanho; ptr++) {
        if (*ptr % 2 == 0) {
            *resultado += *ptr;
        }
    }
}
