#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct aluno {
    int RA;
    float parcial, exame, faltas;
};

void menu(){

    int opcao;

	printf("[1] - Cadastrar\n");
	printf("[2] - Exibir\n");
	printf("[3] - Procurar registro\n");
	printf("[4] - Alterar registro\n");
	printf("[5] - Exibir ordenadamente\n");
	printf("[6] - Deletar registro\n");
	printf("			[7] - Sair\n");
	printf("Opcao: ");
        scanf("%i", &opcao);

	switch (opcao){

        case 1:
            cadastrar();
        break;

        case 2:
            exibir();
        break;

        case 3:
            buscar();
        break;

        case 4:
            alterar();
        break;


        case 7:
            sair();
        break;

	}//switch

}//menu

void cadastrar(){//case 1

	int i, resposta1 = 0, resposta2 = 2;
	struct aluno Aluno[MAX];

    printf("\n\tREGISTRO DE ALUNO\n");
        while(resposta2 == 2){
            if(i < MAX){
                /*printf("\nRegistro N %i", i+1);*/
                printf("\nRA do aluno: ");
                    scanf("%i", &Aluno[i].RA);

                printf("NOTA PARCIAL do aluno: ");
                    scanf("%f", &Aluno[i].parcial);

                printf("NOTA EXAME do aluno: ");
                    scanf("%f", &Aluno[i].exame);

                printf("QUANTIDADE DE FALTAS do aluno: ");
                    scanf("%f", &Aluno[i].faltas);

                i++;

                printf("\nContinuar o registro?\n");
                printf("Sim [1] - Nao [2]: ");
                    scanf("%i", &resposta1);
                        if(resposta1 != 1){
                            printf("TEM CERTEZA?\n");
                            printf("Sim [1] - Nao [2]: ");
                            scanf("%i", &resposta2);
                        }
            }else{
                printf("\nLimite de registros atingido.\n");
                printf("Para continuar, exclua outros registros e retorne.\n\n");
                break;
            }
        }
        resposta2 = 2;
}//cadastrar

void exibir(){//case 2

     /*int j = 0;
     int i = MAX;*/
    float media, frequencia;
    int i = 0;
    struct aluno Aluno[MAX];

        printf("\n\tEXIBICAO DE REGISTROS\n");

        while(i < MAX){

            frequencia = ((Aluno[i].faltas / 80) * 100);

            printf("\n\n\tAluno %i", i+1);
            printf("\nRA: %i", Aluno[i].RA);
            printf("\nPARCIAL: %f", Aluno[i].parcial);
            printf("\nEXAME: %f", Aluno[i].exame);
            printf("\nQTD DE FALTAS: %.0f", Aluno[i].faltas);
            printf("MEDIA: %i", (Aluno[i].parcial * 0,4) + (Aluno[i].exame * 0.6) / 1.0);
            printf("FREQUENCIA: %%i", frequencia);
            if(frequencia < 25){
                printf("Aprovado.\n");
            }else if (frequencia > 25){
                printf("Reprovado.\n");
            }

            i++;
        }
}//exibir

void buscar (){//case 3

    int ra, i = 0;
    struct aluno Aluno[MAX];

    printf("\tBuscar dados específicos\n");
    printf("Digite o RA do aluno: ");
        scanf("%i", &ra);

    while(i < MAX){
        if(ra - Aluno[i].RA == 0){
            printf("\n\n\tAluno N %i", i+1);
            printf("\nRA: %i", Aluno[i].RA);
            printf("Nota PARCIAL: %f", Aluno[i].parcial);
            printf("Nota EXAME: %f", Aluno[i].exame);
            printf("Qtd FALTAS: %.0f\n", Aluno[i].faltas);
        }
    }

}//buscar

void alterar (){//case 4

    int escolha;
    int ra, i = 0;
    int ra2;
    float parcial2, exame2, faltas2;
    struct aluno Aluno[MAX];

    printf("\tAlterar dados específicos\n");
    printf("Digite o RA do aluno: ");
        scanf("%i", &ra);

    while(i < MAX){
        if(ra - Aluno[i].RA == 0){

            printf("[1] - RA\n");
            printf("[2] - Nota PARCIAl\n");
            printf("[3] - Nota EXAME\n");
            printf("[4] - Qtd de FALTAS\n");
            printf("Dado a ser alterado: ");
                scanf("%i", &escolha);

            if(escolha == 1){
                printf("NOVO RA: ");
                    scanf("%i", ra2);
                Aluno[i].RA = ra2;
            }else if(escolha == 2){
                printf("NOVA Nota PARCIAL: ");
                    scanf("%f", parcial2);
                Aluno[i].parcial = parcial2;
            }else if(escolha == 3){
                printf("NOVA Nota EXAME: ");
                    scanf("%f", exame2);
                Aluno[i].exame = exame2;
            }else if(escolha == 4){
                printf("NOVA Qtd de FALTAS: ");
                    scanf("%f", faltas2);
                Aluno[i].faltas = faltas2;
            }else{
                printf("Opcao invalida\n");
            }
        }
    }

}//alterar

int sair(){//case 7

    printf("\n\tObrigado.\n");
    exit("0");

}//sair

int main (){

    int escolha = 1;

    while (escolha){
        system("cls");
        menu();

        printf("\n\nRealizar outra atividade?\n");
        printf("[1] - Sim / [0] - Nao: ");
        scanf("%i", &escolha);
        printf("\n");
    }

}//main
