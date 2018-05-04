#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define capacidade 10000

typedef struct pilha
{
       char *item;
       int valores;
}stack;

/*============== Inicia Pilha ======================*/
void inic_pilha (stack *p)
{
     p->item=NULL;
     p->item =(char*)malloc(sizeof(char)*capacidade);
     p=malloc(sizeof(stack));
     p->valores=-1;
}

/*=============== Verifica pilha Cheia ==============*/
int pilha_cheia (stack *p)
{
    if (p->valores == (capacidade-1))
          return 1;
    else
        return 0;
}

/*=============== Verifica pilha Vazia ==============*/
int pilha_vazia (stack *p)
{
    if (p->valores==0)
     return 1;
    else
     return 0;
}

/*================== Empilha  ========================*/
void push (stack *p, char valor)
{
      p->valores++;
      p->item[p->valores]=valor;
}

/*================== Desempilha  =====================*/
int pop (stack *p)
{
    int aux;
    aux=p->item[p->valores];
    p->valores--;
    return aux;
}

/*================== Mostra Pilha  ===================*/
int mostra (stack *p)
{
    int aux;
    if (pilha_vazia(p))
       return 1;
    else
    {
        aux=p->item[p->valores];
        return aux;
    }
}

/*================== Reempilha  ========================*/
int reempilha (stack *p,stack *p_par,stack *p_impar)
{
    int aux;
    if (pilha_vazia (p))
       return 1;
    else
    {   //seleciona os valores Impares
        if (p->item[p->valores]%2)
        {
               aux = pop (p);
               push (p_impar, aux);
        }
        else //seleciona valores pares
        {
               aux = pop (p);
               push (p_par, aux);
        }
        reempilha (p, p_par, p_impar);
        return 0;
    }

}

void isPalindrome(char* str)
{
  int i,tam,boleia;
  char retorno,retorno1,retorno2;
  i=0;
  boleia=0;
  stack pilha,pilha1;
  inic_pilha(&pilha1);
  inic_pilha (&pilha);
  while(str[i]!='\0')
  {
    push(&pilha,str[i]);
    i++;
  }
  while(retorno!='C')
  {
    retorno=pop(&pilha);
    if(retorno!='C')
        push(&pilha1,retorno);
  }
  while(pilha_vazia(&pilha)==0 && pilha_vazia(&pilha1)==0)
  {
    retorno1=pop(&pilha);
    retorno2=pop(&pilha1);
    if(retorno1!=retorno2)
      boleia=1;
  }
  if(boleia==1)
    printf("NÃO\n");
  else
    printf("SIM\n");
}

void binario(long decimal)
{
   stack pilha;
   inic_pilha(&pilha);
   int resto,aux;
   while(decimal!=0)
   {
      resto = decimal%2;
      push(&pilha,resto);
      decimal=decimal/2;
   }
   while(pilha.valores!=0)
   {
      aux=pop(&pilha);
      printf("%d",aux);
   }
   printf("\n");
}

int maiorvalor(stack *pilha)
{
  int maior,valoratual;
  stack pilha1;
  inic_pilha pilha1;
  maior=-1;
  while(pilha.valores!=0)
  {
    valoratual=pop(&pilha)
    if(valoratual>maior)
      maior=valoratual;
    push(&pilha1,valoratual);
  }
  while(pilha1.valores!=0)
    push(&pilha,pop(&pilha1));
  return maior;
}

int main ()
{
    /* Exercicio Palindromo
    char* str = (char *)malloc(512000 * sizeof(char));
    scanf("%s", str);
    isPalindrome(str); */
    /* Exercicio BInario
    long decimal;
    scanf("%ld",&decimal);
    binario(decimal); */

    int i,aux,operacao,valor;
    scanf("%d",&aux);
    stack pilha;
    inic_pilha(&pilha);
    for(i=0;i<aux;i++)
    {
      scanf("%d",&operacao);
      if(operacao==1)
      {
        scanf("%d",&valor);
        push(&pilha,valor);
      }
      else if(operacao==2)
      {
        valor=pop(&pilha);
      }
      else if(operacao==3)
      {
        valor=maiorvalor(&pilha);
        printf("%d",valor);
      }
    }
    return 0;
}
