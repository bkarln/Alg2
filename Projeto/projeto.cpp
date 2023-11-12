#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_CPF 12

typedef struct {
    char nome[50];
    char cpf[15];
    int idade = 0;
} Pessoa;

typedef struct {
    Pessoa cliente;
    int numero = 0;
    double saldo = 0;
} ContaBancaria;

void inserirPessoaConta(ContaBancaria *contas, int *numContas) {
	contas[*numContas].cliente.cpf[0] = {'\0'};
	
    printf("Digite o nome: ");
    scanf("%s", contas[*numContas].cliente.nome);
    
	while (contas[*numContas].cliente.cpf[0] == '\0'){
        printf("Digite o CPF: ");
        scanf("%s", contas[*numContas].cliente.cpf, TAMANHO_CPF, stdin);
        size_t len = strlen(contas[*numContas].cliente.cpf);
        if (len > 0 && contas[*numContas].cliente.cpf[len - 1] == '\n') {
            contas[*numContas].cliente.cpf[len - 1] = '\0';
        }
    } ;
		
	do 
	{
		printf("Digite a idade(maior de 18 anos): ");
		scanf("%d", &contas[*numContas].cliente.idade);
	} while (contas[*numContas].cliente.idade == 0 || contas[*numContas].cliente.idade < 18);
			
	do 
	{
		printf("Digite o numero da conta: ");
		scanf("%d", &contas[*numContas].numero);
	} while (contas[*numContas].numero == 0);
			
			
	printf("Digite o saldo inicial: ");
    scanf("%lf", &contas[*numContas].saldo);

    (*numContas)++;
}

void salvarContas(ContaBancaria *contas, int numContas) {
    FILE *arquivo = fopen("contas.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    fprintf(arquivo, "%s %s %d %d %.2lf\n", contas[numContas - 1].cliente.nome, contas[numContas - 1].cliente.cpf,
            contas[numContas - 1].cliente.idade, contas[numContas - 1].numero, contas[numContas - 1].saldo);

    fclose(arquivo);

    printf("Conta salva com sucesso!\n");
}

void extratoBancario(ContaBancaria *contas, int numContas, int numeroConta) {
    int contaEncontrada = 0;
	int i = 0;
	
    for (i = 0; i < numContas; i++) {
        if (contas[i].numero == numeroConta) {
            printf("Extrato Bancario para a Conta %d:\n", numeroConta);
            printf("Nome: %s\n", contas[i].cliente.nome);
            printf("CPF: %s\n", contas[i].cliente.cpf);
            printf("Idade: %d\n", contas[i].cliente.idade);
            printf("Saldo Atual: %.2lf\n", contas[i].saldo);
            contaEncontrada = 1;
            break;
        }
    }

    if (!contaEncontrada) {
        printf("Conta nao encontrada. Tente novamente.\n");
    }
}

int main() {
    int opcao;
    ContaBancaria *contas = NULL;
    int numContas = 0;
    int numeroContaSelecionada = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir Pessoa e Conta\n");
        printf("2. Extrato Bancario\n");
        printf("0. Sair\n");

        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                contas = (ContaBancaria *)realloc(contas, (numContas + 1) * sizeof(ContaBancaria));
                if (contas == NULL) {
                    printf("Erro ao alocar memoria.\n");
                    exit(1);
                }
                inserirPessoaConta(contas, &numContas);
                salvarContas(contas, numContas);
                break;

            case 2:
                if (numContas > 0) {
                    printf("Digite o numero da conta para ver o extrato: ");
                    scanf("%d", &numeroContaSelecionada);
                    extratoBancario(contas, numContas, numeroContaSelecionada);
                } else {
                    printf("Nenhuma conta cadastrada. Por favor, crie uma conta primeiro.\n");
                }
                break;

            case 0:
                free(contas);
                printf("Programa finalizado.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

