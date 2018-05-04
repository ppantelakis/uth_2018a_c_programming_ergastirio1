#include <stdio.h>
#include <stdlib.h>

#define n_width 31
#define n_height 41
#define n_randtimes 4


int main()
{
    char table[n_width][n_height];
    const c_trap = 'x';//Trap character
    int i,j;
    int curx=n_width/2,cury=n_height/2;//Current position of the player
    int trap[2][n_randtimes];//Trap coordinations
    for(i=0;i<n_width;i++)
    {
        for(j=0;j<n_height;j++)
        {
            table[i][j]=' ';
        }
    }
    table[curx][cury]='o';
    for(i=0;i<n_randtimes;i++)
    {
        //Adding in 4 random positions in table trap
        //https://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
        trap[0][i]=rand() % n_width;
        trap[1][i]=rand() % n_height;
    }
    return 0;
}
