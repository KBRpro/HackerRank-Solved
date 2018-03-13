#include<stdio.h>

int main(void)
{
  int a,b,i;
  i=0;
  scanf("%d", &a);
  scanf("%d", &b);
  for(i=a;i<=b;i++)
    printf("%d ",i);
  return 0;
}
