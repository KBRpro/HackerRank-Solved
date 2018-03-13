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

  void printarmatriz(int matriz[1000][1000],int linhas,int colunas)
  {
    int i,j;
    printf("%d %d\n",linhas,colunas);
    for(i=0;i<linhas;i++)
    {
      for(j=0;j<colunas-1;j++)
        printf("%d ",matriz[i][j]);
      printf("%d\n",matriz[i][j]);
    }
  }

  void somarmatriz(int matriz[1000][1000],int matriz2[1000][1000],int linhas,int colunas)
  {
    int i,j;
    printf("%d %d\n",linhas,colunas);
    for(i=0;i<linhas;i++)
    {
      for(j=0;j<colunas-1;j++)
        printf("%d ",(matriz[i][j] + matriz2[i][j]));
      printf("%d\n",(matriz[i][j]+matriz2[i][j]));
    }
  }

  int main(void)
  {
    int linhas,colunas;
    int matriz[1000][1000];
    int matriz2[1000][1000];
    scanf("%d %d",&linhas,&colunas);
    lermatriz(matriz,linhas,colunas);
    scanf("%d %d",&linhas,&colunas);
    lermatriz(matriz2,linhas,colunas);
    somarmatriz(matriz,matriz2,linhas,colunas);
    return 0;
  }
