#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int vitoria = 0;
int i,j,k;
void printmatriz (char *printer, int i1, int j1, int k1);
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
    struct jogador *turno;
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
        printmatriz(tabuleiro, 3, 3, 3);
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
        checkdiagonal(tabuleiro);
        checkplano(tabuleiro);
    }while(vitoria!=1);

    //vitoria for atingida
    printmatriz(tabuleiro, 3, 3, 3);
    printf("O jogador %d venceu !!!!!", turno->id);
    return 0;
}

void checkdiagonal (char tabuleirod[3][3][3]){
    if(((tabuleirod[1][1][1] == tabuleirod[0][0][0] && tabuleirod[1][1][1] == tabuleirod[2][2][2]) ||
        (tabuleirod[1][1][1] == tabuleirod[0][0][2] && tabuleirod[1][1][1] == tabuleirod[2][2][0]) ||
        (tabuleirod[1][1][1] == tabuleirod[0][2][0] && tabuleirod[1][1][1] == tabuleirod[2][0][2]) ||
        (tabuleirod[1][1][1] == tabuleirod[2][0][0] && tabuleirod[1][1][1] == tabuleirod[0][2][2])) && (tabuleirod[1][1][1] != '-')){
        vitoria = 1;
    }
}

void checkplano (char tabuleirop[3][3][3]){
    //checa em k
    for(k=0;k<3;k++){
        if((tabuleirop[0][0][k] == tabuleirop[1][1][k] && tabuleirop[0][0][k] == tabuleirop[2][2][k] && tabuleirop[0][0][k] != '-') ||
           (tabuleirop[0][2][k] == tabuleirop[1][1][k] && tabuleirop[0][2][k] == tabuleirop[2][0][k] && tabuleirop[0][2][k] != '-')){
            vitoria = 1;
        }else{
            for(i=0;i<3;i++){
                if((tabuleirop[i][0][k] == tabuleirop[i][1][k] && tabuleirop[i][0][k] == tabuleirop[i][2][k] && tabuleirop[i][0][k] != '-')||
                   (tabuleirop[0][i][k] == tabuleirop[1][i][k] && tabuleirop[0][i][k] == tabuleirop[2][i][k] && tabuleirop[0][i][k] != '-')){
                    vitoria = 1;
                }
            }
        }
    }
    //checa em i
    for(i=0;i<3;i++){
        if((tabuleirop[i][0][0] == tabuleirop[i][1][1] && tabuleirop[i][0][0] == tabuleirop[i][2][2] && tabuleirop[i][0][0] != '-') ||
           (tabuleirop[i][2][0] == tabuleirop[i][1][1] && tabuleirop[i][2][0] == tabuleirop[i][0][2] && tabuleirop[i][2][0] != '-')){
            vitoria = 1;
        }else{
            for(k=0;k<3;k++){
                if((tabuleirop[i][0][k] == tabuleirop[i][1][k] && tabuleirop[i][0][k] == tabuleirop[i][2][k] && tabuleirop[i][0][k] != '-')||
                   (tabuleirop[i][k][0] == tabuleirop[i][k][1] && tabuleirop[i][k][0] == tabuleirop[i][k][2] && tabuleirop[i][k][0] != '-')){
                    vitoria = 1;
                }
            }
        }
    }
    //checa em j
    for(j=0;j<3;j++){
        if((tabuleirop[0][j][0] == tabuleirop[1][j][1] && tabuleirop[0][j][0] == tabuleirop[2][j][2] && tabuleirop[0][j][0] != '-') ||
           (tabuleirop[0][j][2] == tabuleirop[1][j][1] && tabuleirop[0][j][2] == tabuleirop[2][j][0] && tabuleirop[0][j][2] != '-')){
            vitoria = 1;
        }else{
            for(i=0;i<3;i++){
                if((tabuleirop[i][j][0] == tabuleirop[i][j][1] && tabuleirop[i][j][0] == tabuleirop[i][j][2] && tabuleirop[i][j][0] != '-')||
                   (tabuleirop[0][j][i] == tabuleirop[1][j][i] && tabuleirop[0][j][i] == tabuleirop[2][j][i] && tabuleirop[0][j][i] != '-')){
                    vitoria = 1;
                }
            }
        }
    }
}

void printmatriz (char *printer, int i1, int j1, int k1){
    int contagem = 1;
    system("cls");
     for(k=0;k<k1;k++){
        printf(" \t1\t2\t3\n");
        for(i=0;i<i1;i++){
            printf("%d\t",contagem);
            for(j=0;j<j1;j++){
                printf("%c\t",*(((printer+j)+i)+k));
            }
            contagem++;
            printf("\n");
        }
        contagem=1;
        printf("\n\n");
    }
}
