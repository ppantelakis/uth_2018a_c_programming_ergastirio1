#include <stdio.h>
#include <stdlib.h>

#define n_max 3

int main()
{
    int akeraioi[n_max], tablea[n_max], n, i, j, helpvar;//helpvar for switching variables
    for(n=0;n<n_max;n++)
    {
        printf("Give me the %d number : ",n+1);
        scanf("%d",&akeraioi[n]);
    }
    //Copy the contents of tables akeraioi to tablea
    for(n=0;n<n_max;n++)
    {
        tablea[n] = akeraioi[n];
    }
    for(i=n_max-1;i>0;i--)
    {
        for(j=0;j<=i;j++)
        {
            if(tablea[i]<tablea[j])
            {
                //switch variables
                helpvar = tablea[i];
                tablea[i] = tablea[j];
                tablea[j] = helpvar;
            }
        }
    }
    //Print the unsorted array akeraioi
    printf("\n\n The unsorted array is\n\n");
    for(n=0;n<n_max;n++)
    {
        printf("%d ",akeraioi[n]);
    }
    //Print the sorted array tablea
    printf("\n\n The sorted array is \n\n");
    for(n=0;n<n_max;n++)
    {
        printf("%d ",tablea[n]);
    }
    return 0;
}
