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
node * buscaOrdenada(node *LISTA, int x, node ** ant);
void insere(node *LISTA, int x);
void retira(node *LISTA,int x);
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
	printf("1. Exibir lista\n");
    printf("2. Exibir lista Inversa\n");
	printf("3. BUSCA\n");
	printf("4. INSERIR\n");
	printf("5. RETIRAR \n");
	printf("6. Zerar lista\n");
	printf("7. Sair\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

void opcao(node *LISTA, int op)
{   int x ;
	node *ptr=NULL , *ant = NULL ;
	switch(op){	
			
        case 1:
			exibe(LISTA);
			break;
			
		case 2:
			exibeInversa(LISTA);
			break;
		
		case 3:
		    printf("\n BUSCA elemento: "); 
		    scanf("%d", &x);
			ptr = buscaOrdenada(LISTA,x,&ant);
			if (ptr==NULL) printf(" \n Elemento nao encontrado %d \n\n",ant->num);
			            else printf("\n elemento: %d \n \n ",ptr->num); 
			break;
		
		case 4:
		    printf("\n Novo elemento: "); 
		    scanf("%d", &x);
			insere(LISTA,x);
			printf("\n");
			break;	
			
		case 5:
		     printf("\n BUSCA elemento: "); 
		    scanf("%d", &x);
			retira(LISTA,x);
			printf("\n");
			break;	
			
		case 6:
			libera(LISTA);
			break;
		
		case 7:
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
		printf("\nLista vazia!\n\n");
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
		printf("\n Lista vazia!\n\n");
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

void insere(node *LISTA,int x)
{   node *tmp1 = NULL , *ant ;
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	
	tmp1 = buscaOrdenada(LISTA,x,&ant) ;
	if (tmp1 == NULL ) { 
		               novo->num = x ;
	                   if(vazia(LISTA)){
		               LISTA->prox=novo;
		               novo->ant = LISTA ;
		               LISTA->ant = novo ; 
		               novo->prox = LISTA;
					                   }
	                  else{
					  node *tmp = ant->prox ;
		              ant->prox = novo ;	
		              novo->ant = ant ;	
		              novo->prox = tmp ;
		              tmp->ant =novo;
		              
	                      }
					  }
					  else 
					  printf("\nElemento ja esta na lista!\nn");
	                     
}




void retira(node *LISTA, int x)
{
	node *tmp = NULL , *ant ;
	tmp = buscaOrdenada(LISTA,x,&ant) ;
	 
	if(tmp==NULL )  printf("\nElemento n'ao Existe!\n\n");
	             else 
	              if (LISTA->prox->prox == LISTA) 
	                  { node *tmp = LISTA->prox;
						LISTA->prox = NULL ;
						LISTA->ant = NULL ;
						free(tmp);
					   }
					   else 
					       {                 
		                    node *aux1 = tmp->prox;
		                    node *aux2 = tmp->ant;
		                    aux2->prox= aux1;
		                    aux1->ant = aux2; ;
		                    free(tmp);
	                        }
	
}


node * buscaOrdenada(node *LISTA, int x, node ** ant)
{ node *ptr ;
  *ant = LISTA ;
  ptr = NULL ;	
  if(vazia(LISTA)) return NULL ;
               else 
               if (x>LISTA->ant->num) 
                   {*ant = LISTA->ant ;
					return NULL ;
				}
               else 
               { ptr = LISTA->prox;
				 while (ptr != LISTA) 
				   { if (ptr->num < x) { *ant = ptr ;
					                     ptr = ptr->prox ;}
					                else 
					                {if (ptr->num == x)  return ptr ;
										        else  return (NULL);	                     
									 break;
									 }
				   }
				}   
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
