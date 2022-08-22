#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
}; 

typedef struct Node node;

void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA, int x);
void insereInicio(node *LISTA, int x);
node * busca (node *LISTA, int x, node ** ant);
int retirar(node *LISTA);
void exibe(node *LISTA);
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
	}while(opt!=6);

	free(LISTA);
	return 0;
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
}

int menu(void)
{
	int opt;
	
	printf("Escolha a opcao\n");
	
	printf("1. Exibir lista\n");
	printf("2. INSERIR\n");
	
	printf("4. RETIRAR \n");
	printf("5. Zerar lista\n");
	printf("6. Sair\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

void opcao(node *LISTA, int op)
{   int x ;
	switch(op){	
			
		case 1:
			exibe(LISTA);
			break;
		
		
		
		case 2:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			insereFim(LISTA,x);
			break;		
			
		case 4:
			
			retirar(LISTA);
			break;		
			
		case 5:
			libera(LISTA);
			break;
			
	    case 6:
			
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


void insereFim(node *LISTA,int x)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	
	novo->prox = NULL;
	novo->num = x ;
	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		node *tmp = LISTA->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
}

void insereInicio(node *LISTA, int x)
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	
	
	node *oldHead = LISTA->prox;
	
	LISTA->prox = novo;
	novo->num = x ;
	novo->prox = oldHead;
}

node * busca (node *LISTA, int x, node ** ant)
{ node *ptr , *ptraux;
  *ant = LISTA ;
  ptr = NULL ;	
  if(vazia(LISTA)) ptraux =  NULL ;
               else 
               { ptr = LISTA->prox;
                 while (ptr != NULL) 
                    { if (ptr->num != x) { *ant = ptr ;
                                           ptr = ptr->prox ;}
                         else 
                        {if (ptr->num == x)  ptraux =  ptr ;
                                             else  ptraux = NULL;	                     
                         break;
                        }
                     }
               }
       return(ptraux);
      }

int retirar(node *LISTA)
{ node *aux ;
	if (LISTA->prox != NULL ) {
           aux = LISTA->prox ;
           LISTA->prox = aux->prox;
           free(aux);
           return(1);
          } 
            else return 0 ;
 }     



void exibe(node *LISTA)
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n\n");
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
		LISTA = NULL ;
	}
}
