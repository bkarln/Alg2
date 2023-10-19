#include <stdio.h>
#include <string.h>

typedef struct produtor_t produtor;

struct produtor_t{
    int codigo;
    char grao;
    float quantidade;  
};

void le_graos(produtor *prod){
	printf("Informe o codigo do produtor:");
 	scanf(" %d",&prod->codigo);
	printf("\n");
 	do{
 		printf("Informe o grao[F,M,S,T]:");
 		scanf(" %c",&prod->grao);
 		printf("\n");
 	}while((toupper(prod->grao) != 'F')&&
		  (toupper(prod->grao) != 'T')&&
 		  (toupper(prod->grao) != 'S')&&
 		  (toupper(prod->grao) != 'M'));

 	printf("Informe a quantidade de toneladas:");
 	scanf(" %f",&prod->quantidade);
 	printf("\n");
}

void imprime_totais(produtor *prod,int tam){
    float t_feijao=0, t_milho=0, t_soja=0, t_trigo=0;
    for(int i = 0; i<tam; i++){
        if(prod[i].grao =='F')t_feijao += prod[i].quantidade;
        else if(prod[i].grao =='M')t_milho += prod[i].quantidade;
        else if(prod[i].grao =='S')t_soja += prod[i].quantidade;
        else if(prod[i].grao =='T')t_trigo += prod[i].quantidade;
    };
    printf("\n");
    printf("Total de toneladas dos Produtos:"); 
    printf("\n");
    printf("Feijao: %.2f\n", t_feijao); 
    printf("Milho: %.2f\n", t_milho); 
    printf("Soja: %.2f\n", t_soja); 
    printf("Trigo: %.2f\n", t_trigo); 
}

void main () {
    int n=0;
    int i=0;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);
    printf("\n");
    //Declaração da variável tipo struct
    produtor entrada[n];

    for(i=0; i<n; i++){
    le_graos(&entrada[i]);
    }
    imprime_totais(entrada, n);
}


