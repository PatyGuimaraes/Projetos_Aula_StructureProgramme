//Elabore um algoritmo utilizando, obrigatoriamente, vetor e função, que:

//Realize o cadastro 100 produtos, contendo: código, nome, preço de compra, preço de venda, quantidade.

//Realize as seguintes ações: incluir, excluir, editar, pesquisar, realizar backup

//Projeto 1 - Vetor

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX 100

int leValidaCodigo();
void leValidaNomeProd(char nomeProd[]);
float leValidaPrecoCompra();
float leValidaPrecoVenda();

int menu();

void incluirProduto( int codProd[], char nomeProd[][25], float precoCompra[], float precoVenda[]);

void pesquisarProduto( int codProd[], char nomeProd[][25], float precoCompra[], float precoVenda[], int qtd);	

void imprimirProduto(int codProd[], char nomeProd[][25], float precoCompra[], float precoVenda[], int codBkp[],  char nomeBkp[][25], float compraBkp[], float vendaBkp[], int qtd, int back);

void editar(int codProd[], char nomeProd[][25], float precoCompra[], float precoVenda[]);

int backup(int codProd[],char nomeProd[][25], float precoCompra[], float precoVenda[], int codBkp[],  char nomeBkp[][25], float compraBkp[], float vendaBkp[], int qtd, int back);	

int excluir(int codProd[], char nomeProd[][25], float precoCompra[], float precoVenda[], int qtd);	
			 
int main (){
	setlocale(LC_ALL, "Portuguese");
	char nomeProd[MAX][25], nomeBkp[MAX][25];
	int codProd[MAX], codBkp[MAX];
	float precoCompra[MAX], precoVenda[MAX], compraBkp[MAX], vendaBkp[MAX];
	int qtd=0;
	int back;
	
	do{
		switch (menu()){
			case 1:
				incluirProduto(codProd, nomeProd, precoCompra, precoVenda);
				qtd++;
			break;
			case 2:
				pesquisarProduto(codProd, nomeProd, precoCompra, precoVenda, qtd);
				break;
			case 3:
				imprimirProduto(codProd, nomeProd, precoCompra, precoVenda, codBkp, nomeBkp, compraBkp, vendaBkp, qtd, back);
				break;
			case 4:
				editar(codProd, nomeProd, precoCompra, precoVenda);
				break;
			case 5:
				back = backup(codProd,nomeProd,precoCompra, precoVenda, codBkp, nomeBkp, compraBkp, vendaBkp, qtd, back);
				break;
			case 6:
				qtd = excluir(codProd,nomeProd,precoCompra, precoVenda, qtd);
				break;
			case 0:
				exit(0);
		}
	}while(1); 
	
	return 0;
}
/*-----------------------MENU---------------------*/
int menu(){
	int op;
	system("cls");
	do{
		puts("---Escolha uma opcao:---");
		puts("1 - Incluir dados dos produtos.");
		puts("2 - Pesquisar produto.");
		puts("3 - Imprimir produtos.");
		puts("4 - Editar");
		puts("5 - Realizar backup.");
		puts("6 - Excluir.");
		puts("0 - Sair.");
		scanf("%i", &op);
		fflush(stdin);
		if(op<1 || op>6){
			puts("Opção inválida");
		}
	}while(op<1 || op>6);
	return op;
}
/*--------------------VALIDAÇOES---------------------*/
int leValidaCodigo(int codigoProd[]){
	int cod;
	do{
		printf("Digite o codigo do produto (Entre 1 e 100): \n");
		scanf("%i", &cod);	
		if(cod<1 || cod>100){
			printf("Codigo inválido");
		}
	
	}while(cod<1 || cod>100);
	return cod;
}

void leValidaNomeProd(char nomeProd[]){
	do{
		puts("Digite o nome do produto:\n");
		fflush(stdin);
		gets(nomeProd);
		if(strcmp(nomeProd,"")==0){
			puts("Nome do produto é obrigatório.");
		}
	}while(strcmp(nomeProd,"")==0);

}

float leValidaPrecoCompra(){
	float precoCompra;
	do{
		printf("Digite o preco de compra R$:\n");
		scanf("%f", &precoCompra);
		if(precoCompra<0){
			printf("Preco de compra inválido.");
		}
	}while(precoCompra<0);
	return precoCompra;
}

float leValidaPrecoVenda(){
	float precoVenda;
	do{
		printf("Digite o preco de venda R$:\n");
		scanf("%f", &precoVenda);
		if(precoVenda<0){
			printf("Preco de venda inválido.");
		}
	}while(precoVenda<0);
	return precoVenda;
}

/*-------------------INCLUIR------------------------*/
void incluirProduto( int codProd[], char nomeProd[][25], float precoCompra[], float precoVenda[]){
	int i = 0;
	system("cls");
	for(i=0; i < MAX; i++){//utilizei o for porque a questão fala para cadastrar 100 produtos. Ou usaria do while caso fosse até 100 produtos.
		codProd[i] = leValidaCodigo(codProd);
		leValidaNomeProd(nomeProd[i]);
		precoCompra[i] = leValidaPrecoCompra();
		precoVenda[i] = leValidaPrecoVenda();
		printf("----Produto incluído com sucesso.----\n");
		printf("Código: %i - Produto: %s - Preço de Compra: R$ %.2f - Preço de Venda: R$ %.2f\n", codProd[i], nomeProd[i],
		precoCompra[i], precoVenda[i]);
	}
}
/*------------------PESQUISAR----------------------*/
void pesquisarProduto( int codProd[], char nomeProd[][25], float precoCompra[], float precoVenda[], int qtd){
	int codPesquisa, codRetorno, i;
	char continuar;
	system("cls");
	do {
		printf("Informe o codigo do produto? ");
		fflush(stdin);
		scanf("%i", &codPesquisa);
		for(i = 0; i < qtd; i++){
			if(codProd[i] == codPesquisa){
				printf("Código: %i \nProduto: %s  \nPreço de Compra: R$ %.2f \nPreço de Venda: R$ %.2f\n", codProd[i],
					nomeProd[i], precoCompra[i], precoVenda[i]);
					codRetorno++;
			}else if(codRetorno == 0){
				printf("Código não encontrado\n");
			}
		}
		printf("\nDigite 'S' para nova pesquisa: ");
		continuar = toupper (getche());	
	}while(continuar == 'S' || continuar == 's');
}
/*--------------------IMPRIMIR----------------------*/
void imprimirProduto(int codProd[], char nomeProd[][25], float precoCompra[], float precoVenda[], int codBkp[],  char nomeBkp[][25], float compraBkp[], float vendaBkp[], int qtd, int back){
	int i, opcao;
	system("cls");
	
	printf ("*** Imprimir ***\n");
	if (qtd == 0){
			printf("Lista vazia!\n");
	}else{
		printf("Qual lista quer imprimir?\n1. Original\t2. Backup\n");
		scanf("%d", &opcao);
		fflush(stdin);
		switch(opcao){
			case 1: 
			for (i=0;i<qtd;i++){
				printf("Código: %d\tNome: %s\t\tPreço de Compra: %.2f\t\tPreço de Venda: %.2f\n", codProd[i], nomeProd[i], precoCompra[i], precoVenda[i]);
			}
			break;
			case 2:
			for (i=0;i<qtd;i++){
				printf("Código: %d\tNome: %s\t\tPreço de Compra: %.2f\t\tPreço de Venda: %.2f\n", codBkp[i], nomeBkp[i], compraBkp[i], vendaBkp[i]);
			}
			break;
			default: printf("Codigo inválido!\n");
		}
	}	
/*	for(i = 0; i<qtd; i++){
		printf("=======================================================================================\n");
		printf("Código: %i \nProduto: %s  \nPreço de Compra: R$ %.2f \nPreço de Venda: R$ %.2f\n", codProd[i],
			nomeProd[i], precoCompra[i], precoVenda[i]);
		printf("\n=======================================================================================\n");
	}
	if(back == 0){
		printf("=======================================================================================\n");
		printf("Código: %i \nProduto: %s  \nPreço de Compra: R$ %.2f \nPreço de Venda: R$ %.2f\n", codBkp[i],
			nomeBkp[i], compraBkp[i], vendaBkp[i]);
		printf("\n=======================================================================================\n");
	}*/
	printf("\nTotal de itens cadastrados: %d\n\n", qtd);
	system("pause");
}
/*-------------------EDITAR-------------------*/
void editar(int codProd[], char nomeProd[][25], float precoCompra[], float precoVenda[]){
	int codPesquisa, i;
	char aux;
	do{
		printf("Informe o codigo do produto que deseja editar? ");
		scanf("%i", &codPesquisa);
		fflush(stdin);
		for(i = 0; i < MAX; i++){
			if(codProd[i] == codPesquisa){
				codProd[i] = leValidaCodigo(codProd);
				do{
					puts("Digite o nome do produto:\n");
					fflush(stdin);
					gets(nomeProd[i]);
				if(strcmp(nomeProd[i],"")==0){
						puts("Nome do produto é obrigatório.");
					}
				}while(strcmp(nomeProd[i],"")==0);
				precoCompra[i] = leValidaPrecoCompra();
				precoVenda[i] =  leValidaPrecoVenda();
			}
		}
			puts("Deseja editar outro produto [S|N] ? ");
			scanf("%c", &aux);
			fflush(stdin);
	}while (aux == 'S' || aux == 's');
}
/*--------------------BACKUP-----------------*/
int backup(int codProd[], char nomeProd[][25], float precoCompra[], float precoVenda[], int codBkp[],  char nomeBkp[][25], float compraBkp[], float vendaBkp[], int qtd, int back){
	int i;
	for (i = 0; i < qtd; i++){
		codBkp[i] = codProd[i];
		strcpy(nomeBkp[i], nomeProd[i]);
		compraBkp[i] = precoCompra[i];
		vendaBkp[i] = precoVenda[i];
		i++;
	}
	if(i == 0){
		printf("Backup nao concluido");
		return back = 0;
		system("pause");
	}
	else{
		printf("Backup concluido");
		return back = 1;
		system("pause");
	}
}
/*-----------------EXCLUIR------------------*/
int excluir(int codProd[], char nomeProd[][25], float precoCompra[], float precoVenda[], int qtd){
	int i, j, codPesquisa, vazio;
	char aux;
	
	do{
		printf("Informe o codigo do produto que deseja excluir: ");
		scanf("%i", &codPesquisa);
		fflush(stdin);
		for(i = 0; i < MAX; i++){
			if(codProd[i] == codPesquisa){
					for(j=i; j < MAX; j++){
						codProd[j] = codProd[j+1];
						strcpy(nomeProd[j], nomeProd[j+1]);
						precoCompra[j] = precoCompra[j+1];
						precoVenda[j] = precoVenda[j+1];
					}
			}else vazio++;
		qtd--;
		}
		if (vazio==qtd)
			printf ("Esse código não foi cadastrado. Impossível excluir!\n");	
		
		puts("Deseja excluir outro produto [S|N]: ");
		scanf("%c", &aux);
		fflush(stdin);
	}while(aux == 's' || aux == 'S');
	return qtd;
}
