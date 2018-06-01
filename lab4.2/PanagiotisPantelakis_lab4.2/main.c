#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_size_base10(char *num1, char *num2)
{
    int ret = strlen(num2);
    if(strlen(num1)>strlen(num2))
    {
        ret = strlen(num1);
    }
    ret--;
    return ret;
}

void split_at(char *num, int pos, double *high, double *low)
{
    char *to_high = (char*) malloc(pos*sizeof(char));
    char *to_low = (char*) malloc((strlen(num)-pos)*sizeof(char));
    strncpy(to_high, num, pos);
    strncpy(to_low, num+pos, (strlen(num)-pos));
    *high = atof(to_high);
    *low = atof(to_low);
    return;
}

double power_ten(int pow)
{
    double ret = 1;
    while(pow>0)
    {
        ret = ret*10;
        pow--;
    }
    return ret;
}

double karatsuba(char *num1, char *num2)
{
    double ret, high1, low1, high2, low2, z0, z1, z2;
    char str1[100],str2[100];
    int m, m2;
    if (atof(num1) < 10 || atof(num2) < 10)
    {
        ret = atof(num1)*atof(num2);
    }
    else
    {
        m = max_size_base10(num1,num2);
        m2 = m/2;

        split_at(num1,m2,&high1,&low1);
        split_at(num2,m2,&high2,&low2);

        sprintf(str1,"%lf",low1);
        sprintf(str2,"%lf",low2);
        z0 = karatsuba(str1, str2);
        printf("%.0lf",z0);
        sprintf(str1,"%.0lf",(low1+high1));
        sprintf(str2,"%.0lf",(low2+high2));
        z1 = karatsuba(str1, str2);
        sprintf(str1,"%.0lf",high1);
        sprintf(str2,"%.0lf",high2);
        z1 = karatsuba(str1, str2);
        ret = (z2 * power_ten(2 * m2)) + ((z1 - z2 - z0) * power_ten(m2)) + (z0);
    }

    return ret;
}


int main()
{
    char num1[100], num2[100];
    double ret;
    printf("Give me numbers to multiply : ");
    scanf("%s %s",num1,num2);
    ret = karatsuba(num1,num2);
    printf("%.0lf",ret);
    return 0;
}


