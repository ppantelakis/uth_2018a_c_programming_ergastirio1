#include <stdio.h>
#include <stdlib.h>

#define n_width 31
#define n_height 41
#define n_max_trap_points 4
#define n_max_valid_points 4

int main()
{
    char table[n_width][n_height];
    const c_trap = 'x';//Trap character
    int i,j;//Counters for x,y to table
    int curx=n_width/2,cury=n_height/2;//Current position of the player
    int trap[2][n_max_trap_points];//Trap coordinations
    char c;
    int totalvalid=n_max_valid_points;//Total valid positions for success finish of game
    int feltrap=0;//Recognize if the user fell in a trap
    srand(time(NULL));//Initialize random generator
    //Initialization of table
    for(i=0;i<n_width;i++)
    {
        for(j=0;j<n_height;j++)
        {
            table[i][j]=' ';
        }
    }
    //Initialization of player coordination
    table[curx][cury]='o';
    //Adding in 4 random positions in table trap
    for(i=0;i<n_max_trap_points;i++)
    {
        //https://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
        trap[0][i]=rand() % n_width;
        trap[1][i]=rand() % n_height;
        //table[trap[0][i]][trap[1][i]]='t';
    }
    //Adding in 4 random positions in table trap
    for(i=0;i<n_max_valid_points;i++)
    {
        table[rand() % n_width][rand() % n_height]='x';
    }
    while(1)
    {
        //Printing the table
        printf("\n\n");
        for(i=0;i<n_width+2;i++)
        {
            printf("---");
        }
        printf("\n");
        for(i=0;i<n_height;i++)
        {
            printf("|");
            for(j=0;j<n_width;j++)
            {
                printf("%c ",table[j][i]);
            }
            printf("|\n");
        }
        for(i=0;i<n_width+2;i++)
        {
            printf("---");
        }
        printf("\n");
        printf("Press q to quit, h to left, j to down, k to up, l right : ");
        c = getchar();
        getchar();
        if(c=='q')//Quit
        {
            break;
        }
        else if(c=='h')//Left
        {
            table[curx][cury]=' ';
            curx--;
            if(curx<0)
            {
                curx=0;
            }
        }
        else if(c=='j')//Down
        {
            table[curx][cury]=' ';
            cury++;
            if(cury>=n_height)
            {
                cury=n_height-1;
            }
        }
        else if(c=='k')//Up
        {
            table[curx][cury]=' ';
            cury--;
            if(cury<0)
            {
                cury=0;
            }
        }
        else if(c=='l')//Right
        {
            table[curx][cury]=' ';
            curx++;
            if(curx>=n_width)
            {
                curx=n_width-1;
            }
        }
     //   printf("%d",curx);
        if(table[curx][cury]=='x')
        {
            totalvalid--;
            if(totalvalid==0)
            {
                printf("You have finished successfully the game. You found all the %d valid points!!! \n\n",n_max_valid_points);
                break;
            }
            printf("\n\nYou found success point. Left %d valid points to pass ",totalvalid);
        }
        else
        {
            for(i=0;i<n_max_trap_points;i++)
            {
                if(trap[0][i]==curx && trap[1][i]==cury)
                {
                    feltrap = 1;
                    break;
                }
            }
        }
        if(feltrap==1)
        {
            printf("You have fell in a trap. Game over!!! \n\n");
            break;
        }
        table[curx][cury]='o';
    }

    return 0;
}
