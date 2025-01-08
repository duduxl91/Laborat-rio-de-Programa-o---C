#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main() {
    int n, vetor[MAX];
    
    printf("Digite o tamanho do vetor : ", MAX);
    scanf("%d", &n);

    srand(time(NULL));

    printf("Vetor gerado:\n");
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100;
        printf("%d => %p\n", vetor[i], &vetor[i]);
    }

    int *maior = &vetor[0]; 
    for (int i = 1; i < n; i++) {
        if (*(vetor + i) > *maior) {
            maior = (vetor + i);
        }
    }

    printf("\nMaior valor: %d => endereço: %p)\n", *maior, maior);

    return 0;
}
