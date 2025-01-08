#include <stdio.h>

int main(){
    int x, y, soma;
    int *px = &x ,*py = &y, *psoma = &soma;

    printf("Digite o primeiro número: \n");
    scanf("%d",px);

    printf("Digite o segundo número: \n");
    scanf("%d",py);

    *psoma = *px + *py;

    printf("A soma desses numeros é: %d", *psoma);


    return 0;
}   