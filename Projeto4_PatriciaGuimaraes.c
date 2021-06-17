//Elabore um algoritmo utilizando, obrigatoriamente, alocação dinâmica, que:

//Realize o cadastro 100 produtos, contendo: código, nome, preço de compra, preço de venda.

//Realize as seguintes ações: incluir, excluir, editar, pesquisar, realizar backup.

//Projeto 4 - Arquivo

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
//Não consegui fazer backup

typedef struct cadastro {
	int codigo;
	char nome[20];
	float precoCompra, precoVenda;
}Cadproduto;

Cadproduto incluir();
void armazenar(Cadproduto x);
void pesquisar();
void imprimirProdutos();
void excluirProduto();

int main(){
	Cadproduto produto;
	int opcao;
		
	do{
		puts("---Escolha uma opcao:---");
		puts("1 - Incluir e armazenar dados dos produtos.");
		puts("2 - Pesquisar produto.");
		puts("3 - Imprimir produtos.");
		puts("4 - Excluir Produto.");
		puts("0 - Sair.");
		scanf("%i", &opcao);
		switch(opcao){
			case 1:
				armazenar(incluir());
				break;
			case 2:
				pesquisar();			
				break;
			case 3:
				imprimirProdutos();
				break;
			case 4:
				excluirProduto();
				break;
			case 0:
				exit(1);
				break;					
			
		}
		system("pause");
		system("cls");

	}while(1);//se verdadeiro	

	return 0;
}

/*---------Incluir---------*/
Cadproduto incluir(){
	Cadproduto x;

	printf("Digite o codigo do produto: ");
	fflush(stdin);	
	scanf("%d", &x.codigo);

	printf("Informe o nome do produto: ");
	fflush(stdin);
	scanf("%s", &x.nome);
	
	printf("Informe o preco de compra:");
	fflush(stdin);
	scanf("%f", &x.precoCompra);
	
	printf("Informe o preco de venda: ");
	fflush(stdin);
	scanf("%f", &x.precoVenda);
	
	printf("Produto incluido com sucesso!\n");
	return x;
} 

/*---------Armazenar dados no arquivo---------*/
void armazenar(Cadproduto x){
	FILE *fp;
	if((fp = fopen("produtos.bin", "ab"))!= NULL){
		fwrite(&x, sizeof(x), 1, fp);
		fclose(fp);
	}

}
/*---------Pesquisar---------*/
void pesquisar(){
	FILE *fp;
	Cadproduto x;
	int codigoConsulta;
	if((fp=fopen("produtos.bin", "rb"))!=NULL){
		printf("Informe codigo do produto que deseja pesquisar:\n");
		fflush(stdin);
		scanf("%i", &codigoConsulta);
		printf("\n=====Produto=====\n");		
		while(fread(&x, sizeof(x), 1, fp)==1){
			if(codigoConsulta == x.codigo){
				printf("Produto %s\n", x.nome);
				printf("Valor de Compra: %.2f\n", x.precoCompra);
				printf("Valor de Venda: %.2f\n", x.precoVenda);
			}
		}
		fclose(fp);
	}else{
		puts("Arquivo nao encontrado.");
	}	
}
/*---------Imprimir---------*/
void imprimirProdutos(){
	FILE *fp;
	Cadproduto x;
	if((fp=fopen("produtos.bin", "rb"))!=NULL){
		while(fread(&x, sizeof(x), 1, fp)==1){
				printf("\n=====Produto=====\n");
				printf("Codigo do Produto %i\n", x.codigo);
				printf("Produto %s\n", x.nome);
				printf("Valor de Compra: %.2f\n", x.precoCompra);
				printf("Valor de Venda: %.2f\n", x.precoVenda);
		}
		fclose(fp);
	}else{
		puts("Arquivo nao encontrado.");
	}
}
/*---------Excluir---------*/
void excluirProduto(Cadproduto produto){
	FILE *fp, *fpRemove;
	Cadproduto x;
	char nomeRemove[30];
	if((fp=fopen("produtos.bin", "rb"))!=NULL){
		printf("Informe nome do produto para exclusao:\n");
		fflush(stdin);
		gets(nomeRemove);
		fpRemove = fopen("arqRemove.bin", "wb");//arquivo temporário para gravação
		while(fread(&x, sizeof(x), 1, fp)==1){
			if(strcmp(nomeRemove,x.nome)==0){
				puts("Produto excluido.");
			}else{
				fwrite(&x, sizeof(x), 1, fpRemove);//se não for dados iguais, vai guardar nesse arquivo temporário.
			}
		}
		fclose(fp);
		fclose(fpRemove);
	}else{
		puts("Arquivo nao encontrado.");
	}
	//exclusão - tirando do arquivo temporario e voltando para o arquivo original 
	if((fpRemove = fopen("arqRemove.bin", "rb"))!=NULL){//rb pq ele zera o que tinha anteriormente e abre arquivo remove para leitura
		fp=fopen("produto.bin", "wb");//reabre arquivo
		while(fread(&x, sizeof(x), 1, fpRemove)==1){//faz o inverso para voltar com os contatos não excluídos
			fwrite(&x, sizeof(x), 1, fp);
		}
		fclose(fpRemove);
		fclose(fp);
	}
}




