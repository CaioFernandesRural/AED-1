#include <stdio.h>
#include <stdlib.h>



typedef struct {
    int cpf ; 
    char nome[50];
    char endereco[50];
    char tel[10];
    float saldo;
}TCliente; 

typedef struct {
int capacidade;
TCliente *dados;
int topo;
} Pilha ;

void criarPilha( Pilha *f, int c );
int inserir( Pilha *f, TCliente v);
int busca(Pilha *f, int cpf);
int retirarSaldo(Pilha *f, int cpf, float quantia);
TCliente desempilhar(Pilha *f);
void imprimeCliente(Pilha *f);
TCliente criarCliente(TCliente c);

int main() // melhorar o principal
{ Pilha *f = (Pilha*) malloc (sizeof(Pilha));;
  TCliente cl ;
	
	int i , c;
	printf("\n capacidade: ");
	scanf("%d", &c);
	criarPilha(f,c);
	
	
	for(i=0;i<3;i++){
	cl = criarCliente(cl);
	inserir(f,cl);}
	imprimeCliente(f);
	//printf("\n busca = %d",busca(f,2));
	//retirarSaldo(f, 1, 50);
	//imprimeCliente(f);
	desempilhar(f);
	imprimeCliente(f);
	desempilhar(f);
	imprimeCliente(f);
	return(1);
}


void menu(void){
	printf("\n  1. MOSTRAR Pilha");
	printf("\n  2. BUSCAR CLIENTE");
	printf("\n  3. SAQUE ");
	printf("\n  4. DEPOSITO ");
	printf("\n  5. INSERIR NOVO CLIENTE");
	printf("\n  6. RETIRAR CLIENTE ");
	printf("\n  7. SAIR ");
	printf("\n  Digite a Opcao desejada :");
};

 void criarPilha( Pilha *f, int c ) {
f->capacidade = c;
f->dados = (TCliente*) malloc (f->capacidade * sizeof(TCliente));
f->topo = -1 ;
} 

TCliente criarCliente(TCliente c) { 
  printf("\n Entrar com dados do Cliente(cpf,nome, endereco, telefone, saldo):\n");
  scanf("%d",&c.cpf );
  scanf("%s",c.nome);
  scanf("%s",c.endereco);
  scanf("%s",c.tel);
  scanf("%f",&c.saldo );	
  return(c);
}

int inserir( Pilha *f, TCliente v) {
if(f->topo < f->capacidade-1)
            {f->topo++;
             f->dados[f->topo] = v;
             return(1);}
             else return (0);
}	

int busca(Pilha *f , int cpf) { 
int i = 0 , res = -1 ;
for (i=0;i<f->topo+1;i++)
    if (f->dados[i].cpf == cpf ) 
            { res = i ;				  
              break ;
		    }  
				  		
return (res) ;
}	

// a funcao retorna 1 se a retirada foi possivel , -1 se nao encontrou o cliente e -2 caso nao tenha saldo	
int retirarSaldo(Pilha *f, int cpf, float quantia) {
    int  res ;
    res = busca(f,cpf);
    if (res == -1) return -1;
                  else 
                  if (f->dados[res].saldo >= quantia) 
                         { f->dados[res].saldo -= quantia ;   
						   return(1);}
						   else return(-2);
}						   
	
     

TCliente desempilhar ( Pilha *f ){
TCliente aux = f->dados [f->topo];
f->topo--;
return aux;
}

void imprimeCliente(Pilha *f) {
    int i ;
    printf("\n IMPRIME CLIENTE");
     for (i=0;i<f->topo+1;i++) {
       printf("\n #### Cliente ####");;  
       printf("\n %d", f->dados[i].cpf);  
	   printf("\n %s", f->dados[i].nome) ;
	   printf("\n %s", f->dados[i].endereco);
	   printf("\n %s", f->dados[i].tel);
	   printf("\n %f", f->dados[i].saldo);  
	    printf("\n \n ");  
     }
    
}


