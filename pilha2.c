#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define type int


typedef struct stackNode
{
  type valor;
  struct stackNode *next;
}node;

typedef struct pilhas
{
  int size;
  node *no;
}pilha;


int esta_vazia(pilha *stack)
{
  if(stack->no==NULL)
    return TRUE;
  else
    return FALSE;
}

void push(pilha *stack,type valor)
{
  node *aux;
  aux=(node*)malloc(sizeof(node));
  aux->valor=valor;
  aux->next=NULL;
  if(stack->size==0)
    stack->no=aux;
  else
  {
    node *ptr=stack->no;
    while(ptr->next!=NULL)
      ptr=ptr->next;
    ptr->next=aux;
  }
  stack->size++;
}

int pop(pilha *stack)
{
    int retorno;
    node *ptr=stack->no;
    if(stack->size==1)
    {
          retorno=stack->no->valor;
          stack->no=NULL;
          stack->size=0;
    }
    else
    {
        while(ptr->next->next!=NULL)
            ptr=ptr->next;
        retorno=ptr->next->valor;
        ptr->next=NULL;
        stack->size--;
    }
    return retorno;
}

void terminarpilha(pilha *stack)
{
    node* ptr=stack->no;
    node* ptr1=ptr->next;
    while(ptr!=NULL)
    {
      free(ptr);
      ptr=ptr1;
      ptr1=ptr1->next;
    }
}

void print_stack(pilha *stack)
{
  node* ptr=stack->no;
  while(ptr!=NULL)
  {
    printf("%d ",ptr->valor);
    ptr=ptr->next;
  }
  printf("\n");
}

int maiorvalor(pilha *stack)
{
  type maior,atual;
  node *ptr=stack->no;
  maior=ptr->valor;
  while(ptr!=NULL)
  {
      atual=ptr->valor;
      if(atual>maior)
          maior=atual;
      ptr=ptr->next;
  }
  free(ptr);
  return maior;
}

int main(void)
{
  int operacao,valor,aux,i;
  operacao=0;
  valor=0;
  aux=0;
  i=0;
  pilha *stack=malloc(sizeof(pilha));
  stack->size=0;
  stack->no=NULL;
  scanf("%d",&aux);
  while(i<aux)
  {
     scanf("%d",&operacao);
     if(operacao==1)
     {
         scanf("%d",&valor);
         push(stack,valor);
     }
     else if(operacao==2)
     {
         valor=pop(stack);
     }
     else if(operacao==3)
     {
         valor=maiorvalor(stack);
         printf("%d\n",valor);
     }
     i++;
  }
  return 0;
}
