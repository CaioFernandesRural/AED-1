#include "lista_encadeada_prova.h"

int main(void)
{
	node *LISTA = (node *) malloc(sizeof(node));
	node *LISTAO = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	
	if(!LISTAO){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	
	inicia(LISTA);inicia(LISTAO);
	int opt;
	
	do{
		opt=menu();
		opcao(LISTA,LISTAO,opt);
		
		
	}while(opt!=99);

	free(LISTA);
	return 0;
}
