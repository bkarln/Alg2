#include <stdio.h>

int main(){
  int k;
  scanf("%d",&k);
  int m[k][k];
  int maior, i, j;
  int menor=0;
  float media=0;
 
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
		    scanf("%d", &m[i][j]);
		    media=media+m[i][j];
		    if(m[i][j]>maior){
			maior=m[i][j];
		    }
		    if (menor==0){
		        menor=maior;
		    }
			if(m[i][j]<menor){
			menor=m[i][j];
	    	}
	}
	media=media/k;
	printf("Media da linha %d: %.2lf\n", i+1,media);
	media=0;
}
printf("Menor valor: %d\n", menor);
printf("Maior valor: %d\n", maior);
}

