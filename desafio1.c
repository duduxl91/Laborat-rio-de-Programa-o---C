#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned char arm = 0;
    int arm_livre = 0;
    int opcao,num_arm,escolhido,i; 

    while (1) {
        puts("Status dos armários:\n");
        for ( i = 0; i < 8; i++) {
            printf("Armário %d: %s\n", i, (arm & (1 << i)) ? "Ocupado" : "Livre");
        }

        puts("\n1. Ocupar armário");
        puts("2. Liberar armário");
        puts("3. Sair");
        scanf("%d", &opcao);

        if (opcao == 1) {
            for (int i = 0; i < 8; i++) {
                if (!(arm & (1 << i))) {
                    arm_livre = 1;
                    break;
                }
            }

            if (!arm_livre) {
                puts("Todos os armários estão ocupados.\n");
            } else {
                do {
                    escolhido = rand() % 8;
                } while (arm & (1 << escolhido));

                arm |= (1 << escolhido); 
                printf("Armário %d foi ocupado.\n", escolhido);
            }
        } 
        else if (opcao == 2) {
            printf("Digite o número do armário para liberar (0-7): \n");
            scanf("%d", &num_arm);

            if (num_arm < 0 || num_arm > 7) {
                printf("Número do armário inválido.\n");
            } else if (!(arm & (1 << num_arm))) {
                printf("Armário %d já está livre.\n", num_arm);
            } else {
                arm &= ~(1 << num_arm); 
                printf("Armário %d foi liberado.\n", num_arm);
            }
        } 
        else if (opcao == 3) {
            printf("Encerrando o programa...\n");
            break;
        } 
        else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}
