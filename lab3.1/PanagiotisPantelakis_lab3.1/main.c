#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Για την εργασία μας θα υλοποιήσουμε την μαθηματική σχέση που βρίσκεται στο
//http://www.dummies.com/education/math/calculus/how-to-calculate-arc-length-with-integration/
//http://d2r5da613aq50s.cloudfront.net/wp-content/uploads/204917.image6.png
//y=sqrt((x-1)^3)
#define TOTALPOINTS 100
#define POINT_STARTX 1
#define POINT_STEP 10
#define POINTS_FILENAME "file31.txt"
#define CHUNK 1024 /* read 1024 bytes at a time */

FILE * file_open(char *file_mode)
{
    FILE *fp;
    fp = fopen(POINTS_FILENAME, file_mode);
    if(!fp)
    {
        printf("Error while opening file %s for write!!!\n", POINTS_FILENAME);
    }
    return fp;
}

//Function to get the f(x)
double f_y(double x)
{
    return sqrt((x-1)*(x-1)*(x-1));
}

void file_fill()
{
    int i;
    float x, y;
    FILE *fp = file_open("w");
    if(fp)
    {
        fprintf(fp, "%d\n",TOTALPOINTS);
        fprintf(fp, "%d\n",POINT_STARTX);
        fprintf(fp, "%.2f\n",POINT_STEP);
        x = POINT_STARTX;
        for(i=0;i<TOTALPOINTS;i++)
        {
            x = x + POINT_STEP;
            y = f_y(x);
            fprintf(fp, "%.2f\n",y);
        }
        fclose(fp);
    }
    else
    {
        printf("Error while opening file %s for write!!!\n", POINTS_FILENAME);
        exit(1);
    }
    return;
}

void file_print_contents()
{
    char buf[CHUNK];
    FILE *fp = file_open("r");
    size_t nread;

    if(fp)
    {
        while ((nread = fread(buf, 1, sizeof buf, fp)) > 0)
        {
            fwrite(buf, 1, nread, stdout);
        }
        if (ferror(fp)) {
            printf("Error while reading  file %s for read!!!\n", POINTS_FILENAME);
            exit(1);
        }
        fclose(fp);
    }
    else
    {
        printf("Error while opening file %s for read!!!\n", POINTS_FILENAME);
        exit(1);
    }
    return;
}

int main()
{
    file_fill();
    printf("File %s was filled successfully!!!\n",POINTS_FILENAME);
    file_print_contents();

    return 0;
}
