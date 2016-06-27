#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//declaração de variaveis globais
int vitoria = 0;
int i,j,k;
struct jogador{
    char unidade;
};

//declaração de protótipos de funções
void printmatriz (char tabuleirop[3][3][3], int turno);
int checkdiagonal (char tabuleirod[3][3][3]);
int checkplano (char tabuleirop[3][3][3]);
void gravaarquivo (char *tabuleirop);
void learquivo (char *tabuleirop);

int main(){
    //declaração de variavies locais
	char *parametros;
	char tabuleiro[3][3][3];
    struct jogador jogadores[2];
    int turno;
    int x, y, z;

	parametros = getenv("QUERY_STRING");

		
	jogadores[0].unidade = 'X';
	jogadores[1].unidade = 'O';
	
    if (sscanf(parametros, "x=%d&y=%d&z=%d&turno=%d", &x, &y, &z, &turno) != 4) {
		for(k=0;k<3;k++){
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					tabuleiro[i][j][k]='-';
				}
			}
		}

		turno = 0;
		
		// criação do arquivo
		gravaarquivo(tabuleiro);
	} else {
		
		//leitura do arquivo 
		learquivo(tabuleiro);
		if(tabuleiro[x][y][z] == '-'){
			tabuleiro[x][y][z] = jogadores[turno].unidade;

			if (checkdiagonal(tabuleiro) || checkplano(tabuleiro)) {
				vitoria = 1;
			}
			turno = !turno;
			gravaarquivo(tabuleiro);
		}
	}
	printmatriz(tabuleiro, turno);
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
        if(tabuleirod[1][1][0] == tabuleirod[1][1][2] && tabuleirod[1][1][0] == tabuleirod[1][1][1] && tabuleirod[1][1][0] != '-'){
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

void gravaarquivo (char *tabuleirop){
	FILE *pMatriz = fopen("/home/bcc/726507/public_html/tabuleiro.bin","wb");
		if(pMatriz){
			fwrite(tabuleirop, sizeof(char), 27, pMatriz);
			fclose(pMatriz);
		}
}

void learquivo (char *tabuleirop){
	FILE *pMatriz = fopen("/home/bcc/726507/public_html/tabuleiro.bin","rb");
		if(pMatriz){
			fread(tabuleirop, sizeof(char), 27, pMatriz);
			fclose(pMatriz);
		}
}

void printmatriz (char tabuleirop[3][3][3], int turno){	
	printf("Content-type: text/html\r\n\r\n");
	printf("<HTML>"
		"<head>"
		"<meta charset='utf-8'>"
		"<title> Tic Tac Toe 3D </title>"
		"<link rel='stylesheet' href='../jogo.css' type='text/css' >"
		"<link rel=\"apple-touch-icon\" sizes=\"57x57\" href=\"../favicon/apple-touch-icon-57x57.png\">"
		"<link rel=\"apple-touch-icon\" sizes=\"60x60\" href=\"../favicon/apple-touch-icon-60x60.png\">"
		"<link rel=\"apple-touch-icon\" sizes=\"72x72\" href=\"../favicon/apple-touch-icon-72x72.png\">"
		"<link rel=\"apple-touch-icon\" sizes=\"76x76\" href=\"../favicon/apple-touch-icon-76x76.png\">"
		"<link rel=\"apple-touch-icon\" sizes=\"114x114\" href=\"../favicon/apple-touch-icon-114x114.png\">"
		"<link rel=\"apple-touch-icon\" sizes=\"120x120\" href=\"../favicon/apple-touch-icon-120x120.png\">"
		"<link rel=\"apple-touch-icon\" sizes=\"144x144\" href=\"../favicon/apple-touch-icon-144x144.png\">"
		"<link rel=\"apple-touch-icon\" sizes=\"152x152\" href=\"../favicon/apple-touch-icon-152x152.png\">"
		"<link rel=\"apple-touch-icon\" sizes=\"180x180\" href=\"../favicon/apple-touch-icon-180x180.png\">"
		"<link rel=\"icon\" type=\"image/png\" href=\"../favicon/favicon-32x32.png\" sizes=\"32x32\">"
		"<link rel=\"icon\" type=\"image/png\" href=\"../favicon/android-chrome-192x192.png\" sizes=\"192x192\">"
		"<link rel=\"icon\" type=\"image/png\" href=\"../favicon/favicon-96x96.png\" sizes=\"96x96\">"
		"<link rel=\"icon\" type=\"image/png\" href=\"../favicon/favicon-16x16.png\" sizes=\"16x16\">"
		"<link rel=\"manifest\" href=\"../favicon/manifest.json\">"
		"<link rel=\"mask-icon\" href=\"../favicon/safari-pinned-tab.svg\" color=\"#5bbad5\">"
		"<link rel=\"shortcut icon\" href=\"../favicon/favicon.ico\">"
		"<meta name=\"msapplication-TileColor\" content=\"#da532c\">"
		"<meta name=\"msapplication-TileImage\" content=\"../favicon/mstile-144x144.png\">"
		"<meta name=\"msapplication-config\" content=\"../favicon/browserconfig.xml\">"
		"<meta name=\"theme-color\" content=\"#ffffff\">"
		"</head>"
		"<body>"
	);
	printf("<div id='tabuleiro'>");
	for(k=0;k<3;k++){
		printf("<div id='cubo'>");
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				printf("<%s href='?x=%d&y=%d&z=%d&turno=%d'>%c</%s> ", vitoria ? "span" : "a", i, j, k, turno, tabuleirop[i][j][k], vitoria ? "span" : "a");
			}
			printf("<br>");
		}
		printf("</div>");
		printf("<br><br>");
	}
	printf("</div>");
	if (vitoria) {
		turno != turno;
		printf("<div id='vitoria'>");
		printf("O jogador %c venceu!", turno ? 'X' : 'O');
		printf("<div id='botao'><form action='http://cap.dc.ufscar.br/~726507/cgi-bin/jogo-da-velha-3d-cgi.cgi' method='get'>"
		"<input class='button' type='submit' value='Restart'/>"
		"</form>"
		"</div>");
		printf("</div");
	}
	printf("</body>");
}
