#include<stdio.h>
#include "list.h"

void printar_trajeto(list *caminhoX,list *caminhoY)
{
  while(caminhoX->size!=0 && caminhoY->size!=0)
  {
    printf("%d %d\n",list_pop_back(caminhoX),list_pop_back(caminhoY));
  }
}

void resolver_labirinto(list **labirinto,int x,int y)
{
  int i,iX,iY,escolhas;
  iX=x;
  iY=y;
  list *caminhoX=new_list();
  list *caminhoY=new_list();
  i=0;
  escolhas=0;
  list_push_back(caminhoX,x);
  list_push_back(caminhoY,y);
  list_set(labirinto[iY],x,2);
  while(labirinto[i]->valor!=9)
  {
    if(list_at(labirinto[iY--],x)==0)
    {
    list_push_back(caminhoX,iX);
    list_push_back(caminhoY,iY);
    list_set(labirinto[iY],x,2);
    }
    else if(list_at(labirinto[iY],x--)==0)
    {
    list_push_back(caminhoX,iX);
    list_push_back(caminhoY,iY);
    list_set(labirinto[iY],x,2);
    }
    else if(list_at(labirinto[iY++],x)==0)
    {
    list_push_back(caminhoX,iX);
    list_push_back(caminhoY ,iY);
    list_set(labirinto[iY],x,2);
    }
    else if(list_at(labirinto[iY],x++)==0)
    {
    list_push_back(caminhoX,iX);
    list_push_back(caminhoY,iY);
    list_set(labirinto[iY],x,2);
    }
    else
    {
      while(iX!=x)
      {
      list_pop_back(caminhoX);
      if(iX>x)
        iX--;
      else
        iX++;
      }
      while(iY!=y)
      {
      list_pop_back(caminhoY);
      if(iY>y)
        iY--;
      else
        iY++;
      }
    }
  }
  printar_trajeto(caminhoX,caminhoY);
}

int main(void)
{
  int x,y,escalaX,escalaY;
  int pos,i,j;
  i=0;
  j=0;
  while(i<escalaY)
  {
    list *labirinto[i]=new_list();
    while(j<escalaX)
    {
      list_push_back(labirinto[i],scanf("%d",&pos));
      j++;
    }
    j=0;
    i++;
  }
  resolver_labirinto(&labirinto,x,y);
  return 0;
}
