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
int primeiro ;
int ultimo;
int nItens ;
} Fila;

void criarLista( Fila*f, int c );
int inserir( Fila*f, TCliente v);
int busca(Fila*f, int cpf);
int retirarSaldo(Fila*f, int cpf, float quantia);
TCliente retirarCliente(Fila*f);
void imprimeCliente(Fila*f);
TCliente criarCliente(TCliente c);

int main() // melhorar o principal
{ Fila*f = (Fila*) malloc (sizeof(Fila));;
  TCliente cl ;
	
	int i , c;
	printf("\n capacidade: ");
	scanf("%d", &c);
	criarLista(f,c);
	
	
	for(i=0;i<3;i++){
	cl = criarCliente(cl);
	inserir(f,cl);}
	imprimeCliente(f);
	//printf("\n busca = %d",busca(f,2));
	//retirarSaldo(f, 1, 50);
	//imprimeCliente(f);
	retirarCliente(f);
	imprimeCliente(f);
	return(1);
}


void menu(void){
	printf("\n  1. MOSTRAR LISTA");
	printf("\n  2. BUSCAR CLIENTE");
	printf("\n  3. SAQUE ");
	printf("\n  4. DEPOSITO ");
	printf("\n  5. INSERIR NOVO CLIENTE");
	printf("\n  6. RETIRAR CLIENTE ");
	printf("\n  7. SAIR ");
	printf("\n  Digite a Opcao desejada :");
};

 void criarLista( Fila*f, int c ) {
f->capacidade = c;
f->dados = (TCliente*) malloc (f->capacidade * sizeof(TCliente));
f->ultimo = -1 ;
f->primeiro = -1 ;
f->nItens = 0 ;
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

int inserir( Fila*f, TCliente v) {
int prov ;
if(f->nItens < f->capacidade){
             
             prov = f->ultimo % f->capacidade + 1 ;
             if (prov != f->primeiro) {
				        if (f->nItens == 0) f->primeiro = 0 ;
						f->ultimo = prov ; 
						f->nItens ++ ;
						f->dados[f->ultimo] = v;
						return(1);}}
             else return (0);
}	

int busca(Fila*f , int cpf) { 
int i = 0 , res = -1 ;
for (i=0;i<f->ultimo+1;i++)
    if (f->dados[i].cpf == cpf ) 
            { res = i ;				  
              break ;
		    }  
				  		
return (res) ;
}	

// a funcao retorna 1 se a retirada foi possivel , -1 se nao encontrou o cliente e -2 caso nao tenha saldo	
int retirarSaldo(Fila*f, int cpf, float quantia) {
    int  res ;
    res = busca(f,cpf);
    if (res == -1) return -1;
                  else 
                  if (f->dados[res].saldo >= quantia) 
                         { f->dados[res].saldo -= quantia ;   
						   return(1);}
						   else return(-2);
}						   
	
			   
				     
TCliente retirarCliente(Fila*f ) {		
	int i = 0, res ;
	TCliente recuperado ;
	printf("%d %d %d",f->primeiro, f->ultimo,f->nItens);
    if (f->nItens != 0 ) {
        recuperado = f->dados[f->primeiro];
        
        if (f->ultimo == f->primeiro) {
			        f->ultimo = -1 ;
			        f->primeiro = -1 ;}
		            else 
		            f->primeiro = f->primeiro % f->capacidade + 1 ;
				}
		 else printf("FILA VAZIA");   
                             
     return (recuperado);				       
}

void imprimeCliente(Fila*f) {
    int i ;
    printf("\n IMPRIME CLIENTE");
     for (i=f->primeiro;i<f->ultimo+1;i++) {
       printf("\n #### Cliente ####");;  
       printf("\n %d", f->dados[i].cpf);  
	   printf("\n %s", f->dados[i].nome) ;
	   printf("\n %s", f->dados[i].endereco);
	   printf("\n %s", f->dados[i].tel);
	   printf("\n %f", f->dados[i].saldo);  
	    printf("\n \n ");  
     }
    
}


