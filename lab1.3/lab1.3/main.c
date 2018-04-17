#include <stdio.h>
#include <stdlib.h>
int i1,i2,i3,i4;
int main()
{
    printf("Please, type the first number: ");
    scanf("%d", &i1);
    printf("Please, type the second number: ");
    scanf("%d", &i2);
    printf("Please, type the third number: ");
    scanf("%d", &i3);
    printf("Please, type the fourth number: ");
    scanf("%d", &i4);
    printf("You typed the numbers %d, %d, %d, %d.\n", i1, i2, i3, i4);
    if (i1 < i2)
    {
        if (i2 < i3)
        {
            if (i3 < i4) //i1<i2<i3<i4
            {
                printf("The correct order is: %d,%d,%d,%d\n",i1, i2, i3, i4);
            }
            else if (i2 < i4) //i1<i2<i4<i3
            {
                printf("The correct order is: %d,%d,%d,%d\n",i1, i2, i4, i3);
            }
            else if (i1 < i4) // i1<i4<i2<i3
            {
                printf("The correct order is: %d,%d,%d,%d\n",i1, i4, i2, i3);
            }
            else // i4<i1<i2<i3
            {
                printf("The correct order is: %d,%d,%d,%d\n",i4, i1, i2, i3);
            }
        }

    }
    return 0;
}
