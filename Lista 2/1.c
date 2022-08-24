
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int num;
    struct Node *prox;
};
typedef struct Node node;

void inicia (node *Lista){
    Lista->prox = NULL;
    Lista->num = NULL;
}
void exibe (node *Lista){

    if (vazia(Lista)){
        return NULL;
    }
    node *tmp;
    tmp = Lista->prox;
    
    printf("\n");

    while (tmp != NULL){
        printf("  %d  ", tmp->num);
        tmp = tmp->prox;
    }
    printf("\n\n");
}
int elementos (node *Lista){
    
    node *tmp;
    tmp = Lista->prox;

    int contador = 0;

    if (vazia(Lista)){
        return NULL;
    } 
    while (tmp != NULL){
        tmp = tmp->prox;
        contador ++; 
    }
    
    return contador;
}
int vazia(node *Lista){
	if(Lista->prox == NULL)
		return 1;
	else
		return 0;
}
void insereFinal(node *Lista, int x){
    node *novo = (node *) malloc(sizeof(node));

    novo->prox = NULL;
    novo->num = x;
    if (vazia(Lista)){
        Lista->prox = novo;
    }
    else {
        node *tmp = Lista->prox;

        while (tmp->prox != NULL)
        {
            tmp = tmp->prox;
        }
        tmp->prox = novo;  
    }
    
}
void insereInicio(node *Lista, int x){
    node *novo = (node *) malloc(sizeof(node));

    node *oldHead = Lista->prox;

    Lista->prox = novo;
    novo->num = x;
    novo->prox = oldHead;
}
void exibeInv (node *Lista){

    if (vazia(Lista)){
        return NULL;
    }

	exibeInv(Lista->prox);

	printf("  %d  ", Lista->prox->num);
	
}
void valores (node *Lista){

    if (vazia(Lista)){
        return NULL;
    }
    node *tmp;
    tmp = Lista->prox;

    int mai, men, soma = 0;
    mai = tmp->num;
    men = tmp->num;
    
    printf("\n");

    while (tmp != NULL){
        if (tmp->num > mai){ mai = tmp->num;}
        if (tmp->num < men){ men = tmp->num;}

        soma += tmp->num;
        tmp = tmp->prox;
    }
    float media = (soma / elementos(Lista)); //não funcionava sem essa variavel
    printf("\nMaior: %d /Menor: %d", mai, men);
    printf("\nMedia: %.2f", media);
}
void maiorMaior(node *Lista){
    if (vazia(Lista)){
        return NULL;
    }
    node *tmp;
    tmp = Lista->prox;

    int mai, MAI;
    MAI = tmp->num;
    mai = tmp->num;

    while (tmp != NULL){
        if (tmp->num > MAI){ MAI = tmp->num;}
        tmp = tmp->prox;
    }
    tmp = Lista->prox;
    while (tmp != NULL){
        if (tmp->num > mai && tmp->num != MAI){ mai = tmp->num;}
        tmp = tmp->prox;
    }
    printf("\n\nMAIOR: %d /maior: %d", MAI, mai);
}
int menu (){
    int esc;
	
	printf("\nEscolha a opcao\n");
	
	printf("1. Exibir lista\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Adicionar node no final\n");
	printf("4. Exibir Inverso \n");
	printf("5. Valores\n");
    printf("6. Contagem.\n");
	printf("7. Sair\n");
    fflush(stdin);
	printf("Opcao: "); scanf("%d", &esc);
	
	return esc;
}

void menuAtivo(node *Lista, int esc) {
    int x ;
	switch(esc){	
			
		case 1:
			exibe(Lista);
			break;
		
		case 2:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			insereInicio(Lista,x);
			break;
		
		case 3:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			insereFinal(Lista,x);
			break;		
			
		case 4:
			exibeInv(Lista);
			break;		
			
		case 5:
			valores(Lista);
			break;
        
        case 6:
            printf("\nA lista tem %d elementos\n", elementos(Lista));
			
	    case 7:
            maiorMaior(Lista);
            break;
        case 8:
            //ordenada
        case 9:
            //nova inversa
        case 10:
			break;
		
		default:
			printf("Comando invalido\n\n");
	}
}

int main () {
    node *Lista = (node *) malloc (sizeof(node));

    inicia(Lista);
    int esc;

    do{
        esc = menu();
        menuAtivo(Lista, esc);
    } while (esc != 10);
    
    free(Lista);
    return 1;
}