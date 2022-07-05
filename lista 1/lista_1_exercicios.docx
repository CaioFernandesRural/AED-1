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
int ultimo;
} Lista ;

void criarLista( Lista *f, int c );
int inserir( Lista *f, TCliente v);
int busca(Lista *f, int cpf);
int retirarSaldo(Lista *f, int cpf, float quantia);
int retirarCliente(Lista *f,int cpf);
void imprimeCliente(Lista *f);

int main() // melhorar o principal
{ Lista *f = (Lista*) malloc (sizeof(Lista));;
  TCliente cl ;
	
	int c;
	printf("\n capacidade: ");
	scanf("%d", &c);
	criarLista(f,c);
	cl.cpf = 01 ;
	cl.saldo = 100;
	inserir(f,cl);
	imprimeCliente(f);
	printf("\n busca = %d",busca(f,1));
	retirarSaldo(f, 1, 50);
	retirarCliente(f,1);
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

 void criarLista( Lista *f, int c ) {
f->capacidade = c;
f->dados = (TCliente*) malloc (f->capacidade * sizeof(TCliente));
f->ultimo = -1 ;
} 


int inserir( Lista *f, TCliente v) {
if(f->ultimo < f->capacidade-1)
            {f->ultimo++;
             f->dados[f->ultimo] = v;
             return(1);}
             else return (0);
}	

int busca(Lista *f , int cpf) { 
int i = 0 , res = -1 ;
for (i=0;i<f->ultimo+1;i++)
    if (f->dados[i].cpf == cpf ) 
            { res = i ;				  
              break ;
		    }  
				  		
return (res) ;
}	

// a funcao retorna 1 se a retirada foi possivel , -1 se nao encontrou o cliente e -2 caso nao tenha saldo	
int retirarSaldo(Lista *f, int cpf, float quantia) {
    int  res ;
    res = busca(f,cpf);
    if (res == -1) return -1;
                  else 
                  if (f->dados[res].saldo >= quantia) 
                         { f->dados[res].saldo -= quantia ;   
						   return(1);}
						   else return(-2);
}						   
	
			   
				     
int retirarCliente(Lista *f ,int cpf) {		
	int i = 0, res ;
    res = busca(f,cpf);
    if (res == -1) return -1;
        else 
       { for (i=res;i<f->ultimo-1;i++)
         f->dados[i] = f->dados[i+1];	
         f->ultimo -- ;
         return 1 ;                        
       }				       
}

void imprimeCliente(Lista *f) {
    int i ;
    printf("\n IMPRIME CLIENTE");
     for (i=0;i<f->ultimo+1;i++) 
     { printf("\n %d", f->dados[i].cpf);  
	   printf("\n %s", f->dados[i].nome) ;
	   printf("\n %s", f->dados[i].endereco);
	   printf("\n %s", f->dados[i].tel);
	   printf("\n %f", f->dados[i].saldo);  
	    printf("\n \n ");  
     }
    
}


