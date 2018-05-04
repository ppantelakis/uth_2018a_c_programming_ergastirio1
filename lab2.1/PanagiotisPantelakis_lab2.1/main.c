#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x,y;
    printf("Type Value x : ");
    scanf("%lf",&x);
    printf("x=%6.2lf\n\n",x);
    if(x>=10)
    {
      y = 6*x*x+2*x-13;
      printf("y=%6.2lf\n\n",y);
    }
    if(x>=-10 && x<=10)
    {
      y = 160*x+7;
      printf("y=%6.2lf",y);
    }
    if(x<=-10)
    {
      y = -x*x*x-4*x*x+x+3;
      printf("y=%6.2lf",y);
    }
    //y = (x>=10) ? (6*x*x+2*x-13) : x;
    //printf("x=%lf, y=%lf",x,y);
    return 0;
}
