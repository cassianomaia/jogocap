#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//declaração de variaveis globais
int vitoria = 0;
int i,j,k;
int contagem = 0;
struct jogador{
    char unidade;
};

//declaração de protótipos de funções
void printmatriz (char tabuleirop[3][3][3], int turno);
int checkdiagonal (char tabuleirod[3][3][3]);
int checkplano (char tabuleirop[3][3][3]);

int main(){
    printf("Content-type: text/html\r\n\r\n");

    //declaração de variavies locais
	char *parametros;
	char tabuleiro[3][3][3];
    struct jogador jogadores[2];
    int turno;
    int x, y, z;

	parametros = getenv("QUERY_STRING");

    if (sscanf(parametros, "x=%d&y=%d&z=%d&turno=%d", &x, &y, &z, &turno) != 4) {
		for(k=0;k<3;k++){
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					tabuleiro[i][j][k]='-';
				}
			}
		}
		
		jogadores[0].unidade = 'X';
		jogadores[1].unidade = '0';

		turno = 0;
		
		// criação do arquivo
		FILE *pMatriz = fopen("/home/bcc/726507/public_html/tabuleiro.bin","wb");
		if(pMatriz){
			fwrite(tabuleiro, sizeof(char), 27, pMatriz);
			fclose(pMatriz);
		}
		printmatriz(tabuleiro, turno);	
	} else {
		
		//leitura do arquivo 
		FILE *pMatriz = fopen("/home/bcc/726507/public_html/tabuleiro.bin","rb");
		if(pMatriz){
			fread(tabuleiro, sizeof(char), 27, pMatriz);
			fclose(pMatriz);
		}
		
		tabuleiro[x][y][z] = jogadores[turno].unidade;
		printf("%c", jogadores[turno].unidade);
        if (checkdiagonal(tabuleiro) || checkplano(tabuleiro)) {
			printf("O jogador %c venceu !!!!!", jogadores[turno].unidade);
			printmatriz(tabuleiro, turno);
		}else{
			turno = !turno;
			printmatriz(tabuleiro, turno);
		}
		FILE *pMatriz2 = fopen("/home/bcc/726507/public_html/tabuleiro.bin","wb");
		if(pMatriz2){
			fwrite(tabuleiro, sizeof(char), 27, pMatriz2);
			fclose(pMatriz2);
		}
	}

	
    
    return 0;
}

//procedimentos
int checkdiagonal (char tabuleirod[3][3][3]){
    if(((tabuleirod[1][1][1] == tabuleirod[0][0][0] && tabuleirod[1][1][1] == tabuleirod[2][2][2]) ||
        (tabuleirod[1][1][1] == tabuleirod[0][0][2] && tabuleirod[1][1][1] == tabuleirod[2][2][0]) ||
        (tabuleirod[1][1][1] == tabuleirod[0][2][0] && tabuleirod[1][1][1] == tabuleirod[2][0][2]) ||
        (tabuleirod[1][1][1] == tabuleirod[2][0][0] && tabuleirod[1][1][1] == tabuleirod[0][2][2])) && (tabuleirod[1][1][1] != '-')){
        return 1;
    }else{
        if(tabuleirod[1][1][1] == tabuleirod[1][1][3] && tabuleirod[1][1][1] == tabuleirod[1][1][2] && tabuleirod[1][1][1] != '-'){
            return 1;
        }
    }
	return 0;
}

int checkplano (char tabuleirop[3][3][3]){
    //checa em k
    for(k=0;k<3;k++){
        if((tabuleirop[0][0][k] == tabuleirop[1][1][k] && tabuleirop[0][0][k] == tabuleirop[2][2][k] && tabuleirop[0][0][k] != '-') ||
           (tabuleirop[0][2][k] == tabuleirop[1][1][k] && tabuleirop[0][2][k] == tabuleirop[2][0][k] && tabuleirop[0][2][k] != '-')){
            return 1;
        }else{
            for(i=0;i<3;i++){
                if((tabuleirop[i][0][k] == tabuleirop[i][1][k] && tabuleirop[i][0][k] == tabuleirop[i][2][k] && tabuleirop[i][0][k] != '-')||
                   (tabuleirop[0][i][k] == tabuleirop[1][i][k] && tabuleirop[0][i][k] == tabuleirop[2][i][k] && tabuleirop[0][i][k] != '-')){
                   return 1;
                }
            }
        }
    }
    //checa em i
    for(i=0;i<3;i++){
        if((tabuleirop[i][0][0] == tabuleirop[i][1][1] && tabuleirop[i][0][0] == tabuleirop[i][2][2] && tabuleirop[i][0][0] != '-') ||
           (tabuleirop[i][2][0] == tabuleirop[i][1][1] && tabuleirop[i][2][0] == tabuleirop[i][0][2] && tabuleirop[i][2][0] != '-')){
            return 1;
        }else{
            for(k=0;k<3;k++){
                if((tabuleirop[i][0][k] == tabuleirop[i][1][k] && tabuleirop[i][0][k] == tabuleirop[i][2][k] && tabuleirop[i][0][k] != '-')||
                   (tabuleirop[i][k][0] == tabuleirop[i][k][1] && tabuleirop[i][k][0] == tabuleirop[i][k][2] && tabuleirop[i][k][0] != '-')){
                    return 1;
                }
            }
        }
    }
    //checa em j
    for(j=0;j<3;j++){
        if((tabuleirop[0][j][0] == tabuleirop[1][j][1] && tabuleirop[0][j][0] == tabuleirop[2][j][2] && tabuleirop[0][j][0] != '-') ||
           (tabuleirop[0][j][2] == tabuleirop[1][j][1] && tabuleirop[0][j][2] == tabuleirop[2][j][0] && tabuleirop[0][j][2] != '-')){
            return 1;
        }else{
            for(i=0;i<3;i++){
                if((tabuleirop[i][j][0] == tabuleirop[i][j][1] && tabuleirop[i][j][0] == tabuleirop[i][j][2] && tabuleirop[i][j][0] != '-')||
                   (tabuleirop[0][j][i] == tabuleirop[1][j][i] && tabuleirop[0][j][i] == tabuleirop[2][j][i] && tabuleirop[0][j][i] != '-')){
                    return 1;
                }
            }
        }
    }
	
	return 0;
}

void printmatriz (char tabuleirop[3][3][3], int turno){	
	contagem = 1;
	for(k=0;k<3;k++){
        printf(" 1 2 3<br>");
        for(i=0;i<3;i++){
            printf("%d\t",contagem);
            for(j=0;j<3;j++){
                printf("<a href='?x=%d&y=%d&z=%d&turno=%d'>%c</a> ", i, j, k, turno, tabuleirop[i][j][k]);
            }
            contagem++;
            printf("<br>");
        }
        contagem=1;
        printf("<br><br>");
    }
}
