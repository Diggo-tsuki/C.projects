#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// PROJETO GAME!!!!!

typedef struct {
	unsigned long long int dificuldade;
	unsigned long long int valor1;
	unsigned long long int valor2;
	unsigned long long int operacao;
	unsigned long long int resultado;
} Calcular;

void jogar();

unsigned long long int som(unsigned long long int resposta);

unsigned long long int sub(unsigned long long int resposta);

unsigned long long int mult(unsigned long long int resposta);

int score = 0;

Calcular calc;

int main() {
	srand(time(NULL));
	jogar();
	return 0;
}

void jogar() {
	printf("Escolha a dificuldade (1-facil, 2-medio, 3-dificil, 4-insano): ");
	scanf("%lld", &calc.dificuldade);
	calc.operacao = rand() % 3;
	printf("\n");

	if (calc.dificuldade == 1) {
		calc.valor1 = rand() % 11;
		calc.valor2 = rand() % 11;
	} else if (calc.dificuldade == 2) {
		calc.valor1 = rand() % 101;
		calc.valor2 = rand() % 101;
	} else if (calc.dificuldade == 3) {
		calc.valor1 = rand() % 1001;
		calc.valor2 = rand() % 1001;
	} else if (calc.dificuldade == 4) {
		calc.valor1 = rand() % 10001;
		calc.valor2 = rand() % 10001;
	} else {
		calc.valor1 = rand() % 100001;
		calc.valor2 = rand() % 100001;
	}

	unsigned long long int resposta;
	printf("Informe o resultado da seguinte operacao:\n");
	if (calc.operacao == 0) {
		printf("%lld + %lld = ?\n", calc.valor1, calc.valor2);
		printf("RESPOSTA: ");
		scanf("%lld", &resposta);
		if (som(resposta)) {
			score++;
			printf("Voce tem %d ponto(s)\n", score);
		}
	} else if (calc.operacao == 1) {
		printf("%lld - %lld = ?\n", calc.valor1, calc.valor2);
		printf("RESPOSTA: ");
		scanf("%lld", &resposta);
		if (sub(resposta)) {
			score++;
			printf("Voce tem %d ponto(s)\n", score);
		}
	} else if (calc.operacao == 2) {
		printf("%lld * %lld = ?\n", calc.valor1, calc.valor2);
		printf("RESPOSTA: ");
		scanf("%lld", &resposta);
		if (mult(resposta)) {
			score++;
			printf("Voce tem %d ponto(s)\n", score);
		}
	} else {
		printf("A operacao %lld nao é reconhecida!\n", calc.operacao);
	}

	int continuar = 1;
	printf("Gostaria de jogar novamente (1-sim, 0-nao)? ");
	scanf("%d", &continuar);
	printf("\n");

	if (continuar == 1) {
		jogar();
	} else {
		printf("Jogo finalizado com <%d> pontos!!\n", score);
		printf("ATÉ A PROXIMA!!!");
		exit(0);
	}
}

unsigned long long int som(unsigned long long int resposta) {
	calc.resultado = calc.valor1 + calc.valor2;
	if (resposta == calc.resultado) {
		printf("\nResposta correta!!\n");
		return 1;
	} else {
		printf("\nResposta errada!!\n");
		printf("%lld + %lld = %lld!!\n", calc.valor1, calc.valor2, calc.resultado);
		return 0;
	}
}

unsigned long long int sub(unsigned long long int resposta) {
	calc.resultado = calc.valor1 - calc.valor2;
	if (resposta == calc.resultado) {
		printf("\nResposta correta!!\n");
		return 1;
	} else {
		printf("\nResposta errada!!\n");
		printf("%lld - %lld = %lld!!\n", calc.valor1, calc.valor2, calc.resultado);
		return 0;
	}
}

unsigned long long int mult(unsigned long long int resposta) {
	calc.resultado = calc.valor1 * calc.valor2;
	if (resposta == calc.resultado) {
		printf("\nResposta correta!!\n");
		return 1;
	} else {
		printf("\nResposta errada!!\n");
		printf("%lld * %lld = %lld!!\n", calc.valor1, calc.valor2, calc.resultado);
		return 0;
	}
}
