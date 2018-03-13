#include<stdio.h>
#include<math.h>

void lervalores(int *vetor,int valores)
{
  int i;
  for(i=0;i<valores;i++)
  {
    scanf("%d",&vetor[i]);
  }
}

float calcularmedia(int *vetor,int valores)
{
  int cont,somatoria,media;
  cont=0;
  somatoria=0;
  while(cont<valores)
  {
    somatoria=(float)somatoria+vetor[cont];
    cont++;
  }
  media=(float)somatoria/valores;
  return media;
}

float calculardesvio(int *vetor,int valores,float media)
{
  int cont,variancia;
  cont=0;
  float valorR,somavariancia,desvio;
  somavariancia=0;
  while(cont<valores)
  {
    valorR=(float)vetor[cont]-media;
    somavariancia=somavariancia+((float)vetor[cont]-media)*((float)vetor[cont]-media);
    cont++;
  }
  variancia=somavariancia/valores;
  desvio=sqrt(variancia);
  return desvio;
}

int main(void)
{
  int valores;
  int vetor[1000];
  float desvio,media;
  scanf("%d",&valores);
  lervalores(vetor,valores);
  media=calcularmedia(vetor,valores);
  desvio=calculardesvio(vetor,valores,media);
  printf("%f",desvio);
  return 0;
}
