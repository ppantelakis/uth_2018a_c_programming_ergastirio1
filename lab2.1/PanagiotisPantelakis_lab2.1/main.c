#include <stdio.h>
#include <stdlib.h>

const double a = 0.001;

int main()
{
    double x, y, x1, y1, lim, df;
    int myflag = 0;// check if calculated f' 0 = yes 1=no
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

    //First way to calculate f'
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

    printf("First way of calculation f' \n x1=%6.2lf y1=%6.2lf lim=%6.2lf\n\n",x1,y1,lim);

    //Second way to calculate f'
    if(x>10)
    {
      df = 12*x+2;
    }
    else if(x>-(7.0/60) && x<(-7.0/60))
    {
      df = 60;
    }
    else if(x<-(7.0/60) && x>(-10))
    {
      df = -60;
    }
    else if(x<(-10))
    {
      df = -3*x*x-8*x+1;
    }
    else
    {
        printf("Can not calculate f' because of x=%6.2lf",x);
        myflag = 1;
    }
    if(myflag==0)
    {
        printf("Second way of calculation f' \n\n x=%6.2lf df=%6.2lf\n\n",x1,df);
    }
    return 0;
}
