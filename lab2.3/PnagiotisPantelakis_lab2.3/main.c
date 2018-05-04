#include <stdio.h>
#include <stdlib.h>

#define n_width 31
#define n_height 41
#define n_randtimes 4


int main()
{
    char table[n_width][n_height];
    int i,j;
    int curx=n_width/2,cury=n_height/2;//Current position of the player
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
        //Adding in 4 random positions in table the char x
        //https://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
         table[rand() % n_width][rand() % n_height] = 'x';
    }
    return 0;
}
