#include <stdio.h>

int main(){
  int m[3][3];
  int i,j;

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
		    scanf("%d", &m[i][j]);
		}
	}
		
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){	    
	printf("%.1d ",m[j][i]);
		}
	printf("\n");
	}
}


