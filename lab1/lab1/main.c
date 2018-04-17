#include <stdio.h>
#include <stdlib.h>
int i1,i2;
int main()
{
    printf("Please, type the first number: ");
    scanf("%d", &i1);
    printf("Please, type the second number: ");
    scanf("%d", &i2);
    printf("You typed the numbers %d and %d.\n", i1, i2);
    printf("The smallest of the two numbers is ");
    if(i1<i2)
    {
        printf("%d.",i1);
    }
    else
    {
        printf("%d.",i2);
    }
    return 0;
}
