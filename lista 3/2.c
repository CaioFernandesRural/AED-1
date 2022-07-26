#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *prox;
};

typedef struct Node node;

int vazia(node *Lista){
    if (Lista->prox == NULL)
    {
        return 1;
    }
    else return 0;
}
void exibe(node *Lista){
    
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
    printf("\n");
}
void insere(node *Lista, int x){
    node *novo = (node *) malloc(sizeof(node));

    novo->prox = NULL;
    novo->num = x;

    node *oldHead = Lista->prox;

    Lista->prox = novo;
    novo->num = x;
    novo->prox = oldHead;
}
void remover(node *Lista){
    node *tmp;

    if (Lista->prox != NULL){
        
        tmp = Lista->prox;
        Lista->prox = tmp->prox;
        free(tmp);
        return(1);
    }
    else{
        return 0;
    }
}
void inicia(node *Lista){
    Lista->prox = NULL;
    Lista->num = 0;
}
int menu(){
    int esc;

    printf("\nEscolha a opcao\n");
	printf("1. Exibir lista\n");
	printf("2. Adicionar node\n");
	printf("3. Remover valor.\n");
	printf("4. Sair\n");
    fflush(stdin);
	printf("Opcao: "); scanf("%d", &esc);
	
	return esc;
}
void menuAtivo(node *Lista, int esc){
    int x;

    switch (esc){
    case 1:
        exibe(Lista);
        break;
    case 2:
        printf("\nNumero a inserir: ");
        scanf("%d", &x);
        insere(Lista, x);
        break;
    case 3:
        remover(Lista);
        break;
    case 4:
        break;
    
    default:
        printf("\nInvalido.");
        break;
    }
}

int main() {
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