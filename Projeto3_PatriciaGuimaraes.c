//Elabore um algoritmo utilizando, obrigatoriamente, alocação dinâmica, que:

//Realize o cadastro 100 produtos, contendo: código, nome, preço de compra, preço de venda, quantidade.

//Realize as seguintes ações: incluir, excluir, editar, pesquisar, realizar backup

//Projeto 3 - Alocação Dinâmica

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>


typedef struct cadastro produto;
struct cadastro{
	int codigo, qtde;
	char nome[20];
	float precoCompra, precoVenda;
	produto *proximo;
};
/*typedef struct backup backupProd;
struct backup{
	int backCod, backQtde;
	char backNome[20];
	float backCompra, backVenda;
	backupProd *proximo;
};*/

//produto *inicializar();
int menu();
produto* incluir(produto *vendas);
void pesquisar(produto *vendas);
void imprimir(produto *vendas);
void editar(produto *vendas);
//void backupLista(produto *vendas, backupProd *backup);
produto* excluir(produto *vendas);

int main(){
	produto *vendas;
//	backupProd *backup;
	int opcao;
	vendas = NULL;//fiz a inicialização por aqui
//	backup = NULL;
//	vendas = inicializar();
//	backup = inicializar();
	do{
		switch(menu()){
			case 1:
				printf("======Incluir Produto=====\n");
				vendas = incluir(vendas);
				break;
			case 2:
				pesquisar(vendas);
				break;
			case 3:
				imprimir(vendas);
				break;
			case 4:
				editar(vendas);
				break;
			case 5:
//				backupLista(vendas, backup);
				break;
			case 6:
				vendas = excluir(vendas);			
				break;
			case 0:
				exit(1);
				break;	
		}
		system("pause");
		system("cls");
		
 	printf("Deseja realizar uma nova operacao? Digite 1 - se sim.\n");  
	fflush(stdin);  
    scanf("%d", &opcao);			
	}while(opcao==1);

	return 0;
}
/*produto *inicializar(){
	return NULL;
}*/


int menu(){
	int op;

	do{
		puts("---Escolha uma opcao:---");
		puts("1 - Incluir dados dos produtos.");
		puts("2 - Pesquisar produto.");
		puts("3 - Imprimir produtos.");
		puts("4 - Editar");
		puts("5 - Realizar backup.");
		puts("6 - Excluir.");
		puts("0 - Sair.");
		fflush(stdin);
		scanf("%i", &op);
		if(op<1 || op>6){
			puts("Opção invalida");
		}
	}while(op<1 || op>6);
	return op;
}
produto* incluir(produto *vendas){
	produto* novo = (produto*) malloc(sizeof(vendas));
	do{
		printf("Digite o codigo do produto: ");
		scanf("%d", &novo->codigo);
		fflush(stdin);
		
		printf("Informe o nome do produto: ");
		scanf("%s", &novo->nome);
		fflush(stdin);
		
		printf("Informe o preco de compra:");
		scanf("%f", &novo->precoCompra);
		fflush(stdin);
		
		printf("Informe o preco de venda: ");
		scanf("%f", &novo->precoVenda);
		fflush(stdin);
		
		printf("Informe a quantidade: ");
		scanf("%d", &novo->qtde);
		fflush(stdin);
		
		printf("Produto incluido com sucesso!\n");

	puts("Pressione 's' para novo produto:");	
	}while(getch()=='s');
	
	novo->proximo = vendas;	
	return novo;
} 
void pesquisar(produto *vendas){
	produto* aux;
	int codPesquisa;
	printf("Informe codigo do produto que deseje pesquisar: ");
	scanf("%d", &codPesquisa);
	if(vendas == NULL){
		printf("Nao foram realizadas inclusao de produto.\n");
	}else{
		for(aux=vendas; aux!=NULL; aux=aux->proximo){
			if(codPesquisa == aux->codigo){
				printf("Codigo: %d\n", aux->codigo);
				printf("Produto: %s\n", aux->nome);
				printf("Preco de compra: %f\n", aux->precoCompra);
				printf("Preco de venda: %f\n", aux->precoVenda);
				printf("Quantidade de venda: %d\n", aux->qtde);
			}
		}
	}
}
void imprimir(produto *vendas){
	produto* aux;
	if (vendas == NULL){
		printf("Lista vazia!");
	}else{
		puts("====Produtos====");
		for(aux=vendas; aux!=NULL; aux=aux->proximo){
			printf("Codigo: %d\n", aux->codigo);
			printf("Produto: %s\n", aux->nome);
			printf("Preco de compra: %f\n", aux->precoCompra);
			printf("Preco de venda: %f\n", aux->precoVenda);
			printf("Quantidade de venda: %d\n", aux->qtde);
		}	
	}
}
void editar(produto *vendas){
	produto* aux;
	int codPesquisa, opcao;
	puts("====Editar====");
	printf("Informe o codigo do produto que deseja editar: ");
	scanf("%d", &codPesquisa);
	if(vendas == NULL){
		printf("Nao ha produtos cadastrados.\n");
	}else{
		for(aux=vendas; aux!=NULL; aux=aux->proximo){
			if(codPesquisa==aux->codigo){
				puts("1 - Editar codigo.");
				puts("2 - Editar nome produto.");
				puts("3 - Editar preço de compra.");
				puts("4 - Editar preço de venda.");
				puts("5 - Editar quantidade.");
				fflush(stdin);
				scanf("%d", &opcao);
				switch (opcao){
					case 1:
						printf("Digite novo codigo:\n");
						fflush(stdin);
						scanf("%i", &aux->codigo);
						break;
					case 2: 
						printf("Digite novo nome do produto:\n");
						fflush(stdin);
						scanf("%s", &aux->nome);
						break;
					case 3: 
						printf("Digite o novo preco de compra:\n");
						fflush(stdin);
						scanf("%f", &aux->precoCompra);
						break;
					case 4: printf("Digite o novo preco de venda:\n");
						fflush(stdin);
						scanf("%f", &aux->precoVenda);
						break;
					case 5: 
						printf("Informe a quantidade:");
						fflush(stdin);
						scanf("%d", &aux->qtde);	
				default: printf("Código inválido!\n");
				}
			}
		}
	}
}
/*void backupLista(produto *vendas, backupProd *backup){
	produto *aux;
	backup *auxBack;
	
	auxBack = backup;
	
	if(vendas==NULL){
		printf("Nao ha lista para fazer backup.");
	}else{
		for(aux=vendas; aux!=NULL, auxBack!=NULL; aux=aux->proximo, auxBack=auxBack->proximo){
			auxBack->backCod = aux->codigo;
			auxBack->backNome = aux->nome;
			auxBack->backCompra = aux->precoCompra;
			auxBack->backVenda = aux->precoVenda;
			auxBack->backQtde = aux->qtde;
		}
		printf("Backup concluido com sucesso.");
	}
}*/
produto* excluir(produto *vendas){
	produto* aux;
	produto* anterior;
	int codExcluir;
	
	printf("Digite o codigo do produto que deseja excluir: ");
	scanf("%d", &codExcluir);
	
	for(anterior=NULL, aux=vendas; aux!=NULL && aux->codigo!=codExcluir; anterior=aux, aux=aux->proximo){
	}
	if(aux==NULL){
		printf("Codigo nao cadastrado - Lista Vazia\n");
		return vendas;
		}
	if(anterior==NULL){
		vendas = aux->proximo;
		free(aux);
	}else{
		anterior->proximo = aux->proximo;
		free(aux);
	}
	printf("Codigo removido com sucesso.\n");	
	return vendas;
}



