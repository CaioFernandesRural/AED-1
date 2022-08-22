#include <stdio.h>
#include <stdlib.h>
#define M 7
#define n (2*M)


typedef struct {
   int  chave;
   int  prox ;
} Objeto;


int hash(int num)
{
  return(num%M);
}

void STinit(Objeto *tab,int max) 
{ 
   int h;
   max = 2 * M ;
   for (h = 0; h < max; h++) 
      tab[h].chave = 0 ; 
}

void inserir(Objeto *tab, int v) 
{ 
   
	int h = hash(v);
	while (tab[h].chave != 0){
    	h = (h + 1) % M;
	}
	tab[h].chave = v;
}

void imprimir(Objeto *tab,int tam) 
{ int i ;
	
	for (i=0;i<tam;i++)
	printf(" \n chave  %d : %d",i,tab[i].chave);
   
   
 }


Objeto busca(Objeto *tab, int v) 
{ 
   int h = hash(v);
   while (tab[h].chave != 0) 
      if (tab[h].chave == v) return tab[h];
      else h = (h + 1) % M;
   //return objetonulo;
}

int menu(void)
{
	int opt;
	printf("\n\n\n");
	printf("Escolha a opcao\n");	
	printf("1. Exibir Tabela Hash\n");
	printf("2. Adicionar Elemento\n");
	printf("3. Remover No\n");
	printf("4. Qtde de Elementos\n");
	printf("5. Sair\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

void opcao(Objeto *tab, int op)
{   int x ;
	switch(op){	
			
		case 1:
			imprimir(tab,n);
			break;
		
		case 2:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			inserir(tab,x);
			break;
		
		case 3:
		    printf("Elemento a ser Removido: "); 
		    scanf("%d", &x);
			//removeHash(tab,x);
			break;		
			
		case 4:
			//printf("\n Qtde de Elementos :%d ",quantidadeElementos(tab));
			break;
			
		case 5:
			//libera(LISTA);
			break;
		
		default:
			printf("Comando invalido\n\n");
	}
}

int main(void)
{
	Objeto *tab ;
	int opt;
	tab = (Objeto *) malloc (n*sizeof(Objeto));
	STinit(tab,n);
	
	do{
		opt=menu();
		opcao(tab,opt);
	}while(opt!=5);

	return 0;
}
