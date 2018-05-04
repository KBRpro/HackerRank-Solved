#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int* data;
  int  maxvalue;
} set;

set* new_set(int maxvalue)
{
    int i;
    set *aux;
    aux=malloc(sizeof(set));
    aux->maxvalue=maxvalue;
    aux->data=(int*)malloc(sizeof(int)*maxvalue);
    for(i=0;i<maxvalue;i++)
        aux->data[i]=0;
    return aux;

}


set* set_inter(set* A, set* B)
{
    int i,j,maxvalueC;
    i=0;
    j=0;

    if(A->maxvalue<=B->maxvalue)
        maxvalueC=A->maxvalue;
    else
        maxvalueC=B->maxvalue;
    set *aux=new_set(maxvalueC);
    for(i=0;i<maxvalueC;i++)
    {
        if(A->data[i]==1 && B->data[i]==1)
            aux->data[i]=1;
    }
    return aux;
}

set* set_union(set* A, set* B)
{
    int i,j,maxvalueC;
    i=0;
    j=0;

    if(A->maxvalue>=B->maxvalue)
        maxvalueC=A->maxvalue;
    else
        maxvalueC=B->maxvalue;
    set *aux=new_set(maxvalueC);
    for(i=0;i<A->maxvalue;i++)
    {
        if(A->data[i]==1)
                aux->data[i]=1;
    }
    for(i=0;i<B->maxvalue;i++)
    {
        if(B->data[i]==1)
            aux->data[i]=1;
    }
    return aux;
}


void set_print(set* s)
{
    int i;
    i=0;
    for(i=0;i<=s->maxvalue;i++)
    {
      if(s->data[i]==1)
            printf("%d ",i);
    }
    printf("\n");
}

void read_set(set* s, int seqsize)
{
    int i,valor;
    i=0;
    while(i<seqsize)
    {
        scanf("%d",&valor);
        s->data[valor]=1;
        i++;
    }
}

void set_free(set* s)
{
    free(s->data);
    free(s);
}

int main()
{
  // Numero de elementos a serem inseridos no conjunto
  int seqsize;
  // Maior numero que aparecerá na sequência
  int maxval;

  // Lê o tamanho da sequencia e o maior valor para o conjunto A
  scanf("%d %d", &seqsize, &maxval);

  set* A = new_set(maxval);
  read_set(A, seqsize);
  set_print(A);

  // Lê o tamanho da sequencia e o maior valor para o conjunto B
  scanf("%d %d", &seqsize, &maxval);

  set* B = new_set(maxval);
  read_set(B, seqsize);
  set_print(B);

  set* C = set_inter(A, B);
  set_print(C);

  set* D = set_union(A, B);
  set_print(D);

  set_free(A);
  set_free(B);
  set_free(C);
  set_free(D);
}
