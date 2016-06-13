#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct jogador{
    int id;
    char unidade;
};
int main(){
    char tabuleiro[3][3][3];
    int i;//i=linha
    int j;//coluna
    int k;//k-plano
    int contagem=0;//para efeito visual
    int vitoria;
    struct jogador jogador[2];
    struct jogador *j1, *j2;

    jogador[0].id=0;
    jogador[1].id=1;
    jogador[0].unidade='x';
    jogador[1].unidade='o';

    for(k=0;k<3;k++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                tabuleiro[i][j][k]='-';
            }
        }
    }

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

    do{
        printf("Turno do primeiro jogador\nDigite as coordenadas(X,Y,Z):\n");
        scanf("%d%d%d",&i,&j,&k);
        tabuleiro[i][j][k]='x';
        while((i<0)||(i>3)||(j<0)||(j>3)||(k<0)||(k>3)){
            printf("Digite uma coordenada válida:\n");
            scanf("%d%d%d",&i,&j,&k);
            tabuleiro[i][j][k]='x';
        }

        printf("Turno do segundo jogador\nDigite as coordenadas(X,Y,Z):\n");
        scanf("%d%d%d",&i,&j,&k);
        tabuleiro[i][j][k]='o';
        while((i<0)||(i>3)||(j<0)||(j>3)||(k<0)||(k>3)){
            printf("Digite uma coordenada válida:\n");
            scanf("%d%d%d",&i,&j,&k);
            tabuleiro[i][j][k]='o';
        }

    }while(vitoria!=1);

    return 0;
}
