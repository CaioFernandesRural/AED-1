# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define tam 7

struct dados
{
  int info;
  struct dados *prox;
};

typedef struct dados Dados;
typedef Dados* Hash[tam];

int funcaoHash(int num);
void inicializaHash(Hash tab); 
void insereHash(Hash tab,int num);
void buscaHash(Hash tab, int num);
void imprimeHash(Hash tab);
void removeHash(Hash tab, int num);
void imprimeColisao(Hash tab, int pos);
void opcao(Hash tab, int op);
int menu(void);


int funcaoHash(int num)
{
  return(num%tam);
}


void inicializaHash(Hash tab)
{
	int i;
	for(i = 0; i < tam; i++){
		tab[i] = NULL;
	}
}


void insereHash(Hash tab, int num)
{
	int chave = funcaoHash(num);
	Dados* aux = tab[chave];
	while(aux != NULL){
		if(aux->info == num){
			break;
		}
		aux = aux->prox;
	}
	if(aux == NULL){
		aux = (Dados*)malloc(sizeof(Dados));
		aux->info = num;
		aux->prox = tab[chave];
		tab[chave] = aux;
	}
}

void imprimeHash(Hash tab)
{
	int  i = 0;
	for(i = 0; i < tam; i++){
		if(tab[i] != NULL){
			printf("\n %d",tab[i]->info);
			Dados* aux =tab[i]->prox;
			while(aux!=NULL){
				printf(" -> %3d",aux->info);
				aux=aux->prox;
			}
		}
	}
}
 

void removeHash(Hash tab, int num)
{

	int chave = funcaoHash(num);
	Dados* aux = tab[chave];
	Dados *ant = tab[chave];
	while(aux != NULL){
		if(aux->info == num){
			break;
		}
		ant = aux ;
		aux = aux->prox;
	}
	if(aux != NULL){
		if (aux == ant){
			tab[chave] = ant->prox ;
		} 
		else{
			ant->prox = aux->prox ;
		}
	}
}

void buscaHash(Hash tab,int num)
{
	int pos = num;
	if(num > tam || num < 0){
		printf("\nPosicao nao encontrada!");
		return;
	}else {
		imprimeColisao(tab,pos);
	}
}

void imprimeColisao(Hash tab, int pos)
{
	Dados* aux = tab[pos];
	if(aux == NULL){
		printf("Esta posicao esta vazia!");
		return;
	}else {
		if(aux != NULL){
			printf("%3d",aux->info);
			while(aux->prox != NULL){
				printf(" -> %d",aux->prox->info);
				aux = aux->prox;
			}
		}
	}
}


int menu(void)
{
	int opt;
	printf("\n\n\n");
	printf("Escolha a opcao\n");	
	printf("1. Exibir Tabela Hash\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Remover No\n");
	printf("4. Sair\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

void opcao(Hash tab, int op)
{   int x ;
	switch(op){	
			
		case 1:
			imprimeHash(tab);
			break;
		
		case 2:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			insereHash(tab,x);
			break;
		
		case 3:
		    printf("Elemento a ser Removido: "); 
		    scanf("%d", &x);
			removeHash(tab,x);
			break;		
			
					
		case 5:
			//libera(LISTA);
			break;
		
		default:
			printf("Comando invalido\n\n");
	}
}


