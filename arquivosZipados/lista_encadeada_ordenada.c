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
node * buscaOrdenada(node *LISTA, int x, node ** ant);
void insereOrdenado(node *LISTA, int x);
int removeOrdenado(node *LISTA, int x);
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
	printf("2. BUSCA ORDENADA \n");
	printf("3. INSERE ORDENADO\n");
	printf("4. REMOVE ORDENADO\n");
	printf("5. Zerar lista\n");
	printf("6. Sair\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

void opcao(node *LISTA, int op)
{   int x ;
	node *ant= NULL , *aux = NULL;
	switch(op){	
			
		case 1:
			exibe(LISTA);
			break;
		
		case 2:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
		    aux =buscaOrdenada(LISTA, x, &ant);
			break;
		
		case 4:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			printf(" Remove: %d \n",removeOrdenado(LISTA,x));
			break;		
			
		case 3:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
		    insereOrdenado(LISTA, x);
			break;
			
		case 5:
		    libera(LISTA);
			break;
			
		case 6:
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




node * buscaOrdenada(node *LISTA, int x, node ** ant)
{ node *ptr ;
  *ant = LISTA ;
  ptr = NULL ;	
  if(vazia(LISTA)) ptr = NULL ;
               else 
               { ptr = LISTA->prox;
				 while (ptr != NULL) 
				   { if (ptr->num < x) { *ant = ptr ;
					                     ptr = ptr->prox ;}
					                else 
					                {if (ptr->num == x)   ;
										        else  ptr = NULL ;	                     
							  break;
							 }
				    }
		}   
 return(ptr);
 }	
 
 
 void insereOrdenado(node *LISTA, int x)
 {   node * ant ;
	 node *	aux = buscaOrdenada(LISTA, x, &ant);	
	        	
	 if (!aux) 	{ node *pt=(node *) malloc(sizeof(node));
	                      if(!pt){
		                          printf("Sem memoria disponivel!\n");
		                          exit(1);
	                               }
	                       pt->num = x ;   
	                       pt->prox = NULL ;     
	                       if(vazia(LISTA))
		                            LISTA->prox=pt;
	                                 else
	                                 {                       
	                                  pt->num = x ;	                     
	                                  pt->prox = ant->prox ;
	                                  ant->prox = pt ;
	                                  }
                 }	
  }                                   
		 			 	
int removeOrdenado(node *LISTA, int x)
{ node * ant ;
  node *aux = buscaOrdenada(LISTA, x, &ant);
  if (aux)  { ant->prox = aux->prox ;
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
		while(atual != NULL)
		    { proxNode = atual->prox;
			  free(atual);
			  atual = proxNode;
		    }
	}
	
}
