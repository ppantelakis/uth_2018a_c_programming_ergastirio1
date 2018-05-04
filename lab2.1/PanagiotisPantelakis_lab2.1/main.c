#include <stdio.h>
#include <stdlib.h>

const double a = 0.001;

int main()
{
    double x, y, x1, y1, lim;
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
      y = 60*x+7;
      if(y<0)
      {
        y=-1*y;
      }
      printf("y=%6.2lf",y);
    }
    if(x<=-10)
    {
      y = -x*x*x-4*x*x+x+3;
      printf("y=%6.2lf",y);
    }

    x1=x+a;
    if(x1>=10)
    {
      y1 = 6*x1*x1+2*x1-13;
      printf("y1=%6.2lf\n\n",y1);
    }
    if(x1>=-10 && x1<=10)
    {
      y1 = 60*x1+7;
      if(y1<0)
      {
        y1=-1*y1;
      }
      printf("y1=%6.2lf",y1);
    }
    if(x1<=-10)
    {
      y1 = -x1*x1*x1-4*x1*x1+x1+3;
      printf("y1=%6.2lf",y1);
    }

    lim = (y1-y)/a;

    printf("x1=%lf y1=%lf lim=%lf",x1,y1,lim);
    return 0;
}
