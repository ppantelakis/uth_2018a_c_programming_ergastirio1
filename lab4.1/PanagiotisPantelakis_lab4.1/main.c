#include <stdio.h>
#include <stdlib.h>
#include <float.h>

//Filename
#define ELEMENTS_FILENAME "file_lab_41.txt"

//Maximum no zero elements
#define M_max 10

//N width,height of table
#define N_SIZE 60

typedef struct {
    int x;
    int y;
    double val;
}SparseElement;

SparseElement SparseMatrix[M_max];

FILE * file_open(char *file_mode)
{
    FILE *fp;
    fp = fopen(ELEMENTS_FILENAME, file_mode);
    if(!fp)
    {
        printf("Error while opening file %s for write!!!\n", ELEMENTS_FILENAME);
    }
    return fp;
}

void file_fill()
{
    int i, x, y;
    double val;
    FILE *fp = file_open("w");
    srand(time(NULL));
    if(fp)
    {

        /*fprintf(fp, "%d\n",TOTALPOINTS);
        fprintf(fp, "%d\n",POINT_STARTX);
        fprintf(fp, "%.2f\n",POINT_STEP);*/
        for(i=0;i<M_max;i++)
        {
            x = rand() % N_SIZE;
            y = rand() % N_SIZE;
            val = (double)rand();//DBL_MAX;
            fprintf(fp, "%d %d %.0lf\n",x,y,val);
        }
        fclose(fp);
    }
    else
    {
        printf("Error while opening file %s for write!!!\n", ELEMENTS_FILENAME);
        exit(1);
    }
    return;
}

void file_print_contents()
{
    FILE *fp = file_open("r");
    size_t nread;
    SparseElement tmp_element;
    if(fp)
    {
        while(fscanf(fp, "%d %d %lf", &tmp_element.x, &tmp_element.y, &tmp_element.val)>0)
        {
            printf("%d %d %.0lf\n",tmp_element.x, tmp_element.y, tmp_element.val);
        }
        if (ferror(fp)) {
            printf("Error while reading  file %s for read!!!\n", ELEMENTS_FILENAME);
            exit(1);
        }
        fclose(fp);
    }
    else
    {
        printf("Error while opening file %s for read!!!\n", ELEMENTS_FILENAME);
        exit(1);
    }
    return;
}

int main()
{
    file_fill();
    file_print_contents();
    return 0;
}
