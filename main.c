#include <stdio.h>
#include <stdlib.h>

/* 
1- Reescreva o programa do caixa eletronico utilizando ponteiro
 de funções.
faça um algoritmo que simule o funcionamento de um caixa eletrônico, 
onde será apresentado uma lista de operações:
1-Saldo
2-Saque
3-Deposito
Ao iniciar o programa determine um valor inicial para a variável saldo 
(utilize um ponteiro para manter o valor do saldo), 
se o cliente escolher a opção 1 mostre o valor do saldo, 
caso escolha o valor 2 leia o valor a ser sacado e verifique se existe
 saldo suficiente, 
 se o saldo for maior ou igual , deduza da variável saldo o valor 
 solicitado, 
 caso não haja saldo suficiente mostre a mensagem 
 “Saldo Insuficiente”, 
 caso a opção 3 seja escolhida adicione o valor 
 informado de deposito ao saldo. 
 Implemente um laço faça enquanto que verifique 
 se o usuário deseja continuar, 
 caso a variável coletada for igual 1 reinicie o laço, 
 mantendo o valor do saldo.
 */
void saldo(float *saldoAtual);
void saque(float *saldoAtual);
void deposito(float *saldoAtual);


int main(int argc, char *argv[]) {
	float s=100;
	float *p;
	int op;
	p = &s;
	void(*listaF[4])(float *saldoAtual) = {NULL};  
    listaF[1] = &saldo;
    listaF[2] = &saque;
    listaF[3] = &deposito;
    
	void(*ptrF)(float *saldoAtual) = NULL;  
 	
	
	do{
		printf("\nInforme a op. a ser realizada\n1-saldo\n2-saque\n3-deposito\n4-sair\n");
		scanf("%i", &op);	
		if(op>=1 && op<=3){
		    ptrF  = listaF[op];
 	        ptrF(p);
		}
	}while(op<4);
	
	
	return 0;
}

void saldo(float *saldoAtual){
	printf("\nO saldo atual = %.2f", *saldoAtual);
}
void saque(float *saldoAtual){
	float valor;
	printf("\nInforme o valor a ser sacado:");
	scanf("%f", &valor);
	if(valor > *saldoAtual){
		printf("\nSaldo insuficiente !!");	
	} else {
		*saldoAtual = *saldoAtual - valor;
		printf("\nSaque realizado com sucesso !");  
	}
}
void deposito(float *saldoAtual){
	float valor;
	printf("\nInforme o valor a ser depositado:");
	scanf("%f", &valor);
	*saldoAtual = *saldoAtual + valor;
	printf("\ndeposito realizado com sucesso !");  
}

