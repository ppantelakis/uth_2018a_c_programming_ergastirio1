#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int d, board=0, moves=0, repeat=0, prev; //added var prev for previus value of d
    char c;
    srand((unsigned int) time(0));
    d = 1 + ((long long)6*rand())/(1+(long long)RAND_MAX);
    prev = d;
    while(board<=100)
    {
        if(repeat==0)
        {
            moves++;
        }
        d = 1 + ((long long)6*rand())/(1+(long long)RAND_MAX);
        repeat = 1;
        if(prev!=d || moves==1)
        {
            repeat=0;
            switch(d)
            {
                case 1  :
                  board++;
                  printf("You got a 1, and you are sent forward +1 to position %d...\n",board);
                  break;

               case 2  :
                  board=board*2;
                  printf("You got a 2, and you are sent forward *2 position %d...\n",board);
                  break;

                case 3  :
                  board=0;
                  printf("You are very unlucky! You got a 3, and you are sent back to position 0...\n");
                  break;
                case 4  :
                  printf("You got a 4, and you are stable to position %d...\n",board);
                  break;

                case 5  :
                  board=board-2;
                  printf("You are very unlucky! You got a 5, and you are sent back -2 to position %d...\n",board);
                  break;

                case 6  :
                  board=board+10;
                  printf("You are very lucky! You got a 6, and you are sent forward +10 to position %d...\n",board);
                  break;

                default : /* Not necessary because 1<=d<=6 */
                    printf("Something went wrong! You got a %d...\n",d);
                    break;
            }
        }
        prev = d;
    }
    printf("\n\nGame over!!!\n\nTotal moves done : %d\n\n\nYour score is : %d\n\n\n",moves,board);
    while(1)
    {
        printf("Press q to quit: ");
        c = getchar();
        getchar();
        if(c=='q')
        {
            break;
        }
    }
    return 0;
}
