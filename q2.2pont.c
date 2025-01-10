#include <stdio.h>
#include <stdlib.h>

void ordenar_vetor(float *vetor, int n, char ordem) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            float *atual = vetor + j;
            float *proximo = vetor + j + 1;

            if ((ordem == 'c' && *atual > *proximo) || (ordem == 'd' && *atual < *proximo)) {
                float temp = *atual;
                *atual = *proximo;
                *proximo = temp;
            }
        }
    }
}

int main() {
    int n;
    char ordem;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    float *vetor = (float *)malloc(n * sizeof(float));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", vetor + i);
    }

    printf("Digite a ordem ('c' para crescente, 'd' para decrescente): ");
    scanf(" %c", &ordem);

    if (ordem != 'c' && ordem != 'd') {
        printf("Ordem inválida. Use 'c' ou 'd'.\n");
        free(vetor);
        return 1;
    }

    ordenar_vetor(vetor, n, ordem);

    printf("Vetor ordenado (%s):\n", ordem == 'c' ? "crescente" : "decrescente");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", *(vetor + i));
    }
    printf("\n");

    free(vetor);
    return 0;
}
