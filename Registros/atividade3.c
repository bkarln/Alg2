#include <stdio.h>
#include <string.h>

typedef struct endereco endereco;
typedef struct cliente cliente;

struct endereco {
    char rua[20];
    char cidade[20];
    char estado[20];
    int numero;  
};

struct cliente {
    int id;
    char nome[20];
    char telefone[20];
    endereco ender;
};

void ler_cliente(cliente *c, int n){
	int i;
	for (i = 0; i < n; i++){
		scanf("%d", &c[i].id);
		scanf("\n");
		fgets(c[i].nome, 20, stdin);
		c[i].nome[strlen(c[i].nome)-1] = '\0';
		fgets(c[i].ender.rua, 30, stdin);
		c[i].ender.rua[strlen(c[i].ender.rua)-1] = '\0';
		fgets(c[i].ender.estado, 20, stdin);
		c[i].ender.estado[strlen(c[i].ender.estado)-1] = '\0';
		fgets(c[i].ender.cidade, 20, stdin);
		c[i].ender.cidade[strlen(c[i].ender.cidade)-1] = '\0';
		scanf("%d", &c[i].ender.numero);
		scanf("\n");
		fgets(c[i].telefone, 21, stdin);
		c[i].telefone[strlen(c[i].telefone)-1] = '\0';
	}
}

void buscar_cliente(cliente *c, int n){
    int i = 0, cod=0;
    scanf("%d", &cod);
    for (i=0;i<n;i++){
        if(c[i].id == cod){
            printf("%d - %s \n%s, %d \n%s - %s \nTel: %s", c[i].id, c[i].nome, c[i].ender.rua, c[i].ender.numero, c[i].ender.cidade, c[i].ender.estado, c[i].telefone);
        }
    } 
}

void main(){
    cliente pessoas[3];
    ler_cliente(pessoas, 3);
    buscar_cliente(pessoas, 3);
}