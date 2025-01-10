#include <stdio.h>

int primo(int num);
int main(){
    int n;
    printf("Digite o numero: \n");
    scanf("%d",&n);

    if (primo(n)){
        printf("O número %d é primo. \n", n);
    }
    else{
        printf("O número %d é primo. \n", n);
    }
    
    return 0;
}

int primo(int num){
    if (num <= 1){
        return 0;
    }
    for (int i = 2; i <= num / 2; i++){
        if( num % i == 0 ){
            return 0;
        }
    }
    return 1;


}