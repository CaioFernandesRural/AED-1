#include <stdio.h>
#include <stdlib.h>

#define tam 7

struct dados
{
    int info;
    struct dados *prox;
};

typedef struct dados Dados;
typedef Dados* Hash[tam];
