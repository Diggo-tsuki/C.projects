#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// PROJETO BANCO!!!!!

typedef struct {
	int codigo;
	char nome[50];
	char cpf[20];
	char email[50];
	char data[30];
	char cadastrodata[20];
} CLIENTE;

typedef struct {
	int numero;
	CLIENTE cliente;
	float saldo;
	float limite;
	float saldoTT; // SALDO + LIMITE;
} CONTA;

CLIENTE cliente;
CONTA contas[50];
int contacontas = 0;
int contacliente = 0;

void menu();
void infocliente(CLIENTE cliente);
void infoconta(CONTA conta);
void criarconta();
void efetuar_saque();
void efetuar_deposito();
void efetuar_trasferencia();
void listar_contas();
float atualiza_saldoTT(CONTA conta);
CONTA BuscarContaPorNumero(int numero);
void sacar(CONTA conta, float valor);
void depositar(CONTA conta, float valor);
void trasferir(CONTA origem, CONTA destino, float valor);

int main() {
	menu();
	return 0;
}

void menu() {
	printf("\n======================================\n");
	printf("==========BANCO DO PORTUGA============\n");
	printf("========ROUBANDO SEU OURO DNV=========\n");
	printf("======================================\n");
	printf("\nSELECIONE UMA OPCAO A BAIXO:\n");
	printf("1 - CRIAR CONTA!\n");
	printf("2 - EFETUAR SAQUE\n");
	printf("3 - EFETUAR DEPOSITO!\n");
	printf("4 - EFETUAR TRASFERENCIA!\n");
	printf("5 - LISTAR CONTAS!\n");
	printf("6 - SAIR DO SISTEMA!\n");
	int escolha;
	scanf("%d", &escolha);
	getchar();

	switch(escolha) {
	case 1:
		criarconta();
		break;

	case 2:
		efetuar_saque();
		break;

	case 3:
		efetuar_deposito();
		break;

	case 4:
		efetuar_trasferencia();
		break;

	case 5:
		listar_contas();
		break;

	case 6:
		printf("OBRIGADO POR VIR!!!\nVOLTE SEMPRE!!!\n");
		sleep(2);
		exit(0);

	default:
		printf("OPCAO INVALIDA!!!\n");
		sleep(2);
		menu();
		break;
	}
}

void infocliente(CLIENTE cliente) {
	printf("CODIGO: %d\nNOME: %s\nDATA DE NASCIMENTO: %s\nDATA DE CADASTRO: %s\n", cliente.codigo, strtok(cliente.nome, "\n"), strtok(cliente.data, "\n"), strtok(cliente.cadastrodata, "\n"));
	sleep(2);
}

void infoconta(CONTA conta) {
	printf("NUMERO DA CONTA: %d\nCLIENTE: %s\nDATA DE NASCIMENTO: %s\nDATA DE CADASTRO: %s\nSALDO TOTAL: %.2f\n", conta.numero, strtok(conta.cliente.nome, "\n"), strtok(conta.cliente.data, "\n"), strtok(conta.cliente.cadastrodata, "\n"), conta.saldoTT);
	sleep(2);
}

void criarconta() {
	CLIENTE cliente;
	char dia[100];//06;
	char mes[100];//08;
	char ano[100];//2020;
	char datacadastro[20];
	time_t t = time(NULL);
	struct tm TM = *localtime(&t);
	// DIA;
	if(TM.tm_mday < 10) {
		sprintf(dia, "0%d", TM.tm_mday);
	}
	else {
		sprintf(dia, "%d", TM.tm_mday);
	}
	// MES;
	if((TM.tm_mon + 1) < 10) {
		sprintf(mes, "0%d", TM.tm_mon + 1);
	}
	else {
		sprintf(mes, "%d", TM.tm_mon + 1);
	}
	// ANO;
	sprintf(ano, "%d", TM.tm_year + 1900);

	strcpy(datacadastro, "");
	strcat(datacadastro, dia);
	strcat(datacadastro, "/");
	strcat(datacadastro, mes);
	strcat(datacadastro, "/");
	strcat(datacadastro, ano);
	strcat(datacadastro, "\0");
	strcpy(cliente.cadastrodata, datacadastro);

	//Criar cliente;
	printf("Informe os dados do cliente:\n");
	cliente.codigo = contacliente + 1;
	printf("NOME: ");
	fgets(cliente.nome,50,stdin);
	printf("EMAIL: ");
	fgets(cliente.email,50,stdin);
	printf("CPF: ");
	fgets(cliente.cpf,20,stdin);
	printf("DATA DE NASCIMENTO: ");
	fgets(cliente.data,30,stdin);
	contacliente++;

	//Criar conta;
	contas[contacontas].numero = contacontas + 1;
	contas[contacontas].cliente = cliente;
	contas[contacontas].saldo = 0.0;
	contas[contacontas].limite = 0.0;
	contas[contacontas].saldoTT = atualiza_saldoTT(contas[contacontas]);

	printf("CONTA CRIADA COM SUCESSO!!\n");
	printf("DADOS DA CONTA CRIADA:\n");
	sleep(2);
	infoconta(contas[contacontas]);
	contacontas++;
	sleep(4);
	menu();
}

void efetuar_saque() {
	int numero;
	if(contacontas > 0) {
		printf("Informe o numero da conta: ");
		scanf("%d", &numero);
		getchar();
		CONTA conta = BuscarContaPorNumero(numero);
		if(conta.numero == numero) {
			float valor;
			printf("Informe o valor do saque: ");
			scanf("%f", &valor);
			sacar(conta, valor);
			sleep(2);
			menu();
		}
		else {
			printf("Nao foi encontrado uma conta com numero %d", numero);
			sleep(2);
			menu();
		}
	}
	else {
		printf("NENHUMA CONTA CRIADA PARA SAQUE!!\n");
		sleep(2);
		menu();
	}
}

void efetuar_deposito() {
	int numero;
	if(contacontas > 0) {
		printf("Informe o numero da conta: ");
		scanf("%d", &numero);
		getchar();
		CONTA conta = BuscarContaPorNumero(numero);
		if(conta.numero == numero) {
			float valor;
			printf("Informe o valor do deposito: ");
			scanf("%f", &valor);
			depositar(conta, valor);
			sleep(2);
			menu();
		}
		else {
			printf("Nao foi encontrado uma conta com numero %d", numero);
			sleep(2);
			menu();
		}
	}
	else {
		printf("NENHUMA CONTA CRIADA PARA DEPOSITO!!\n");
		sleep(2);
		menu();
	}
}

void efetuar_trasferencia() {
	if(contacontas > 0) {
		int norigem,ndestino;
		printf("Informe o numero da sua conta: ");
		scanf("%d", &norigem);
		getchar();
		CONTA ORIG = BuscarContaPorNumero(norigem);
		if(ORIG.numero == norigem) {
			printf("Informe o numero da conta destino: ");
			scanf("%d", &ndestino);
			getchar();
			CONTA DESTI = BuscarContaPorNumero(ndestino);
			if(DESTI.numero == ndestino) {
				float valor;
				printf("Informe o valor da trasferencia: ");
				scanf("%f", &valor);
				getchar();
				trasferir(ORIG, DESTI, valor);
				menu();
			}
			else {
				printf("A conta destino com numero %d nao foi encontrada!\n", ndestino);
				menu();
			}
		}
		else {
			printf("A conta com numero %d nao foi encontrada", norigem);
			menu();
		}
	}
	else {
		printf("NENHUMA CONTA CRIADA PARA TRASFERENCIA!!\n");
		sleep(2);
		menu();
	}
}

void listar_contas() {
	if(contacontas > 0) {
		for(int i=0; i<contacontas; i++) {
			infoconta(contas[i]);
			printf("\n");
			sleep(2);
		}
		menu();
	}
	else {
		printf("Nao existem contas cadastradas ainda!!!\n");
		sleep(2);
		menu();
	}
}

float atualiza_saldoTT(CONTA conta) {
	return conta.saldo + conta.limite;
}

CONTA BuscarContaPorNumero(int numero) {
	CONTA C;
	if(contacontas > 0) {
		for(int i=0; i<contacontas; i++) {
			if(contas[i].numero == numero) {
				C = contas[i];
			}
		}
	}
	return C;
}

void sacar(CONTA conta, float valor) {
	if(valor > 0 && conta.saldoTT >= valor) {
		for(int i=0; i<contacontas; i++) {
			if(contas[i].numero == conta.numero) {
				if(contas[i].saldo >= valor) {
					contas[i].saldo -= valor;
					contas[i].saldoTT = atualiza_saldoTT(contas[i]);
					printf("SAQUE EFETUADO COM SUCESSO!!!!\n");
					sleep(2);
				}
				else {
					float restante = contas[i].saldo - valor;
					contas[i].limite = contas[i].limite + restante;//PARA QUE SEJA SUBTRAIDO O RESTANTE DO LIMITE, POIS RESTANTE C	 <0;
					contas[i].saldo = 0.0;
					contas[i].saldoTT == atualiza_saldoTT(contas[i]);
					printf("SAQUE EFETUADO COM SUCESSO!!!!\nOBS: Valor retirado do limite\n");
					sleep(2);
				}
			}
		}
	}
	else {
		printf("SAQUE NAO REALIZADO!!\nTENTE NOVAMENTE!!!\n");
		sleep(2);
	}
}

void depositar(CONTA conta, float valor) {
	if(valor > 0) {
		for(int i=0; i<contacontas; i++) {
			if(contas[i].numero == conta.numero) {
				contas[i].saldo+=valor;
				contas[i].saldoTT = atualiza_saldoTT(contas[i]);
				printf("DEPOSITO REALIZADO COM SUCESSO\n");
				sleep(2);
			}
		}
	}
	else {
		printf("ERRO AO REALIZAR O DEPOSITO!!!\nTENTE NOVAMENTE!!!\n");
		sleep(2);
	}
}

void trasferir(CONTA origem, CONTA destino, float valor) {
	if(valor > 0 && origem.saldoTT >= valor) {
		for(int ori=0; ori<contacontas; ori++) {
			if(contas[ori].numero == origem.numero) {
				for(int des=0; des<contacontas; des++) {
					if(contas[des].numero == destino.numero) {
						if(contas[ori].saldo >= valor) {
							contas[ori].saldo = contas[ori].saldo - valor;
							contas[des].saldo = contas[des].saldo + valor;
							contas[ori].saldoTT = atualiza_saldoTT(contas[ori]);
							contas[des].saldoTT = atualiza_saldoTT(contas[des]);
							printf("TRASFERENCIA REALIZADA COM SUCESSO!!!\n");
							sleep(2);
						}
						else {
							float restente = contas[ori].saldo - valor;
							contas[ori].limite = contas[ori].limite + restente;//PARA QUE SEJA SUBTRAIDO O RESTANTE DO LIMITE, POIS RESTANTE C	 <0;
							contas[ori].saldo = 0.0;
							contas[des].saldo = contas[des].saldo + valor;
							contas[ori].saldoTT = atualiza_saldoTT(contas[ori]);
							contas[des].saldoTT = atualiza_saldoTT(contas[des]);
							printf("TRASFERENCIA REALIZADA COM SUCESSO!!!\nOBS: Valor retirado do limite...\n");
							sleep(2);
						}
					}
				}
			}
		}
	}
	else {
		printf("ERRO AO REALIZAR A TRANSFERENCIA!!!\nTENTE NOVAMENTE!!!\n");
		sleep(2);
	}
}
