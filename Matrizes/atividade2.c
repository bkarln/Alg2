#include <stdio.h>

int main(){
  int k;
  scanf("%d",&k);
  float m[k][k];
  float soma[k][k];
  int i, j;

	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
		    scanf("%f", &m[i][j]);
		    soma[i][j]=m[i][j]+m[i][j];
		}
	}
		
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){	    
	printf("%.1lf ",soma[i][j]);
		}
	printf("\n");
	}
}


