#include <stdio.h>
#include <stdlib.h>

#define n_width 31
#define n_height 41


int main()
{
    char table[n_width][n_height];
    int i,j;
    for(i=0;i<n_width;i++)
    {
        for(j=0;j<n_height;j++)
        {
            table[i][j]=' ';
            if(i==((n_width/2)+1) && j==((n_height/2)+1))
            {
                table[i][j]='O';
                printf("%d %d",i,j);
            }
        }
    }
    return 0;
}
