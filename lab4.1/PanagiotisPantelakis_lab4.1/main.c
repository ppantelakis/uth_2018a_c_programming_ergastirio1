#include <stdio.h>
#include <stdlib.h>
#include <float.h>

//Filename
#define ELEMENTS_FILENAME "file_lab_41.txt"

//Maximum no zero elements
#define M_max 500

//N width,height of table
#define N_SIZE 60

typedef struct {
    int col;
    int line;
    double val;
}SparseElement;

//Table with nozero elements of type sparseElement
SparseElement SparseMatrix[M_max];

//table1,table_sort_col_line sparse tables
double table1[N_SIZE][N_SIZE], table_sort_line_col[N_SIZE][N_SIZE], table_sort_col_line[N_SIZE][N_SIZE];

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
    int i = 0;
    FILE *fp = file_open("r");
    size_t nread;
    SparseElement tmp_element;
    if(fp)
    {
        while(fscanf(fp, "%d %d %lf", &tmp_element.col, &tmp_element.line, &tmp_element.val)>0)
        {
            SparseMatrix[i++] = tmp_element;
            printf("%d %d %.0lf\n",tmp_element.col, tmp_element.line, tmp_element.val);
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

//Fill table1 from SparseMatrix
void fill_table1()
{
    int col, line;
    SparseElement tmp_element;
    for(col=0;col<N_SIZE;col++)
    {
        for(line=0;line<N_SIZE;line++)
        {
            table1[col][line] = 0;
        }
    }
    for(col=0;col<M_max;col++)
    {
        tmp_element = SparseMatrix[col];
        table1[tmp_element.col][tmp_element.line] = tmp_element.val;
    }
}

void copy_table1_to_others()
{
    int col,line;
    for(col=0;col<N_SIZE;col++)
    {
        for(line=0;line<N_SIZE;line++)
        {
            table_sort_line_col[col][line] = table_sort_col_line[col][line] = table1[col][line];

        }
    }
}

void print_table(double * table_for_print)
{
    int col,line;
    for(line=0;line<N_SIZE;line++)
    {
        for(col=0;col<N_SIZE;col++)
        {
            printf("%.0lf ",table_for_print[col][line]);
        }
        printf("\n");

    }
}

void sort_line_col()
{
    int col,line;
    double tmp;
    for(col=0;col<N_SIZE;col++)
    {
        for(line=0;line<N_SIZE;line++)
        {
            if(line>0 && table_sort_line_col[col][line]<table_sort_line_col[col][line-1])
            {
                tmp = table_sort_line_col[col][line-1];
                table_sort_line_col[col][line-1] = table_sort_line_col[col][line];
                table_sort_line_col[col][line] = tmp;
                line = -1;
            }
        }

    }
    print_table(&table_sort_line_col);

}

int main()
{
    file_fill();
    file_print_contents();
    fill_table1();
    copy_table1_to_others();
    sort_line_col();
    return 0;
}
