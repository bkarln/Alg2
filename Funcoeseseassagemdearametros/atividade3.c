#include <stdio.h>  

void processar(int vetor[], int n){
	for(int i=0; i<n; i++){
		if (i%2==0){
				vetor[i]= vetor[i]*2;	
			}
		else{
			vetor[i] = vetor[i]*3;
		}
	}
}

void printVetor(int vetor[], int n){
	for(int i=0; i<n; i++){
			printf("%d ", vetor[i]);
		}
	}

int main (){
    int n;
    scanf("%d", &n);
    int vetor[n];
        
    for (int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    processar(vetor, n);
    printVetor(vetor, n);
}  