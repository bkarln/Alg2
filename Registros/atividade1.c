#include <stdio.h>
#include <string.h>

typedef struct pessoa_s pessoa_t;
typedef struct data_s data_t;

struct data_s {
    int dia, mes, ano; 
};

struct pessoa_s {
    int cod;
    char nome[64];
    data_t nasc;
};

void read_person(pessoa_t *p){
    scanf("%d", &p->cod);
    scanf(" %[^\n]s", p->nome);
    scanf("%d", &p->nasc.dia);
    scanf("%d", &p->nasc.mes);
    scanf("%d", &p->nasc.ano);
}

void print_person (pessoa_t p){
    printf("%d - ", p.cod);
    printf("%s", p.nome);
    printf("\n");
    printf("Nascimento: %d/", p.nasc.dia);
    printf("%d/", p.nasc.mes);
    printf("%d", p.nasc.ano);
}

void main (){
    pessoa_t p;
    read_person(&p);
    print_person(p);
}