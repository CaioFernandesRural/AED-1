#ifndef __BANCOLISTA__
#define __BANCOLISTA__

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
    int ultimo;
} Lista ;

void criarLista( Lista *f, int c){
    f->capacidade = c;
    f->dados = (TCliente*) malloc(f->capacidade * sizeof(float));
    f->ultimo = -1;
}

int acharCadastro(Lista *f, int cpf){
    for (int i = 0; i <= f->ultimo ; i++)
    {
        if (f->dados[i].cpf == cpf){
            return i;
            break;
        }
        else {return -1;}
    }
}
void verificarCadastro(Lista *f){
    int cpf;

    printf("\n\nCPF : ");
    scanf("%d",&cpf);

    if (acharCadastro(f, cpf) == -1){
        printf("\ncadastro nao encontrado");
    } else{
        printf("\nCadastro existente");
    }
}
void sacar(Lista *f){
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
int novoCadastro(Lista *f){

    if(f->ultimo >= f->capacidade - 1){
        printf("\nNao ha espaço para um cliente novo.");
        return 0;
    }
    else {
        f->ultimo ++;
        printf("\nNome: ");
        fflush(stdin);
        gets(f->dados[f->ultimo].nome);
        printf("\nEndereço: ");
        fflush(stdin);
        gets(f->dados[f->ultimo].endereco);
        printf("\nTelefone: ");
        fflush(stdin);
        scanf("%d",&f->dados[f->ultimo].telefone);
        printf("\nCPF: ");
        fflush(stdin);
        scanf("%d",&f->dados[f->ultimo].cpf);
        printf("\nSaldo: ");
        fflush(stdin);
        scanf("%d",&f->dados[f->ultimo].saldo);

        return 1;
    }
}
int removerCadastro(Lista *f){
    int cpf;
    printf("\nCPF : ");
    scanf("%d",&cpf);
    int busca = acharCadastro(f, cpf);

    if (busca == -1) {return -1;}
    else {
        for (int i = busca; i < f->ultimo; i++)
        { //desloca todos a partir da busca para trás e diminui o último.
            f->dados[i] = f->dados[i+1];
            f->ultimo --;
            return 1;
        }
    }
}
void menu(Lista *f){
    int esc;

    while (1 > 0){
        printf("\n\n1-Verificar cadastro");
        printf("\n2-Saque");
        printf("\n3-Novo cadastro");
        printf("\n4-Retirar cadastro");
        printf("\n5-Sair");
        printf("\nEscolha: ");
        scanf("%d",&esc);

        if (esc == 1){verificarCadastro(f);}
        else if (esc == 2) {sacar(f);}
        else if (esc == 3) {novoCadastro(f);}
        else {break;}        
    }
}

#endif

