# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define tam 7

struct dados
{
  int info;
  struct dados *prox;
};

typedef struct dados Dados;
typedef Dados* Hash[tam];

int funcaoHash(int num);
void inicializaHash(Hash tab); 
void insereHash(Hash tab,int num);
int buscaHash(Hash tab, int num);
void imprimeHash(Hash tab);
void removeHash(Hash tab, int num);
float porcentagemHash(Hash tab);
void indiceColisao(Hash tab);
int quantidadeColisao(Hash tab);
int quantidadeElementos(Hash tab);
void posicoesVazias(Hash tab);
void imprimeColisao(Hash tab, int pos);
void opcao(Hash tab, int op);
int menu(void);


int funcaoHash(int num)
{
  return(num%tam);
}


void inicializaHash(Hash tab)
{
 int i;
 for(i = 0; i < tam; i++)
 {
  tab[i] = NULL;
 }
}


void insereHash(Hash tab, int num)
{
 
 int chave = funcaoHash(num);
 Dados* aux = tab[chave];
 while(aux != NULL)
 {
  if(aux->info == num)
  {
   break;
  }
  aux = aux->prox;
 }
 if(aux == NULL)
 {
  aux = (Dados*)malloc(sizeof(Dados));
  aux->info = num;
  aux->prox = tab[chave];
  tab[chave] = aux;
  
 }
}

void imprimeHash(Hash tab)
{
 int  i = 0;
 for(i = 0; i < tam; i++)
 {
  if(tab[i] != NULL)
  {
   printf("\n %d",tab[i]->info);
   Dados* aux =tab[i]->prox;
   while(aux!=NULL)
   {
    printf(" -> %3d",aux->info);
     aux=aux->prox;
   }
  }
 }
}
 

void removeHash(Hash tab, int num)
{
 
 int chave = funcaoHash(num);
 Dados* aux = tab[chave];
 Dados *ant = tab[chave];
 while(aux != NULL)
 {
  if(aux->info == num)
  {
   break;
  }
  ant = aux ;
  aux = aux->prox;
 }
 if(aux != NULL)
        { if (aux == ant) tab[chave] = ant->prox ; 
                       else 
                       ant->prox = aux->prox ;
  
	    }
}

int buscaHash(Hash tab,int num)
{ Dados* aux = tab[num];
  int busca = 0 ;
  while(aux != NULL)
       if (aux->info  == num) { busca = 1 ; break ;}
                    else  aux = aux->prox;
   return(busca);
 }

// Exercicio 5 
float porcentagemHash(Hash tab)
{
 int i;
 float porcent = 0, cont  = 0;
 for(i = 0; i < tam; i++)
 {
  if(tab[i] != NULL)
  {
   cont++;
  }
 }
 porcent = (cont*100)/tam;
 return(porcent);
}

// Exercicio6
void indiceColisao(Hash tab)
{
 int i;
 printf("\nOcorreram colisoes nas posicoes\n");
 for(i = 0 ; i< tam; i++)
 {
  if(tab[i] != NULL && tab[i]->prox)
  {
   printf("%d\t",i);
  }
 }
 return;
}

// Exercicio7
int quantidadeColisao(Hash tab)
{
 int i, cont = 0;
 for(i = 0; i < tam; i++)
 {
  Dados* aux = tab[i];
  if(aux != NULL)
  {
    while(aux->prox != NULL)
    {
     cont++;
     aux = aux->prox;
    }
  }
 }
 return cont;
}

// Exercicio8
int quantidadeElementos(Hash tab)
{
 int i, cont = 0;
 for(i = 0; i < tam; i++)
 {
  Dados* aux = tab[i];
  if(aux != NULL)
  { cont++;
    while(aux->prox != NULL)
    {
     cont++;
     aux = aux->prox;
    }
  }
 }
 return cont;
}


/*O procedimento posicaoVazias mostra todas as posicoes que apos a insercao
continuam nulas.*/

void posicoesVazias(Hash tab)
{
 int i, cont = 0;
 printf("Posicoes Vazias\n");
 for(i = 0; i < tam; i++)
 {
  if(tab[i] == NULL)
  {
   printf("%d\t",i);
   cont++;

  }
 }
 printf("\nTotal de posicoes vazias = %d",cont);
}

/*O procedimento imprimeColisaon mostra uma posicao
e todas as suas colisoes.*/

void imprimeColisao(Hash tab, int pos)
{
 Dados* aux = tab[pos];
 if(aux == NULL)
 {
  printf("Esta posicao esta vazia!");
  return;
 }else
 {
  if(aux != NULL)
  {
   printf("%3d",aux->info);
   while(aux->prox != NULL)
   {
    printf(" -> %d",aux->prox->info);
    aux = aux->prox;
   }
  }
 }
}


 int menu(void)
{
	int opt;
	printf("\n\n\n");
	printf("Escolha a opcao\n");
	
	printf("1. Exibir Tabela Hash\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Remover No\n");
	printf("4. Qtde de Elementos\n");
	printf("5. Busca\n");
	printf("6. Sair\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

void opcao(Hash tab, int op)
{   int x ;
	switch(op){	
			
		case 1:
			imprimeHash(tab);
			break;
		
		case 2:
		    printf("Novo elemento: "); 
		    scanf("%d", &x);
			insereHash(tab,x);
			break;
		
		case 3:
		    printf("Elemento a ser Removido: "); 
		    scanf("%d", &x);
			removeHash(tab,x);
			break;		
			
		case 4:
			printf("\n Qtde de Elementos :%d ",quantidadeElementos(tab));
			break;
			
		case 5:
			 printf("Elemento: "); 
		    scanf("%d", &x);
			printf(" busca = %d ",buscaHash(tab,x));
			break;		
			
		
		default:
			printf("Comando invalido\n\n");
	}
}


