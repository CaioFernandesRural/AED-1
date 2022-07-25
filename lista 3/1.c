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

    if (vazia(Lista))
    {
        Lista->prox = novo;
    }
    else
    {
        node *tmp = Lista->prox;

        while (tmp->prox != NULL)
        {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
}
void remove(node *Lista){ //erro bizarro
    if (vazia(Lista)){
        return NULL;
    }
    node *tmp;
    tmp = Lista->prox;
    
    while (tmp->prox != NULL){
        tmp = tmp->prox;
    }
    free(tmp);
}

void inicia(node *Lista){
    Lista->prox = NULL;
    Lista->num = NULL;
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
        remove(Lista);
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