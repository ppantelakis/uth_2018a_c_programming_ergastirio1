#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int d, board=0, moves=0;
    srand((unsigned int) time(0));
    d = 1 + ((long long)6*rand())/(1+(long long)RAND_MAX);
    while(board<=100)
    {
        moves++;
        d = 1 + ((long long)6*rand())/(1+(long long)RAND_MAX);
        switch(d)
        {
            case 1  :
              board++;
              break; /* optional */

           case 2  :
              board=board*2;
              break; /* optional */

            case 3  :
              board=0;
              break; /* optional */
            case 4  :
              break; /* optional */
            case 5  :
              board=board-2;
              break; /* optional */
            case 6  :
              board=board+10;
              break; /* optional */
           /* you can have any number of case statements */
           default : /* Not neseseray because 1<=d<=6 */
                break;
        }

    }
    return 0;
}
