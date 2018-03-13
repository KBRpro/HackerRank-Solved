  #include<stdio.h>

  void printarmatriz(int matriz[][colunas],int linhas)
  {
    int i,j;
    for(j=0;j<linhas;j++)
    {
      for(i=0;i<colunas;i++)
        printf("%d ",matriz[i][j]);
      printf("\n");
    }
  }

  void criarmatriz(int matriz[][colunas],int linhas,int linha)
  {
    if(linha>linhas)
      printarmatriz(matriz,linhas,colunas);
    criarlinhas(matriz,linhas,linha,0);
  }

  void criarlinha(int matriz[][colunas],int linhas,int linha,int coluna)
  {
    if(coluna>colunas)
      criarmatriz(matriz,linhas,colunas,linha+1);
    criarcoluna(matriz,linhas,linha,coluna);
  }

  void criarcoluna(int matriz[][colunas],int linhas,int linha,int coluna)
  {
    int valor;
    scanf("%d",&valor);
    matriz[linha][coluna]=valor;
    criarlinha(matriz,linhas,linha,coluna+1);
  }

  int main(void)
  {
    int linhas,colunas;
    scanf("%d %d",&linhas,&colunas);
    int matriz[linhas][colunas];
    criarmatriz(matriz,linhas,0);
    return 0;
  }
