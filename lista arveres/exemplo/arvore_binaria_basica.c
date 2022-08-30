#include <stdio.h>
#include <stdlib.h>

struct no
{
  int info;
  struct no *esq;
  struct no *dir;
};
typedef struct no no;

void pre_ordem(no *pt)
{
  printf("\n %d ", pt->info);
  if (pt->esq != NULL)
    pre_ordem(pt->esq);
  if (pt->dir != NULL)
    pre_ordem(pt->dir);
}

no *busca_arvore(no *pt, int x, int *f)
{
  if (pt == NULL)
  {
    *f = 0;
    return (NULL);
  }
  else if (pt->info == x)
  {
    *f = 1;
    return (pt);
  }
  else if (pt->info > x)
    if (pt->esq == NULL)
    {
      *f = 2;
      return (pt);
    }

    else
    {
      pt = pt->esq;
      busca_arvore(pt, x, f);
    }
  else if (pt->dir == NULL)
  {
    *f = 2;
    return (pt);
  }

  else
  {
    pt = pt->dir;
    busca_arvore(pt, x, f);
  }
}

no *insercao(no *pt, int x)
{
  no *pt1, *pt2;
  int f;
  pt1 = busca_arvore(pt, x, &f);

  if (f == 1)
  {
    printf("inserao Invalida");
    return (NULL);
  }
  else
  {
    pt2 = malloc(sizeof(no));
    pt2->info = x;
    pt2->esq = NULL;
    pt2->dir = NULL;
    if (f == 0)
    {
      return (pt2);
      printf("\n 2 %d f= ", f);
    }
    else if (f == 2)
    {
      if (x < pt1->info)
        pt1->esq = pt2;
      else
        pt1->dir = pt2;
      return (pt2);
    }
  }
}

no *deletar_no(no *r, int x)
{
  no *pt, *pt1;
  if (r == NULL)
    return (NULL);
  else if (r->info == x)
  {
    if (r->esq == r->dir)
    {
      free(r);
      return (NULL);
    }

    else if (r->esq == NULL)
    {
      pt = r;
      r = r->dir;
      free(pt);
      return (r);
    }
    else if (r->dir == NULL)
    {
      pt = r;
      r = r->esq;
      free(pt);
      return (r);
    }
    else if ((r->esq)->esq == (r->dir)->dir)
    {
      r->info = (r->esq)->info;
      free(r->esq);
      r->esq = NULL;
    }

    else
    {
      pt = r;
      pt1 = r->esq;
      if (pt1->dir == NULL)
      {
        r->info = pt1->info;
        r->esq = pt1->esq;
        free(pt1);
      }
      else
      {
        while (pt1->dir != NULL)
        {
          pt = pt1;
          pt1 = pt1->dir;
        }

        r->info = pt1->info;
        pt->dir = pt1->esq;
        free(pt1);
      }
    }
  }

  if (r->info > x)
    r->esq = deletar_no(r->esq, x);
  else
    r->dir = deletar_no(r->dir, x);
  return (r);
}

int main()
{
  no *raiz = NULL, *aux;
  int f, op = 1, elem;

  while (op < 5)
  {
    printf("\n\n\n\n Arvore Bin'aria de Busca \n");
    printf("1.BUSCA \n");
    printf("2.INSERIR\n");
    printf("3.REMOVER \n");
    printf("4.IMPRIMIR \n");
    printf("5.SAIR \n");
    printf(" opcao: ");
    scanf("%d", &op);

    if (op == 1)
    {
      printf("\n Elemento:");
      scanf("%d", &elem);
      aux = busca_arvore(raiz, elem, &f);
      if (f == 1)
        printf("\v %d f=  %d ELEMENTO ENCONTRADO !!! ", aux->info, f);
      else
        printf("\n ELEMENTO NAO ENCONTRADO !!!");
    }
    if (op == 2)
    {
      printf("\n Elemento:");
      scanf("%d", &elem);
      if (raiz == NULL)
        raiz = insercao(raiz, elem);
      else
        insercao(raiz, elem);
      printf("\n ELEMENTO INSERIDO !!! ");
    }
    if (op == 3)
    {
      printf("\n Elemento:");
      scanf("%d", &elem);
      busca_arvore(raiz, elem, &f);
      if (f == 1)
      {
        raiz = deletar_no(raiz, elem);
        printf("\n ELEMENTO REMOVIDO !!! ");
      }
      else
        printf("\n ELEMENTO NAO ENCONTRADO !!! ");
    }
    if (op == 4)
    {
      if (raiz != NULL)
        pre_ordem(raiz);
      else
        printf("\n ARVORE VAZIA !!! ");
    }
  }

  return (0);
}
