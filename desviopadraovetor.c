#include<stdio.h>
#define MAX_NOME_SIZE 30

typedef struct
{
  int idade;
  long cpf;
  char nome[MAX_NOME_SIZE];
}Pessoa;

int lerstruct(Pessoa p[])
{
  int cont;
  cont=0;
  while(scanf("%s",p[cont].nome)!=EOF)
  {
    scanf("%d",&p[cont].idade);
    scanf("%ld",&p[cont].cpf);
    cont++;
  }
  return cont;
}

float media_idade(Pessoa p[],int valor)
{
  int i;
  float somatoria,media;
  i=0;
  somatoria=0.00;
  while(i<valor) //se der erro pode ser aq
  {
    somatoria=somatoria+p[i].idade;
    i++;
  }
  media=somatoria/valor;
  return media;
}

int main(void)
{
  float media;
  int valor;
  Pessoa p[6000];
  valor=lerstruct(p);
  media=media_idade(p,valor);
  printf("%f",media);
  return 0;
}
