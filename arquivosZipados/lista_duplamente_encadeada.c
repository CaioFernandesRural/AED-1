#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *ant;
	struct Node *prox;
}; 
typedef struct Node node;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
void exibe(node *LISTA);
void exibeInversa(node *LISTA);
node * busca(node *LISTA, int x);
void insereFim(node *LISTA, int x);
void insereInicio(node *LISTA, int x);
void retiraFim(node *LISTA);
void retiraInicio(node *LISTA);
void libera(node *LISTA);


int main(void)
{
	node *LISTA = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	inicia(LISTA);
	int opt;
	
	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt!=7);

	free(LISTA);
	return 0;
}

void inicia(node *LISTA)
{
	LISTA->ant = NULL;
	LISTA->prox = NULL;
	LISTA->num = -1;
}

int menu(void)
{
	int opt;
	
	printf("Escolha a opcao\n");	
	printf("0. Exibir lista\n");
    printf("1. Exibir lista Inversa\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Adicionar node no final\n");
	printf("4. Retirar node no inicio\n");
	printf("5. Retirar node no final\n");	
	printf("6. Zerar lista\n");
	printf("7. Sair\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

void opcao(node *LISTA, int op)
{   int x ;
	switch(op){	
			
        case 0:
			exibe(LISTA);
			break;
			
		case 1:
			exibeInversa(LISTA);
			break;
		
		case 2:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			insereInicio(LISTA,x);
			break;
		
		case 3:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			insereFim(LISTA,x);
			break;	
			
		case 4:
			retiraInicio(LISTA);
			break;	
			
		case 5:
			retiraFim(LISTA);
			break;
		
		case 6:
			libera(LISTA);
			break;
			
		case 7:
			libera(LISTA);
			break;
		
		default:
			printf("Comando invalido\n\n");
	}
}

int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

void exibe(node *LISTA)
{    if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	
	while( tmp != LISTA){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n\n");
}

void exibeInversa(node *LISTA)
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	
	node *tmp;
	tmp = LISTA->ant;
	
	while( tmp != LISTA){
		printf("%5d", tmp->num);
		tmp = tmp->ant;
	}
	printf("\n\n");
}

void insereFim(node *LISTA,int x)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	
	
	novo->num = x ;
	if(vazia(LISTA)){
		LISTA->prox=novo;
		novo->ant = LISTA ;
		LISTA->ant = novo ; 
		novo->prox = LISTA;
	    }
	else{
		node *tmp = LISTA->ant;
		
		tmp->prox = novo ;
		novo->ant = tmp ;	
		novo->prox = LISTA ;	
		LISTA->ant = novo;
	}
}

void insereInicio(node *LISTA, int x)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	
	novo->num = x ;
	
	if(vazia(LISTA)){
		LISTA->prox=novo;
		novo->ant = LISTA ;
		LISTA->ant = novo ; 
		novo->prox = LISTA;
	    }
	else{
		node *tmp = LISTA->prox;
	
	    LISTA->prox = novo;
	    novo->ant = LISTA;
	    novo->num = x ;
	    novo->prox = tmp;
	    tmp->ant = novo ;
	}
	
	
}

void retiraFim(node *LISTA)
{
	
	if(vazia(LISTA))  {}
	             else 
	              if (LISTA->prox->prox == LISTA) 
	                  { node *tmp = LISTA->prox;
						LISTA->prox = NULL ;
						LISTA->ant = NULL ;
						free(tmp);
					   }
					   else 
					       {                 
		                    node *tmp = LISTA->ant;
		                    node *ant = tmp->ant;
		                    node *prox = tmp->prox;
		                    ant->prox= prox;
		                    prox->ant = ant ;
		                    free(tmp);
	                        }
	
}

void retiraInicio(node *LISTA)
{
	
	if(vazia(LISTA))  {}
	             else 
	              if (LISTA->prox->prox == LISTA) 
	                  { node *tmp = LISTA->prox;
						LISTA->prox = NULL ;
						LISTA->ant = NULL ;
						free(tmp);
					   }
					   else 
					       {                 
		                    node *tmp = LISTA->prox;
		                    node *prox = tmp->prox;
		                    LISTA->prox= prox;
		                    prox->ant = LISTA ;
		                    free(tmp);
	                        }
	
}


node * busca(node *LISTA, int x)
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return NULL;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	
	while( tmp != NULL)
		if (tmp->num == x ) return tmp ;
		                    else  tmp = tmp->prox;
	
	 if (tmp == NULL) return tmp;
}


void libera(node *LISTA)
{
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;
		
		atual = LISTA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}
