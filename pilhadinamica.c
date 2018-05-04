#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define type int


typedef struct stackNode
{
  int valor;
  struct stackNode *next;
}node;

typedef struct pilhas
{
  int size;
  node *no;
}pilha;

pilha inic_pilha(pilha *stack)
{
  pilha *aux=malloc(sizeof(pilha));
  aux->size=0;
  aux->no=NULL;
  return *aux;
}

int esta_vazia(pilha *stack)
{
  if(stack->no==NULL)
    return TRUE;
  else
    return FALSE;
}

node interagir(pilha *stack)
{
  node *aux;
  *aux=*stack->no;
  return *aux;
}

void push(pilha *stack,type valor)
{
  node *aux;
  aux=(node*)malloc(sizeof(node));
  aux->valor=valor;
  aux->next=NULL;
  if(esta_vazia(stack)==TRUE)
  {
    stack->no=aux;
    stack->size++;
  }
  else
  {
    while(stack->no->next!=NULL)
    {
      stack->no=stack->no->next;
    }
    stack->no->next=aux;
    stack->size++;
  }
}

int pop(pilha *stack)
{
      int retorno;
      node *aux;
      *aux=interagir(stack);
      while(aux->next!=NULL)
        aux=aux->next;
      retorno=aux->valor;
      stack->size--;
      return retorno;
}

void terminarpilha(pilha *stack)
{
    pilha *stack1=malloc(sizeof(pilha));
    stack1->no=stack->no;
    while(stack1->no->next!=NULL)
    {
      stack1->no=stack1->no->next;
      free(stack->no);
      *stack->no=*stack1->no;
    }
    free(stack->no);
}

void print_stack(pilha *stack)
{
  while(stack->no->next!=NULL)
  {
    printf("%d ",stack->no->valor);
    stack->no=stack->no->next;
  }
  printf("%d\n",stack->no->valor);
}

int main(void)
{
  int retorno;
  pilha *stack=malloc(sizeof(pilha));
  stack->size=0;
  stack->no=NULL;
  printf("esta vazia %d\n",esta_vazia(stack)); //funcionando;
  push(stack,10); //funcionando;
  retorno=pop(stack);
  printf("pop %d\n",retorno);
  push(stack,10);
  push(stack,11);
  push(stack,12);
  print_stack(stack); //funcionando
  terminarpilha(stack);//funcionando
  return 0;
}
