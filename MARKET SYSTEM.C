#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
	int codigo;
	char nome[30];
	float preco;
} Produto;

Produto prod;

typedef struct {
	Produto produto;
	int quantidade;
} Carrinho;

void infoproduto(Produto i);
void menu();
void cadastrar();
void comprarproduto();
void listarcadastrados();
void visualizarcarrinho();
Produto pegarprodutoporcodigo(int codigo);
int temnocarrinho(int codigo);
void fecharpedido();

static int contador = 0;
static int contcarrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];

int main()
{
	menu();
	return 0;
}

void infoproduto(Produto i) {
	printf("Codigo do produto: %d\nNome do produto: %s\nValor do produto: %.2f\n", i.codigo, strtok(i.nome, "\n"), i.preco);
}

void menu() {
	printf("\n======================================\n");
	printf("==========LOJINHO DO TADEU============\n");
	printf("========QUEM N COMPROU SE FU*=========\n");
	printf("======================================\n");
	printf("\nSELECIONE UMA OPCAO A BAIXO:\n");
	printf("1 - CADASTRAR PRODUTO!\n");
	printf("2 - LISTAR PRODUTO!\n");
	printf("3 - COMPRAR PRODUTO!\n");
	printf("4 - VISUALIZAR CARRINHO!\n");
	printf("5 - FECHAR PEDIDO!\n");
	printf("6 - SAIR DO SISTEMA!\n");
	int escolha;
	scanf("%d", &escolha);
	getchar();

	switch (escolha) {
	case 1:
		cadastrar();
		break;

	case 2:
		listarcadastrados();
		break;

	case 3:
		comprarproduto();
		break;

	case 4:
		visualizarcarrinho();
		break;

	case 5:
		fecharpedido();
		break;

	case 6:
		printf("VOLTE SEMPRE!!!\n");
		sleep(2);
		exit(0);
		break;

	default:
		printf("Opcao invalida!!\n");
		sleep(2);
		menu();
		break;
	}
}

void cadastrar() {
	printf("\nCadastro de produto\n");
	printf("===================\n");
	printf("INFORME O NOME DO PRODUTO: ");
	fgets(produtos[contador].nome, 30, stdin);
	printf("INFORME O PRECO DO PRODUTO: ");
	scanf("%f", &produtos[contador].preco);
	printf("O produto %s foi cadastrado com sucesso!!\n", strtok(produtos[contador].nome, "\n"));
	produtos[contador].codigo = contador + 1;
	contador++;
	menu();
}

void listarcadastrados() {
	if (contador > 0) {
		printf("\nPRODUTOS REGISTRADOS!!!\n");
		for (int i = 0; i < contador; i++) {
			infoproduto(produtos[i]);
			printf("==========================\n");
			sleep(1);
		}
		menu();
	} else {
		printf("NENHUM PRODUTO CADASTRADO!!!\n");
		sleep(2);
		menu();
	}
}

void comprarproduto() {
	if (contador > 0) {
		printf("\nInforme o codigo do produto que gostaria de comprar!!\n");
		printf("======PRODUTOS DISPONIVEIS======\n");
		for (int i = 0; i < contador; i++) {
			infoproduto(produtos[i]);
			printf("================================\n");
			sleep(1);
		}
		int codigo;
		scanf("%d", &codigo);
		getchar();
		int tem = 0;
		int i;
		for (i = 0; i < contador; i++) {
			if (produtos[i].codigo == codigo) {
				tem = 1;
				if (contcarrinho > 0) {
					int cod = temnocarrinho(codigo);
					if (cod != -1) {
						carrinho[cod].quantidade++;
						printf("Quantidade do produto %s foi aumentada para %d\n", strtok(carrinho[cod].produto.nome, "\n"), carrinho[cod].quantidade);
						sleep(2);
						menu();
					} else {
						Produto p = pegarprodutoporcodigo(codigo);
						carrinho[contcarrinho].produto = p;
						carrinho[contcarrinho].quantidade = 1;
						contcarrinho++;
						printf("O produto %s, foi adicionado ao carrinho!!!\n", strtok(p.nome, "\n"));
						sleep(2);
						menu();
					}
				} else {
					Produto p = pegarprodutoporcodigo(codigo);
					carrinho[contcarrinho].produto = p;
					carrinho[contcarrinho].quantidade = 1;
					contcarrinho++;
					printf("O produto %s, foi adicionado ao carrinho!!!\n", strtok(p.nome, "\n"));
					sleep(2);
					menu();
				}
			}
		}
		if (tem < 1) {
			printf("Nao foi encontrado o produto com o codigo %d.\n", codigo);
			sleep(2);
			menu();
		}
	} else {
		printf("Nenhum produto a venda!!\n");
		sleep(2);
		menu();
	}
}

void visualizarcarrinho() {
	if (contcarrinho > 0) {
		printf("\nPRODUTOS NO CARRINHO!!!\n");
		printf("==========================\n");
		for (int i = 0; i < contcarrinho; i++) {
			infoproduto(carrinho[i].produto);
			printf("Quantidade: %d\n", carrinho[i].quantidade);
			printf("==========================\n");
			sleep(1);
		}
		menu();
	} else {
		printf("NENHUM PRODUTO NO CARRINHO!!!\n");
		sleep(2);
		menu();
	}
}

Produto pegarprodutoporcodigo(int codigo) {
	Produto p;
	for (int i = 0; i < contador; i++) {
		if (produtos[i].codigo == codigo) {
			p = produtos[i];
		}
	}
	return p;
}

int temnocarrinho(int codigo) {
	for (int i = 0; i < contcarrinho; i++) {
		if (carrinho[i].produto.codigo == codigo) {
			return i;
		}
	}
	return -1;
}

void fecharpedido() {
	if (contcarrinho < 1) {
		printf("\nVoce nao tem nenhum produto no carrinho!!\n");
		sleep(2);
		menu();
	} else {
		float TT = 0.0;
		printf("\nProdutos do carrinho!\n");
		printf("==========================\n");
		for (int i = 0; i < contcarrinho; i++) {
			TT += carrinho[i].produto.preco * carrinho[i].quantidade;
			infoproduto(carrinho[i].produto);
			printf("Quantidade: %d\n", carrinho[i].quantidade);
			printf("==========================\n");
			sleep(1);
		}
		printf("Seu valor total a pagar fica: %.2f\n", TT);
		printf("Fale com um de nossos vendedores para realizar seu pagamento e retirar o(s) produto(s)!!!!\n\n");
		contcarrinho = 0;
		printf("OBRIGADO PELA PREFERENCIA!!!!\n");
		sleep(5);
		menu();
	}
}
