#include<stdio.h>

void lermatriz(int matriz[1000][1000],int linhas,int colunas)
 {
   int i,j;
   for(i=0;i<linhas;i++)
   {
     for(j=0;j<colunas;j++)
       scanf("%d",&matriz[i][j]);
   }
 }

void unidimensionalizar(int matriz[1000][1000],int vetor[2000],int valores)
{
  int cont;
  int cont2;
  cont=0;
  cont2=0;
  while(cont<valores)
  {
    vetor[cont2]=matriz[cont][0];
    cont2++;
    vetor[cont2]=matriz[cont][1];
    cont2++;
    cont++;
  }
}

int moda(int vetor[2000],int valores)
{
  int vezes,valoresM,cont,comparacoes,vezesATUAL,moda;
  moda=vetor[0];
  cont=0;
  valoresM=(valores*2)-2;
  vezes=0;
  vezesATUAL=0;
  comparacoes=0;
  while(cont<valoresM)
  {
    while(comparacoes<valoresM)
    {
      if(cont==0)
        comparacoes++;
      if(vetor[cont]==vetor[comparacoes])
        vezes++;
      comparacoes++;
    }
    if(vezesATUAL<vezes)
    {
      moda=vetor[cont];
      vezesATUAL=vezes;
      vezes=0;
      comparacoes=0;
    }
    if(vezesATUAL==vezes && vetor[cont]>moda)
    {
      moda=vetor[cont];
      vezesATUAL=vezes;
      vezes=0;
      comparacoes=0;
    }
    else
    {
      vezes=0;
      comparacoes=0;
    }
    cont++;
  }
  return vezesATUAL;
}

int main(void)
{
  int matriz[1000][1000];
  int vetor[2000];
  int valores;
  int valor;
  scanf("%d",&valores);
  lermatriz(matriz,valores-1,2);
  unidimensionalizar(matriz,vetor,valores);
  valor=moda(vetor,valores);
  printf("%d",valor);
  return 0;
}
