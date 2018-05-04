#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int d;
    srand((unsigned int) time(0));
    d = 1 + ((long long)6*rand())/(1+(long long)RAND_MAX);
}
