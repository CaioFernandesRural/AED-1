#include "bancoPilha.h"

/*
a) cada cliente do banco possui os seguintes dados : nome . endereço, telefone , cpf e saldo.
b) Para fazer um saque é necessário que o cliente tenha saldo suficiente.
Fazer um programa em C para :
a) Verificar se um cliente está cadastrado ou não.
b) fazer retirada de uma determinada quantia de um cliente ;
c) Inserir um novo cliente ;
d) retirar um cliente.
*/

void main(){

    Pilha *clientes = (Pilha*) malloc (sizeof(Pilha));
    int capacidade;

    printf("\nCapacidade da Pilha: ");
    scanf("%d",&capacidade);

    criarPilha(clientes, capacidade);

    menu(clientes);
}