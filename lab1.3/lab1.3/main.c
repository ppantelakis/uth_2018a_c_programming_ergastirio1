#include <stdio.h>
#include <stdlib.h>
int i1,i2,i3,i4;
int main()
{
    while(1)
    {
        printf("Please, type the first number: ");
        scanf("%d", &i1);
        printf("Please, type the second number: ");
        scanf("%d", &i2);
        printf("Please, type the third number: ");
        scanf("%d", &i3);
        printf("Please, type the fourth number: ");
        scanf("%d", &i4);
        printf("You typed the numbers i1=%d, i2=%d, i3=%d, i4=%d.\n", i1, i2, i3, i4);
        if (i1 < i2)
        {
            if (i2 < i3) // i1<i2<i3
            {
                if (i4 > i3) //i1<i2<i3<i4
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i1, i2, i3, i4);
                }
                else if (i4 > i2) //i1<i2<i4<i3
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i1, i2, i4, i3);
                }
                else if (i4 > i1) // i1<i4<i2<i3
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i1, i4, i2, i3);
                }
                else // i4<i1<i2<i3
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i4, i1, i2, i3);
                }
            }
            else if (i1 < i3) // i1<i3<i2
            {
                if (i4 > i2) // i1<i3<i2<i4
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i1, i3, i2, i4);
                }
                else if (i4 > i3) // i1<i3<i4<i2
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i1, i3, i4, i2);
                }
                else if (i4 > i1) // i1<i4<i3<i2
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i1, i4, i3, i2);
                }
                else // i4<i1<i3<i2
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i4, i1, i3, i2);
                }
            }
            else // i3<=i1<i2
            {
                if (i4 > i2) // i3<i1<i2<i4
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i3, i1, i2, i4);
                }
                else if (i4 > i1) // i3<i1<i4<i2
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i3, i1, i4, i2);
                }
                else if (i4 > i3) // i3<i4<i1<i2
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i3, i4, i1, i2);
                }
                else // i4<i3<i1<i2
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i4, i3, i1, i2);
                }
            }
        }
        else //i2 <= i1
        {
            if (i1 < i3) // i2<i1<i3
            {
                if (i4 > i3) //i2<i1<i3<i4
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i2, i1, i3, i4);
                }
                else if (i4 > i1) //i2<i1<i4<i3
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i2, i1, i4, i3);
                }
                else if (i4 > i2) // i2<i4<i1<i3
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i2, i4, i1, i3);
                }
                else // i4<i2<i1<i3
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i4, i2, i1, i3);
                }
            }
            else if (i2 < i3) // i2<i3<i1
            {
                if (i4 > i1) // i2<i3<i1<i4
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i2, i3, i1, i4);
                }
                else if (i4 > i3) // i2<i3<i4<i1
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i2, i3, i4, i1);
                }
                else if (i4 > i2) // i2<i4<i3<i1
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i2, i4, i3, i1);
                }
                else // i4<i2<i3<i1
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i4, i2, i3, i1);
                }
            }
            else // i3<=i2<i1
            {
                if (i4 > i1) // i3<i2<i1<i4
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i3, i2, i1, i4);
                }
                else if (i4 > i2) // i3<i2<i4<i1
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i3, i2, i4, i1);
                }
                else if (i4 > i3) // i3<i4<i2<i1
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i3, i4, i2, i1);
                }
                else // i4<i3<i2<i1
                {
                    printf("The correct order is: %d,%d,%d,%d\n",i4, i3, i2, i1);
                }
            }
        }
    }
    return 0;
}
