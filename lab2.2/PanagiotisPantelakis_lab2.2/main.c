#include <stdio.h>
#include <stdlib.h>

#define n_max 3

int main()
{
    int akeraioi[n_max], tablea[n_max], tableb[n_max], n, i, j, helpvar, isswitched=1;//helpvar for switching variables, isswitched flag if switched variables
    for(n=0;n<n_max;n++)
    {
        printf("Give me the %d number : ",n+1);
        scanf("%d",&akeraioi[n]);
    }
    //Copy the contents of tables akeraioi to tablea, tableb
    for(n=0;n<n_max;n++)
    {
        tablea[n] = akeraioi[n];
        tableb[n] = akeraioi[n];
    }
    //First sorting method
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
    printf("\n\n The sorted array table a is \n\n");
    for(n=0;n<n_max;n++)
    {
        printf("%d ",tablea[n]);
    }

    //Second sorting method
    while(isswitched)
    {
        isswitched = 0;
        for(i=0;i<n_max-1;i++)
        {
            if(tableb[i]>tableb[i+1])
            {
                //switch variables
                helpvar = tableb[i];
                tableb[i] = tableb[i+1];
                tableb[i+1] = helpvar;
                isswitched = 1;
                break;
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
    printf("\n\n The sorted array tableb is \n\n");
    for(n=0;n<n_max;n++)
    {
        printf("%d ",tableb[n]);
    }
    return 0;
}
