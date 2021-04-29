//Elabore um algoritmo utilizando, obrigatoriamente, vetor e função, que:

//Realize o cadastro 100 produtos, contendo: código, nome, preço de compra, preço de venda, quantidade.

//Realize as seguintes ações: incluir, excluir, editar, pesquisar, realizar backup

//Projeto 2 - Struct

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX 2

typedef struct cadastro{
	int codProd;
	char nomeProd[25];
	float precoCompra;
	float precoVenda;
	int codBkp;
	char nomeBkp[25];
	float compraBkp;
	float vendaBkp;
	
}mercado;

int menu();
void incluirProduto( mercado produtos[]);
void pesquisarProduto(mercado produtos[], int qtd);
void imprimirProduto(mercado produtos[], int qtd, int back);
void editar(mercado produtos[], int qtd);
int backup(mercado produtos[], int qtd, int back);
int excluir(mercado produtos[], int qtd);

int main(){
	setlocale(LC_ALL, "Portuguese");
	mercado produtos[MAX];
	int qtd=0, back;

	do{
		switch (menu()){
			case 1:
				incluirProduto(produtos);
				qtd++;
			break;
			case 2:
				pesquisarProduto(produtos,qtd);
				break;
			case 3:
				imprimirProduto(produtos, qtd, back);
				break;
			case 4:
				editar(produtos, qtd);
				break;
			case 5:
				back = backup(produtos, qtd, back);
				break;
			case 6:
				qtd = excluir(produtos, qtd);
				break;
			case 0:
				exit(0);
		}
	}while(1); 
	
	return 0;
}	


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
			puts("Opção invalida");
		}
	}while(op<1 || op>6);
	return op;
}

/*--------------------VALIDAÇOES---------------------
int leValidaCodigo(mercado produtos[].codProd){
	int cod;
	do{
		printf("Digite o codigo do produto (Entre 1 e 100): \n");
		scanf("%i", &cod);	
		if(cod<1 || cod>100 && codigoProd[cod] != 0){
			printf("Codigo invalido");
		}
	
	}while(cod<1 || cod>100);
	return cod;
}

void leValidaNomeProd(mercado produtos[].nomeProd){
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
}*/
/*-------------------INCLUIR------------------------*/
void incluirProduto( mercado produtos[]){
	int i = 0;
	system("cls");
	printf("----Incluir Produto----\n");
	for(i=0; i<MAX; i++){//utilizei o for porque a questão fala para cadastrar 100 produtos. Ou usaria do while caso fosse até 100 produtos.
		printf("Digite o código do %iº produto (Entre 1 e 100): ", i+1);
		scanf("%i", &produtos[i].codProd);
		fflush(stdin);
		printf("Digite o nome do produto: ");
		fgets(produtos[i].nomeProd, 25, stdin);
		fflush(stdin);
		printf("Digite o valor de compra:");
		scanf("%f", &produtos[i].precoCompra);
		fflush(stdin);
		printf("Digite o valor de venda:");
		scanf("%f", &produtos[i].precoVenda);
		fflush(stdin);
		printf("----Produto incluído com sucesso.----\n");
		printf("Código %i - Produto: %s - Preço de Compra %.2f - Preço de Venda %.2f", produtos[i].codProd, produtos[i].nomeProd, produtos[i].precoCompra, produtos[i].precoVenda);
	}
}
void pesquisarProduto(mercado produtos[], int qtd){
	int codPesquisa, codRetorno, i;
	char continuar;
	system("cls");
	do {
		printf("\nInforme o codigo do produto? ");
		fflush(stdin);
		scanf("%i", &codPesquisa);
		for(i = 0; i <= qtd; i++){
			if(produtos[i].codProd == codPesquisa){
				printf("Código: %i \nProduto: %s  \nPreço de Compra: R$ %.2f \nPreço de Venda: R$ %.2f\n", produtos[i].codProd, produtos[i].nomeProd, produtos[i].precoCompra, produtos[i].precoVenda);
					codRetorno++;
			}else if(codRetorno == 0){
				printf("Código não encontrado\n");
			}
		}
		printf("\nDigite 'S' para nova pesquisa: ");
		continuar = toupper (getche());	
	}while(continuar == 'S' || continuar == 's');
}
void imprimirProduto(mercado produtos[], int qtd, int back){
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
			for (i=0;i<=qtd;i++){
				printf("Código: %d\tNome: %s\t\tPreço de Compra: %.2f\t\tPreço de Venda: %.2f\n", produtos[i].codProd, produtos[i].nomeProd, produtos[i].precoCompra, produtos[i].precoVenda);
			}
			break;
			case 2:
			for (i=0;i<=qtd;i++){
				printf("Código: %d\tNome: %s\t\tPreço de Compra: %.2f\t\tPreço de Venda: %.2f\n", produtos[i].codBkp, produtos[i].nomeBkp, produtos[i].compraBkp, produtos[i].vendaBkp);
			}
			break;
			default: printf("Codigo inválido!\n");
		}
	}
	printf("\nTotal de itens cadastrados: %d\n\n", qtd);
	system("pause");
}	
void editar(mercado produtos[], int qtd){
	int codPesquisa, i, opcao;
	printf("----Editar----\n");
	printf("\nInforme o codigo do produto que deseja editar: ");
	fflush(stdin);
	scanf("%i", &codPesquisa);
	for(i = 0; i < qtd; i++){
		if(codPesquisa == produtos[i].codProd){
			puts("1 - Editar codigo.");
			puts("2 - Editar nome produto.");
			puts("3 - Editar preço de compra.");
			puts("4 - Editar preço de venda.");
			fflush(stdin);
			scanf("%d", &opcao);
			switch (opcao){
				case 1: printf("Digite novo codigo:\n");
						fflush(stdin);
						scanf("%i", produtos[i].codProd);
						break;
				case 2: printf("Digite novo nome do produto:\n");
						fflush(stdin);
						fgets(produtos[i].nomeProd, 25, stdin);
						break;
				case 3: printf("Digite o novo preco de compra:\n");
						fflush(stdin);
						scanf("%f", produtos[i].precoCompra);
						break;
				case 4: printf("Digite o novo preco de venda:\n");
						fflush(stdin);
						scanf("%f", produtos[i].precoVenda);
						break;
				default: printf("Código inválido!\n");
			}
		}
	}
}
int backup(mercado produtos[], int qtd, int back){
	int i;
	for (i = 0; i <= qtd; i++){
		produtos[i].codBkp = produtos[i].codProd;
		strcpy(produtos[i].nomeBkp, produtos[i].nomeProd);
		produtos[i].compraBkp = produtos[i].precoCompra;
		produtos[i].vendaBkp = produtos[i].precoVenda;
//	i++;
	}
	if(i == 0){
		printf("\nBackup nao concluido");
	//	return back = 0;
		system("pause");
	}
	else{
		printf("\nBackup concluido");
	//	return back = 1;
		system("pause");
	}
	return back;
}
/*-----------------EXCLUIR------------------*/
int excluir(mercado produtos[], int qtd){
	int i, j, codPesquisa, vazio;
	char aux;
	
	do{
		printf("Informe o codigo do produto que deseja excluir: ");
		scanf("%i", &codPesquisa);
		fflush(stdin);
		for(i = 0; i <=qtd; i++){
			if(produtos[i].codProd == codPesquisa){
					for(j=i; j < MAX; j++){
						produtos[j].codProd = produtos[j+1].codProd;
						strcpy(produtos[j].nomeProd, produtos[j+1].nomeProd);
						produtos[j].precoCompra = produtos[j+1].precoCompra;
						produtos[j].precoVenda = produtos[j+1].precoVenda;
					}
					qtd--;	
			}else vazio++;
		}
		if (vazio==qtd){
			printf ("Esse código não foi cadastrado. Impossível excluir!\n");	
		}
		
		puts("Deseja excluir outro produto [S|N]: ");
		scanf("%c", &aux);
		fflush(stdin);
	}while(aux == 's' || aux == 'S');
	return qtd;
}
		
		
		



