#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    struct Node *ant;
    struct Node *prox;
}; 
typedef struct Node node;

int vazia(node *Lista){
    if (Lista->prox == NULL){
        return 1;
    }
    else {
        return 0;
    }
    
}

void exibe(node *Lista){
    if (vazia(Lista)){
        return NULL;
    }

    node *tmp;
    tmp = Lista->prox;

    while(tmp != NULL){
        printf("%5d", tmp->num);
        tmp = tmp->prox;
    }
    printf("\n\n");
}
node * buscaOrdenada(node *Lista, int x, node ** ant){
    node *tmp;
    *ant = Lista;
    tmp = NULL;

    if(vazia(Lista)){
        return NULL;
    }
    else{
        if (x > Lista->ant->num){
            *ant = Lista->ant;
            return NULL;
        }
        else {
            tmp = Lista->prox;
            while (tmp != Lista){
                if (tmp->num < x){
                    *ant = tmp;
                    tmp = tmp->prox;
                }
                else {
                    if (tmp->num == x){
                        return tmp;
                    }
                    else {
                        return NULL;
                    }
                    break;
                }
            }
        }
    }
}
void insere(node *Lista, int x){
    node *tmp1 = NULL, *ant;
    node *novo=(node *) malloc(sizeof(node));

    tmp1 = buscaOrdenada(Lista, x, &ant);

    if (tmp1 ==NULL){
        novo->num = x;
        if (vazia(Lista)){
            Lista->prox=novo;
            novo->ant = Lista ;
            Lista->ant = novo ; 
            novo->prox = Lista;
        }
        else{
            node *tmp = ant->prox ;
            ant->prox = novo ;	
            novo->ant = ant ;	
            novo->prox = tmp ;
            tmp->ant =novo;
        }
    }
}

void inicia(node *Lista){
    Lista->ant = NULL;
    Lista->prox = NULL;
    Lista->num = NULL;
}
int menu(){
    int esc;

    printf("\nEscolha a opcao\n");

    printf("1. Exibir lista\n");
    printf("2. Adicionar Node\n");
    printf("3. Fim.\n");
    fflush(stdin);
	printf("Opcao: "); scanf("%d", &esc);

    return esc;
}
void menuFuncoes(node *Lista, int op){
    int x;
    switch (op){
    case 1:
        exibe(Lista);
        break;
    case 2:
        printf("Novo elemento: "); 
        scanf("%d", &x);
        insere(Lista,x);
        break;
    case 3:
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
        menuFuncoes(Lista, esc);
    } while (esc != 4);
    
    free(Lista);
    return 1;
}