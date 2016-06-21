#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//declara��o de variaveis globais
int vitoria = 0;
int i,j,k;
struct jogador{
    int n;
    char unidade;
    struct jogador *proximo;
};

//declara��o de prot�tipos de fun��es
void printmatriz (char tabuleirop[3][3][3]);
void checkdiagonal (char tabuleirod[3][3][3]);
void checkplano (char tabuleirop[3][3][3]);

int main(){
    printf("Content-type: text/html\r\n\r\n");

    //declara��o de variavies locais
	char *parametros;
	char tabuleiro[3][3][3];
    struct jogador jogador[2];
    struct jogador *turno;
    int x, y, z;
    srand(time(NULL));

	parametros = getenv("QUERY_STRING");

    sscanf(parametros, ,);


    //fazer a partir daqui

    //povoamento da array de variaveis heterogeneas
    jogador[0].unidade='X';
    jogador[0].n=0;
    jogador[0].proximo = &jogador[1];
    jogador[1].unidade='O';
    jogador[1].n=1;
    jogador[1].proximo = &jogador[0];

    //povoa o vetor com tra�os
    for(k=0;k<3;k++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                tabuleiro[i][j][k]='-';
            }
        }
    }

    //fase de turnos, jogo come�a
    turno = &jogador[rand()%2];
    do{
        turno = turno->proximo;
        printmatriz(tabuleiro);
        printf("Turno de %e.\nDigite as coordenadas(X,Y,Z):\n", turno->n);
        printf("X:");
        scanf("%d", &x);
        printf("Y:");
        scanf("%d", &y);
        printf("Z:");
        scanf("%d", &z);
        tabuleiro[x-1][y-1][z-1]=turno->unidade;
        while((x<0)||(x>3)||(y<0)||(y>3)||(z<0)||(z>3)){
            printf("Digite uma coordenada v�lida:\n");
            printf("X:");
            scanf("%d", &x);
            printf("Y:");
            scanf("%d", &y);
            printf("Z:");
            scanf("%d", &z);
            tabuleiro[x-1][y-1][z-1]=turno->unidade;
        }
        checkdiagonal(tabuleiro);
        checkplano(tabuleiro);
    }while(vitoria!=1);

    //condi��o de vit�ria satisfeita
    printmatriz(tabuleiro);
    printf("O jogador %e venceu !!!!!", turno->n);
    return 0;
}

//procedimentos
void checkdiagonal (char tabuleirod[3][3][3]){
    if(((tabuleirod[1][1][1] == tabuleirod[0][0][0] && tabuleirod[1][1][1] == tabuleirod[2][2][2]) ||
        (tabuleirod[1][1][1] == tabuleirod[0][0][2] && tabuleirod[1][1][1] == tabuleirod[2][2][0]) ||
        (tabuleirod[1][1][1] == tabuleirod[0][2][0] && tabuleirod[1][1][1] == tabuleirod[2][0][2]) ||
        (tabuleirod[1][1][1] == tabuleirod[2][0][0] && tabuleirod[1][1][1] == tabuleirod[0][2][2])) && (tabuleirod[1][1][1] != '-')){
        vitoria = 1;
    }else{
        if(tabuleirod[1][1][1] == tabuleirod[1][1][3] && tabuleirod[1][1][1] == tabuleirod[1][1][2] && tabuleirod[1][1][1] != '-'){
            vitoria = 1;
        }
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

void printmatriz (char tabuleirop[3][3][3]){
    int contagem = 1;
    system("cls");
     for(k=0;k<3;k++){
        printf(" \t1\t2\t3\n");
        for(i=0;i<3;i++){
            printf("%d\t",contagem);
            for(j=0;j<3;j++){
                printf("%c\t",tabuleirop[i][j][k]);
            }
            contagem++;
            printf("\n");
        }
        contagem=1;
        printf("\n\n");
    }
}