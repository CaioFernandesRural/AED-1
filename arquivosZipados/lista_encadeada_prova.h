#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
	struct Node *prox;
}; 
typedef struct Node node;



void inicia(node *LISTA)
{
	LISTA->prox = NULL;
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

int exibe(node *LISTA)
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return 0;
	}
	
	node *tmp;
	tmp = LISTA->prox;
	
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n\n");
	return 1;
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

int numElementos(node *LISTA)
{ node *temp = LISTA ; 
  int cont=0 ;
  
	   if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return 0;
	    }
	   
		
		while(temp->prox != NULL)
		{ cont ++ ; 
			temp = temp->prox;
		}
        return (cont);	
}

void exibeInversa(node *LISTA)
{   int i =0 ,j = 0 ,  num ;
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	num = numElementos(LISTA);
	node *tmp;
	tmp = LISTA->prox;
	for (i = num ; i>0 ; i--) 
	  { tmp = LISTA->prox;
	    for ( j = 1 ; j< i ; j++)
	        tmp = tmp->prox;
	    printf("%5d", tmp->num);
	  }
	
	printf("\n\n");
}

node * criaLista(node *LISTA,int n)
{   node *aux = NULL ;
	int  i ;
	LISTA=(node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	
	LISTA->prox = NULL;
	LISTA->num = -1 ;
	aux = LISTA ;
	for (i=0;i<n;i++)
	{ node *novo=(node *) malloc(sizeof(node));
	  novo->prox = NULL;
	  printf("\n valor =");scanf ("%d",&novo->num);
	  aux->prox = novo ;
	  aux = novo ;
	 } 
		
	return(LISTA);
}

node * busca(node *LISTA, int x, node ** ant)
{ node *ptr ;
  *ant = LISTA ;
  ptr = NULL ;	
  if(vazia(LISTA)) return NULL ;
               else 
               { ptr = LISTA->prox;
				 while (ptr != NULL) 
				     if (ptr->num == x)  break ;
				                         else 
				                           { *ant = ptr ;
					                        ptr = ptr->prox ;}
					                
					                
				return ptr ;     
               }	
}
 
 int removeLista(node *LISTA, int x)
{ node *aux , *ant ;
  aux = busca(LISTA, x, &ant);
  
  if (aux)  { ant->prox = aux->prox ;
	           free(aux);
	           return(1);
	          } 
            else return 0 ;
 }   
 
 int maior(node *LISTA)
{ node *temp = LISTA ; 
  int maior = -1 ;
  
	   if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return 0;
	    }
	   
		
		while(temp != NULL)
		{    if ( temp->num > maior) maior = temp->num ;
			 temp = temp->prox;
		}
        return (maior);	
}

int listaordenada(node *LISTA, node *LISTA1)
{ 	
  int m = -1 ;
  
	   if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return 0;
	    }
	   
		
		while(!vazia(LISTA))
		{    m = maior(LISTA);
			 insereFim(LISTA1,m);
			 removeLista(LISTA, m);
			 
		}
		
		//exibe(LISTA);
		//exibe(LISTA1);
		return 1;
        
}
 
int menu(void)
{
	int opt;
	
	printf("Escolha a opcao\n");
	
	printf("1. Exibir lista\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Adicionar node no final\n");
	printf("4. Maior Elemento \n");
	printf("5. Exibir Numero de Elementos\n");
	printf("6. Exibir lista Inversa \n");
	printf("7. Remover node \n");
	printf("8. Buscar node \n");
	printf("9. Criar Lista Ordenada\n");
	printf("99. Sair \n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
} 

void opcao(node *LISTA,node *LISTA1, int op)
{   int x ;
	switch(op){	
			
		case 1:
			exibe(LISTA);
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
			 printf("\n maior elemento: %d \n\n ",maior(LISTA));
			break;
			
		
		case 5:
			printf("\n Numero de elementos:%d \n ",numElementos(LISTA));
			break;
		
		case 6:
			exibeInversa(LISTA);
			break;
			
		case 7:
			printf(" Elemento para Remover: "); 
		    scanf("%d", &x);
			removeLista(LISTA,x);
			break;
			
		case 8:
		    printf(" Elemento para Busca: "); 
		    scanf("%d", &x);
			node * ant , *aux ;
            aux = busca(LISTA, x, &ant);
            if (aux != NULL) printf(" \n Elemento na lista !!! %d %d \n ",aux->num , ant->num); 
                            else printf(" \n Elemento fora da  lista !!!!  \n "); 
			break;
		
		case 9: listaordenada (LISTA,LISTA1);
		        exibe(LISTA1);
		        exibe(LISTA);
			
			break;	
		
		case 99:
			
			break;
		
		default:
			printf("Comando invalido\n\n");
	}
}
