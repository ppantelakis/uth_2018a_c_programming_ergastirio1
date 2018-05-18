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

//Table to keep x,fx,f'x
double t_vals[3][TOTALPOINTS];

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

//Function to get the f'(x)
//xn next value of x ps x+1
double fd_y(double y, double yn, double x, double xn)
{
    return (yn-y)/(xn-x);
}

//Function to fill the table with x,y,y'
void fint_x()
{
    int i = 0;
    char buffer[30];
    double x, xn, y, yn, yd;
    FILE *fp = file_open("r");

    printf("\n\n");
    if(fp)
    {
        while(fscanf(fp,"%lf", &y) != EOF)
        {
            if(i>2)
            {
                x = get_x(i-2);
                y = f_y(x);
                t_vals[0][i-3] = x;
                t_vals[1][i-3] = y;
                printf("%lf ", y);
            }
            i++;
        }
        fclose(fp);
        for(i=0;i<TOTALPOINTS;i++)
        {
            if(i<TOTALPOINTS-1)
            {
                x = t_vals[0][i];
                y = t_vals[1][i];
                xn = t_vals[0][i+1];
                yn = t_vals[1][i+1];
                yd = fd_y(y, yn, x, xn);
                t_vals[2][i] = yd;
            }

        }
    }
    else
    {
        printf("Error while opening file %s for read!!!\n", POINTS_FILENAME);
        exit(1);
    }
    return;
}

void t_print()
{
    int i;
    printf("\n\n");
    for(i=0;i<TOTALPOINTS;i++)
    {
        if(i<TOTALPOINTS-1)
        {
            printf("x=%lf y=%lf y'=%lf\n",t_vals[0][i], t_vals[1][i], t_vals[2][i]);
        }

    }

}

double f_integral()
{
    int i;
    double ret = 0.00;
    for(i=0;i<(TOTALPOINTS-1);i++)
    {
        ret = ret + t_vals[2][i];

    }
    return ret;
}

//1<=pos<=TOTALPOINTS
int get_x(int pos)
{
    return (POINT_STARTX + (pos*POINT_STEP));
}

void file_fill()
{
    int i;
    double y;
    FILE *fp = file_open("w");
    if(fp)
    {
        fprintf(fp, "%d\n",TOTALPOINTS);
        fprintf(fp, "%d\n",POINT_STARTX);
        fprintf(fp, "%.2f\n",POINT_STEP);
        for(i=1;i<=TOTALPOINTS;i++)
        {
            y = f_y(get_x(i));
            fprintf(fp, "\n%.2f",y);
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
    fint_x();
    t_print();
    printf("The integral is : %lf\n\n", f_integral());
    return 0;
}
