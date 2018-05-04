#include <stdio.h>
#include <stdlib.h>

#define n_width 31
#define n_height 41
#define n_max_valid_points 4
#define n_total_boards 4

int main()
{
    char table[n_width][n_height];
    const c_trap = 'x';//Trap character
    int i,j;//Counters for x,y to table
    int curx=n_width/2,cury=n_height/2;//Current position of the player
    char c;
    int totalvalid=n_max_valid_points;//Total valid positions for success finish of game
    int feltrap=0;//Recognize if the user fell in a trap
    int neartrap=0;//Recognize if the user is near in a trap
    int totalmoves=0;//Total moves done by player
    int t_max_trap_points[n_total_boards] = { 4, 6, 10, 12};//Trap points per board
    int trap[2][14];//Trap coordinations
    int trap_points;//Current max traps
    int k;//counter for boards
    srand(time(NULL));//Initialize random generator

    for(k=0;k<n_total_boards;k++)
    {
        trap_points = t_max_trap_points[k];
        printf("\n\nStarting board %d for %d traps",k+1,trap_points);
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
        //Adding in trap_points variable random positions in table trap
        for(i=0;i<trap_points;i++)
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
            totalmoves++;
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
                for(i=0;i<trap_points;i++)
                {
                    if(trap[0][i]==curx && trap[1][i]==cury)
                    {
                        feltrap = 1;
                        break;
                    }
                    else if(trap[0][i]==curx-1 || trap[0][i]==curx+1 || trap[1][i]==cury+1 || trap[1][i]==cury-1)
                    {
                        neartrap=1;
                    }
                }
            }
            if(feltrap==1)
            {
                printf("\n\nYou have fell in a trap. Game over!!! \n\n");
                break;
            }
            else if(neartrap==1)
            {
                printf("\n\nYou are near in a trap. Be careffuly!!! \n\n");
            }
            neartrap=0;
            table[curx][cury]='o';
        }
        printf("\n\nYou have done total %d moves \n\n",totalmoves);
    }


    return 0;
}
