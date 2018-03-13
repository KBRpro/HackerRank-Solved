#include<stdio.h>

int main(void)
{
  int valores,numero;
  int cont,somatoria;
  cont=0;
  somatoria=0;
  float media;
  scanf("%d",&valores);
  while(cont<valores)
  {
    scanf("%d",&numero);
    somatoria=somatoria+numero;
    cont++;
  }
  media=(float)somatoria/valores;
  printf("%f",media);
  return 0;

}
