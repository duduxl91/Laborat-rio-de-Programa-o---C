#include <stdio.h>

int soma(int *n1, int *n2){
    return *n1 + *n2;
}

int main(){
    int a, b, s;

    printf("Digite o primeiro número: \n");
    scanf("%d",&a);
    printf("Digite o segundo número: \n");
    scanf("%d",&b);

    s = soma( &a, &b);

    printf("A soma dos dois números é: %d \n",s);

    return 0;
}




