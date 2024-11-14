#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//PROJETO GAME!!!!!

typedef struct {
	int dificuldade;
	int valor1;
	int valor2;
	int operacao;
	int resultado;
} Calcular;

void jogar();

int som(int resposta);

int sub(int resposta);

int mult(int resposta);

int score=0;

Calcular calc;

int main() {
	srand(time(NULL));
	jogar();
	return 0;
}

void jogar() {
	printf("Escolha a dificuldade (1-facil, 2-medio, 3-dificil, 4-insano): ");
	scanf("%d", &calc.dificuldade);
	calc.operacao = rand() % 3;
	printf("\n");
	if(calc.dificuldade == 1){
	    //facil;
	 calc.valor1 = rand()%11;
	 calc.valor2 = rand()%11;
	}
	else if(calc.dificuldade == 2){
	    //medio;
	 calc.valor1 = rand()%101;
	 calc.valor2 = rand()%101;
	}
	else if(calc.dificuldade == 3){
	    //dificil;
	 calc.valor1 = rand()%1001;
	 calc.valor2 = rand()%1001;
	}
	else if(calc.dificuldade == 4){
	    //insano;
	 calc.valor1 = rand()%10001;
	 calc.valor2 = rand()%10001;
	}
	else{
	 //nivel secreto!!!!!!;
	 calc.valor1 = rand()%100001;
	 calc.valor2 = rand()%100001;
	}
	int resposta;
	printf("Informe o resultado da seguinte operacao:\n");
	if(calc.operacao == 0){
	    printf("%d + %d = ?\n", calc.valor1,calc.valor2);
        printf("RESPOSTA: ");
        scanf("%d", &resposta);
	    if(som(resposta)){
	        score++;
	        printf("Voce tem %d ponto(s)\n", score);
	    }
	}
	else if(calc.operacao == 1){
	    printf("%d - %d = ?\n", calc.valor1,calc.valor2);
        printf("RESPOSTA: ");
        scanf("%d", &resposta);
	    if(sub(resposta)){
	        score++;
	        printf("Voce tem %d ponto(s)\n", score);
	    }
	}
	else if(calc.operacao == 2){
	    printf("%d * %d = ?\n", calc.valor1,calc.valor2);
        printf("RESPOSTA: ");
        scanf("%d", &resposta);
	    if(mult(resposta)){
	        score++;
	        printf("Voce tem %d ponto(s)\n", score);
	    }
	}
	else{
	    printf("A operacao %d nao é reconhecida!\n", calc.operacao);
	}
	int continuar = 1;
	printf("Gostaria de jogar novamente (1-sim, 0-nao)? ");
    scanf("%d", &continuar);
    printf("\n");
    if(continuar == 1){
        jogar();
    }
    else{
        printf("Jogo finalizado com <%d> pontos!!\n", score);
        printf("ATÉ A PROXIMA!!!");
        exit(0);
    }
}

int som(int resposta) {
	calc.resultado = calc.valor1 + calc.valor2;
	int certo=0;
	if(resposta == calc.resultado) {
		printf("Resposta correta!!\n");
		certo=1;
	}
	else {
		printf("Resposta errada!!\n");
	}
	printf("%d + %d = %d!!\n", calc.valor1, calc.valor2, calc.resultado);
	return certo;
}

int sub(int resposta) {
	int resultado = calc.valor1 - calc.valor2;
	calc.resultado = resultado;
	int certo=0;
	if(resposta == calc.resultado) {
		printf("Resposta correta!!\n");
		certo=1;
	}
	else {
		printf("Resposta errada!!\n");
	}
	printf("%d - %d = %d!!\n", calc.valor1, calc.valor2, calc.resultado);
	return certo;
}

int mult(int resposta) {
	int resultado = calc.valor1 * calc.valor2;
	calc.resultado = resultado;
	int certo=0;
	if(resposta == calc.resultado) {
		printf("Resposta correta!!\n");
		certo=1;
	}
	else {
		printf("Resposta errada!!\n");
	}
	printf("%d * %d = %d!!\n", calc.valor1, calc.valor2, calc.resultado);
	return certo;
}
