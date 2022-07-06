#ifndef __BANCOPILHA__
#define __BANCOPILHA__

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    char endereco[50];
    int telefone[10];
    int cpf;
    float saldo;
} TCliente;
typedef struct {
    int capacidade;
    TCliente *dados;
    int topo;
} Pilha ;

void criarPilha( Pilha *f, int c){
    f->capacidade = c;
    f->dados = (TCliente*) malloc(f->capacidade * sizeof(float));
    f->topo = -1;
}

int acharCadastro(Pilha *f, int cpf){
    for (int i = 0; i < f->topo ; i++)
    {
        if (f->dados[i].cpf == cpf){
            return i;
            break;
        }
        else {return -1;}
    }
}
void verificarCadastro(Pilha *f){
    int cpf;

    printf("\n\nCPF : ");
    scanf("%d",&cpf);

    if (acharCadastro(f, cpf) == -1){
        printf("\ncadastro nao encontrado");
    } else{
        printf("\nCadastro existente");
    }
}
void sacar(Pilha *f){
    float saque; int cpf;

    printf("\nCPF : ");
    scanf("%d",&cpf);

    int busca = acharCadastro(f, cpf);

    if (busca == -1){
        printf("\ncadastro nao encontrado");
    } 
    else {
        printf("\n\nQuantia do saque: ");
        scanf("%f",&saque);
        if (saque > f->dados[busca].saldo)
        {
            printf("\nSaque maior que o saldo atual.");
        } else {
            f->dados[busca].saldo -= saque;
        }
    }
}
int novoCadastro(Pilha *f){

    if(f->topo >= f->capacidade - 1){
        printf("\nNao ha espaço para um cliente novo.");
        return 0;
    }
    else {
        f->topo ++;
        printf("\nNome: ");
        fflush(stdin);
        gets(f->dados[f->topo].nome);
        printf("\nEndereço: ");
        fflush(stdin);
        gets(f->dados[f->topo].endereco);
        printf("\nTelefone: ");
        fflush(stdin);
        scanf("%d",&f->dados[f->topo].telefone);
        printf("\nCPF: ");
        fflush(stdin);
        scanf("%d",&f->dados[f->topo].cpf);
        printf("\nSaldo: ");
        fflush(stdin);
        scanf("%d",&f->dados[f->topo].saldo);

        return 1;
    }
}
int removerCadastro(Pilha *f){
    f->topo --;
}
void menu(Pilha *f){
    int esc;

    while (1 > 0){
        printf("\n\n1-Verificar cadastro");
        printf("\n2-Saque");
        printf("\n3-Novo cadastro");
        printf("\n4-Retirar último cadastro");
        printf("\n5-Sair");
        printf("\nEscolha: ");
        scanf("%d",&esc);

        if (esc == 1){verificarCadastro(f);}
        else if (esc == 2) {sacar(f);}
        else if (esc == 3) {novoCadastro(f);}
        else if (esc == 4) {removerCadastro(f);}
        else {break;}        
    }
}

#endif

