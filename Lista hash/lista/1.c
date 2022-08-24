#include <stdio.h>
#include <stdlib.h>

#define tam 23

struct dados
{
    int info;
    struct dados *prox;
}; //struct do nó

typedef struct dados Dados;
typedef Dados* Hash[tam]; //declaração de um array contendo nós

int funcHash(int num){
    return (num % tam); //função que retorna o codigo hash
}
void inicializaHash(Hash tab){
    for (int i = 0; i < tam; i++){
        tab[i] = NULL; 
    }
    //inicia todos os headers da tabela hash
}

void insereHash(Hash tab, int x){
    int chave = funcHash(x);//gera a chave hash a partir de x
    Dados* tmp = tab[chave];//ponteiro temporario para percorrer
                            // a lista da posição

    while (tmp != NULL){ //percorre até o final
        if (tmp->info == x){
            break; //para no caso de elemento repetido
        }
        tmp = tmp->prox;
    }
    if (tmp == NULL) //so insere se estiver no final
    {                //ou seja, sem elementos repetidos
        tmp = (Dados*) malloc(sizeof(Dados));
        tmp->info = x;
        tmp->prox = tab[chave];
        tab[chave] = tmp;
        //insere no começo
    }   
}

void imprime(Hash tab){

    for (int i = 0; i < tam; i++){ //percorre a hash
        if(tab[i] != NULL){ //se não for uma lista vazia
            printf("\n %d", tab[i]->info); //imprime o primeiro el.
            
            Dados* tmp = tab[i]->prox;
            while (tmp != NULL){ //imprime todos
                printf(" -> %3d", tmp->info);
                tmp = tmp->prox;
            }    
        }
    }
}

void removeHash(Hash tab, int x){

    int chave = funcHash(x);
    Dados* tmp = tab[chave];
    Dados* ant = tab[chave]; //estará sempre um nó atrás do tmp
    
    while(tmp != NULL){
        if (tmp->info == x){ //percorre até achar o x
            break;
        }
        ant = tmp; //ant -> tmp
        tmp = tmp->prox;
    }
    if (tmp != NULL){
        if (tmp == ant){ //um elemento só
            tab[chave] = ant->prox;
        }
        else{//pula o elemento que está entre o ant e o tmp->prox
            ant->prox = tmp->prox;
        }
    }
}

void buscaHash(Hash tab, int x){ //recebe uma posição
    
    if(x > tam || x < 0){ //posições inválidas
        printf("\nPosicao nao encontrada!");
        return;
    } else{
        imprimeColi(tab, x);
    }
}

void imprimeColi(Hash tab, int pos){
    
    Dados* tmp = tab[pos];

    if(tmp == NULL){
        printf("\nLista vazia!");
        return;
    } else{
        if(tmp != NULL){
            printf("%3d", tmp->info); //imprime o primeiro
            while (tmp != NULL){ //percorre a lista
                printf(" -> %d", tmp->info);
                tmp = tmp->prox;
            }
        }
    }
}

int menu(){
    int op;
    printf("\n\n");
    printf("Escolha a opcao\n");	
	printf("1. Exibir Tabela Hash\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Remover No\n");
	printf("4. Sair\n");
	printf("Opcao: ");
    fflush(stdin);
    scanf("%d", &op);

    return op;
}

void funcs(Hash tab, int op){
    int x;
    switch(op){

        case 1:
            imprime(tab);
            break;
        case 2:
            printf("\nNovo elemento: ");
            fflush(stdin);
            scanf("%d", &x);
            insereHash(tab, x);
            break;
        case 3:
            printf("\nElemento a ser Removido: ");
            fflush(stdin);
            scanf("%d", &x);
            removeHash(tab,x);
            break;	
        default:
            printf("Comando invalido\n");
    }
}

int main(void){
    Hash HASH;
    int opt;
    inicializaHash(HASH);

    do
    {
        opt = menu();
        funcs(HASH, opt);
    } while(opt != 4);

    return 0;
}