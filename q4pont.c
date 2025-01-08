#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main() {
    int n, vetor[MAX];
    int *enderecos[2] = {NULL, NULL};

    printf("Digite o tamanho do vetor: ", MAX);
    scanf("%d", &n);

    srand(time(NULL));

    printf("Vetor gerado:\n");
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100;
        printf("%.2d => endereço: %p\n", vetor[i], &vetor[i]);

        if (enderecos[0] == NULL && vetor[i] % 2 == 0) {
            enderecos[0] = &vetor[i];
        }
        if (enderecos[1] == NULL && vetor[i] % 2 != 0) {
            enderecos[1] = &vetor[i];
        }

    }

    if (enderecos[0] != NULL) {
        printf("\nPrimeiro valor par: %d => endereço: %p\n", *enderecos[0], enderecos[0]);
    } else {
        printf("\nNenhum valor par foi encontrado no vetor.\n");
    }

    if (enderecos[1] != NULL) {
        printf("Primeiro valor ímpar: %d => endereço: %p\n", *enderecos[1], enderecos[1]);
    } else {
        printf("Nenhum valor ímpar foi encontrado no vetor.\n");
    }

    return 0;
}
