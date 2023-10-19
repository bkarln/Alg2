#include <stdio.h>

void printMatriz(int l, int c, int matriz[3][3]){
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

int processaMatriz(int l, int c, int x, int matriz[3][3]){
	int mudou = l*c;
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			if (matriz[i][j]<=x){
				matriz[i][j] = 0;
			mudou--;	
			}
		}	
	}
	return mudou;
}

int main (){
    int x, alteracoes=0;
	int matriz[3][3];
	scanf("%d",&x);
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
	alteracoes = processaMatriz(3, 3, x, matriz);
	printMatriz(3, 3, matriz);
	printf("Quantidade não alterada=%d",alteracoes);
}