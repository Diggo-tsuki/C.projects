#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
//Constante:
#ifndef LIMITE_TOTAL
#define LIMITE_TOTAL 10//Limite de cada produto a ser comprado por pessoa;
#endif
////////////
typedef struct {
	char NOME[100];//Rogerio rodrigues;
	long long int CPF;//08723498742;
	int DDD;//62;
	long int TELEFONE;//992456678;
	char EMAIL[100];//Teste@gmail.com;
	int itens;//8 itens;
} cliente[100]; //Limite de 100 contatos;

//VARIAVEIS GLOBAIS:
cliente CLIENTE;
int clientes_cadastrados = 0;
//PROTOTIPOS DE FUNCOES;
void menu();
void infocliente(int X);
void alterar();
void cadastrar();
void listarclientes();
void excluir();
void consulta();
//////////////////////////
int main()
{
	menu();
	return 0;
}

void menu() {
	printf("\n========Virtual Calender========\n");
	printf("1 - Cadastrar cliente\n");
	printf("2 - Alterar dados do cliente\n");
	printf("3 - Consultar dados do cliente\n");
	printf("4 - Listar clientes cadastrados\n");
	printf("5 - Excluir cliente\n");
	printf("6 - SAIR DO SISTEMA\n");
	int escolha;
	scanf("%d", &escolha);
	getchar();
	switch(escolha) {
	case 1:
		cadastrar();
		break;

	case 2:
		alterar();
		break;

	case 3:
		consulta();
		break;

	case 4:
		listarclientes();
		break;

	case 5:
		excluir();
		break;

	case 6:
		printf("OBRIGADO POR TER VINDO!\n");
		sleep(1);
		printf("TENHA UM EXCELENTE DIA!\n");
		sleep(1);
		exit(0);
		break;

	default:
		printf("Opcao invalida!!!!\n");
		sleep(1);
		menu();
		break;
	}
}

void cadastrar() {
    long long int S;
    printf("Digite o Nome da pessoa a ser cadastrado(a): ");
	fgets(CLIENTE[clientes_cadastrados].NOME, 100, stdin);
	printf("Digite o CPF(APENAS NUMEROS): ");
	scanf("%lld", &S);
	if(clientes_cadastrados > 0){
	for(int i=0; i<clientes_cadastrados; i++){
	    if(S == CLIENTE[i].CPF){
	        printf("CPF ja cadastrado!!!\n");
	        printf("Digite outro!!!\n");
	        printf("Digite o CPF(APENAS NUMEROS): ");
	        scanf("%lld", &CLIENTE[clientes_cadastrados].CPF);
	        break;
	    }
	    else{
	        CLIENTE[clientes_cadastrados].CPF = S;
	    }
	}
	}
	else{
	  CLIENTE[clientes_cadastrados].CPF = S;
	}
	getchar();
	printf("Digite o email do cliente: ");
	fgets(CLIENTE[clientes_cadastrados].EMAIL, 100, stdin);
	printf("Digite o DDD: ");
	scanf("%d", &CLIENTE[clientes_cadastrados].DDD);
	printf("Digite o numero de telefone(ex: 998762789): ");
	scanf("%ld", &CLIENTE[clientes_cadastrados].TELEFONE);
	printf("Digite o limite de itens a ser comprados(0-10): ");
	scanf("%d", &CLIENTE[clientes_cadastrados].itens);
	while(CLIENTE[clientes_cadastrados].itens > 10) {
		if(CLIENTE[clientes_cadastrados].itens > LIMITE_TOTAL) {
			printf("\nValor total invalido, deve ser menor ou igual a 10!!: ");
			scanf("%d", &CLIENTE[clientes_cadastrados].itens);
		}
	}
	printf("\nCLIENTE CADASTRADO COM SUCESSO!!!\n");
	clientes_cadastrados++;
	sleep(2);
	menu();
}

void excluir(){
    if(clientes_cadastrados <= 0) {
		printf("NENHUM CLIENTE CADASTRADO!\n");
		sleep(2);
		menu();
	}
	else{
	printf("Digite o CPF do cliente a ser excluido!!\n");
	long long int TI;
	scanf("%lld", &TI);
	for(int i=0; i<clientes_cadastrados; i++){
	    if(CLIENTE[i].CPF == TI){
	        CLIENTE[i].CPF = 0;
	    }
	}
	printf("Contato excluido com sucesso!!!\n");
	sleep(1);
	menu();
	}
}

void alterar() {
	int i;
	bool R = true;
	if(clientes_cadastrados <= 0) {
		printf("NENHUM CLIENTE CADASTRADO!\n");
		sleep(2);
		menu();
	}
	else {
		long long int CEPEEFE;
		printf("Qual o CPF da pessoa que gostaria de alterar os dados? ");
		scanf("%lld", &CEPEEFE);
		getchar();
		for(i=0; i<clientes_cadastrados; i++) {
			if(CLIENTE[i].CPF == CEPEEFE) {
				char DECISAO;
				printf("Gostaria de alterar o nome(S/N)? ");
				scanf("%c", &DECISAO);
				getchar();
				if(DECISAO == 'S' || DECISAO == 's') {
					printf("Digite o novo nome do cliente: ");
					fgets(CLIENTE[i].NOME, 100, stdin);
					printf("ALTERACAO REALIZADA!!\n");
				}

				printf("Gostaria de alterar o EMAIL(S/N)? ");
				scanf("%c", &DECISAO);
				getchar();
				if(DECISAO == 'S' || DECISAO == 's') {
					printf("Digite o novo EMAIL do cliente: ");
					fgets(CLIENTE[i].EMAIL, 100, stdin);
					printf("ALTERACAO REALIZADA!!\n");
				}
				printf("Gostaria de alterar o DDD(S/N)? ");
				scanf("%c", &DECISAO);
				getchar();
				if(DECISAO == 'S' || DECISAO == 's') {
					printf("Digite o novo DDD do cliente: ");
					scanf("%d", &CLIENTE[i].DDD);
					getchar();
					printf("ALTERACAO REALIZADA!!\n");
				}
				printf("Gostaria de alterar o NUMERO DE TELEFONE(S/N)? ");
				scanf("%c", &DECISAO);
				getchar();
				if(DECISAO == 'S' || DECISAO == 's') {
					printf("Digite o novo NUMERO do cliente: ");
					scanf("%ld", &CLIENTE[i].TELEFONE);
					getchar();
					printf("ALTERACAO REALIZADA!!\n");
				}
				printf("Gostaria de alterar o Limite de compras(S/N)? ");
				scanf("%c", &DECISAO);
				getchar();
				if(DECISAO == 'S' || DECISAO == 's') {
					printf("Digite o novo Limite do cliente(0-10): ");
					scanf("%d", &CLIENTE[i].itens);
					getchar();
					while(CLIENTE[i].itens > 10) {
						if(CLIENTE[i].itens > LIMITE_TOTAL) {
							printf("\nValor total invalido, deve ser menor ou igual a 10!!: ");
							scanf("%d", &CLIENTE[i].itens);
						}
					}
				}
				printf("ALTERACAO REALIZADA!!\n");
				R = false;
			}
		}
		if(!R) {
			menu();
		}
		else {
			printf("Falha ao realizar alteracao!\n");
			printf("CPF invalido ou Inexistente!!\n");
			printf("Gostaria de tentar novamente(S/N)? ");
			char T;
			scanf("%c", &T);
			getchar();
			if(T == 'S' || T=='s') {
				alterar();
			}
			else {
				menu();
			}
		}
	}
}

void consulta() {
	long long int LOL;
	bool YH = true;
	if(clientes_cadastrados <= 0) {
		printf("NENHUM CLIENTE CADASTRADO!\n");
		sleep(2);
		menu();
	}
	else {
		printf("Digite o CPF a ser consultado: ");
		scanf("%lld", &LOL);
		getchar();
		for(int i=0; i<clientes_cadastrados; i++) {
			if(CLIENTE[i].CPF == LOL) {
				infocliente(i);
				YH = false;
			}
		}
		if(!YH) {
			menu();
		}
		else {
			printf("Contato nao encontrado!!\n");
			printf("CPF invalido ou Inexistente!\n");
			printf("Gostaria de tentar novamente(S/N)? ");
			char T;
			scanf("%c", &T);
			getchar();
			if(T == 'S' || T=='s') {
				alterar();
			}
			else {
				menu();
			}
		}
	}
}

void listarclientes() {
	if(clientes_cadastrados <= 0) {
		printf("NENHUM CLIENTE CADASTRADO!\n");
		sleep(2);
		menu();
	}
	else {
		for(int i=0; i<clientes_cadastrados; i++) {
			if(CLIENTE[i].CPF != 0){
			infocliente(i);
			printf("\n");
			}
		}
		menu();
	}
}

void infocliente(int X) {
	printf("NOME: %s\n", strtok(CLIENTE[X].NOME, "\n"));
	usleep(50000);
	printf("CPF: %lld\n", CLIENTE[X].CPF);
	usleep(50000);
	printf("EMAIL: %s\n", strtok(CLIENTE[X].EMAIL, "\n"));
	usleep(50000);
	printf("DDD: %d\n", CLIENTE[X].DDD);
	usleep(50000);
	printf("TELEFONE: %ld\n", CLIENTE[X].TELEFONE);
	usleep(50000);
	printf("LIMITE: %d\n", CLIENTE[X].itens);
	usleep(50000);
	sleep(1);
}
