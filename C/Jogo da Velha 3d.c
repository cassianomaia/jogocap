#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct jogador{
    int id;
    char unidade;
    struct jogador *proximo;
};
int main(){
    char tabuleiro[3][3][3];
    int i;//i=linha
    int j;//coluna
    int k;//k-plano
    int contagem=0;//para efeito visual
    int vitoria = 0;
    struct jogador jogador[2];
    struct jogador *turno, *jvitoria;
    jogador[0].id=1;
    jogador[1].id=2;
    jogador[0].unidade='x';
    jogador[1].unidade='o';
    jogador[0].proximo = &jogador[1];
    jogador[1].proximo = &jogador[0];

    //povoa o vetor com traços
    for(k=0;k<3;k++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                tabuleiro[i][j][k]='-';
            }
        }
    }

    //turno começa
    turno = &jogador[1];
    do{
        system("cls");
        for(k=0;k<3;k++){
            printf(" \t0\t1\t2\n");
            for(i=0;i<3;i++){
                printf("%d\t",contagem);
                for(j=0;j<3;j++){
                    printf("%c\t",tabuleiro[i][j][k]);
                }
                contagem++;
                printf("\n");
            }
            contagem=0;
            printf("\n\n");
        }
        printf("Turno do jogador %d.\nDigite as coordenadas(X,Y,Z):\n", turno->id);
        printf("X:");
        scanf("%d", &i);
        printf("Y:");
        scanf("%d", &j);
        printf("Z:");
        scanf("%d", &k);
        tabuleiro[i][j][k]=turno->unidade;
        while((i<0)||(i>3)||(j<0)||(j>3)||(k<0)||(k>3)){
            printf("Digite uma coordenada válida:\n");
            printf("X:");
            scanf("%d", &i);
            printf("Y:");
            scanf("%d", &j);
            printf("Z:");
            scanf("%d", &k);
            tabuleiro[i][j][k]=turno->unidade;
        }
        turno = turno->proximo;
    }while(vitoria!=1);

    //Qd vitoria for atingida
    system("cls");
     for(k=0;k<3;k++){
        printf(" \t0\t1\t2\n");
        for(i=0;i<3;i++){
            printf("%d\t",contagem);
            for(j=0;j<3;j++){
                printf("%c\t",tabuleiro[i][j][k]);
            }
            contagem++;
            printf("\n");
        }
        contagem=0;
        printf("\n\n");
    }
    printf("O jogador %d venceu !!!!!", jvitoria->id);
    return 0;
}
