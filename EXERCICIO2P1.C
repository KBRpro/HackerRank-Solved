#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
  float x;
  float y;
  float time;
} checkpoint;


float distancia(float x0,float x1,float y0,float y1)
{
    float dist;
    float dX,dY;
    dX=powf((x0-x1),2);
    dY=powf((y0-y1),2);
    dist=sqrtf(dX+dY);
    return dist;
}

int main()
{

    float dist,speed,bestspeed,dT;
    int trechos,besttrecho;
    int i,j;
    bestspeed=0.00;
    besttrecho=0;
    j=0;
    scanf("%d",&trechos);
    checkpoint *a=malloc(sizeof(checkpoint)*trechos);
    while(j<trechos)
    {
        scanf("%f %f %f",&a[j].x,&a[j].y,&a[j].time);
        j++;
    }
    i=0;
    while(i<trechos)
    {
        dist=distancia(a[i].x,a[i+1].x,a[i].y,a[i+1].y);
        dT=a[i+1].time-a[i].time;
        speed=dist/dT;
        if(speed>bestspeed)
        {
            bestspeed=speed;
            besttrecho=i;
        }
        i++;
    }
    besttrecho+=1;
    printf("%d %.3f",besttrecho,bestspeed);
    free(a);
    return 0;
}
