#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define type char


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

type pop(pilha *stack)
{
    type retorno;
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

type maiorvalor(pilha *stack)
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

int comparamaior(pilha *stack,pilha *stack1)
{
    int valor1,valor2;
    valor1=0;
    valor2=0;
    while(stack->size!=0)
       valor1=valor1+(int)pop(stack);
    while(stack1->size!=0)
        valor2=valor2+(int)pop(stack1);
    if(valor1>valor2)
       return 0;
    else if(valor1<valor2)
       return 2;
    else
       return 1;
}

int main(void)
{
  char str[10000],str1[10000];
  int i,j,maior;
  i=0;
  j=0;
  pilha *stack=malloc(sizeof(pilha));
  pilha *stack1=malloc(sizeof(pilha));
  stack1->size=0;
  stack->size=0;
  stack->no=NULL;
  stack1->no=NULL;
  scanf("%s",str);
  scanf("%s",str1);
  while(i<strlen(str))
  {
      push(stack,str[i]);
      i++;
  }
  while(j<strlen(str1))
  {
      push(stack1,str1[j]);
      j++;
  }
  maior=comparamaior(stack,stack1);
  if(maior==0)
      printf("A maior que B\n");
  else if(maior==1)
      printf("A igual a B\n");
  else if(maior==2)
      printf("A menor que B\n");
  return 0;
}
