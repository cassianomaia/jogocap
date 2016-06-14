#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int vitoria = 0;
int i,j,k, contagem =1;
void printmatriz (char tabuleiroprint[3][3][3]);
void checkdiagonal (char tabuleirod[3][3][3]);
void checkplano (char tabuleirop[3][3][3]);

struct jogador{
    int id;
    char unidade;
    struct jogador *proximo;
};

int main(){
    char tabuleiro[3][3][3];
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
        turno = turno->proximo;
        printmatriz(tabuleiro);
        printf("Turno do jogador %d.\nDigite as coordenadas(X,Y,Z):\n", turno->id);
        printf("X:");
        scanf("%d", &i);
        printf("Y:");
        scanf("%d", &j);
        printf("Z:");
        scanf("%d", &k);
        tabuleiro[i-1][j-1][k-1]=turno->unidade;
        while((i<0)||(i>3)||(j<0)||(j>3)||(k<0)||(k>3)){
            printf("Digite uma coordenada válida:\n");
            printf("X:");
            scanf("%d", &i);
            printf("Y:");
            scanf("%d", &j);
            printf("Z:");
            scanf("%d", &k);
            tabuleiro[i-1][j-1][k-1]=turno->unidade;
        }
    }while(vitoria!=1);

    //vitoria for atingida
    printmatriz(tabuleiro);
    printf("O jogador %d venceu !!!!!", jvitoria->id);
    return 0;
}

void checkdiagonal (char tabuleirod[3][3][3]){

}

void checkplano (char tabuleirop[3][3][3]){
    for(i=0;i<2;i++){
        if(tabuleirop[])
    }
}

void printmatriz (char tabuleiroprint[3][3][3]){
    system("cls");
     for(k=0;k<3;k++){
        printf(" \t1\t2\t3\n");
        for(i=0;i<3;i++){
            printf("%d\t",contagem);
            for(j=0;j<3;j++){
                printf("%c\t",tabuleiroprint[i][j][k]);
            }
            contagem++;
            printf("\n");
        }
        contagem=1;
        printf("\n\n");
    }
}
