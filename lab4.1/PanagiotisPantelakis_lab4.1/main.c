#include <stdio.h>
#include <stdlib.h>
#include <float.h>

//Filename
#define ELEMENTS_FILENAME "file_lab_41.txt"
#define ELEMENTS_FILENAME2 "file_lab_41_2.txt"

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
SparseElement SparseMatrix[M_max], SparseMatrix2[M_max];

//table1, table2, table_sort_col_line sparse tables
double table1[N_SIZE][N_SIZE], table2[N_SIZE][N_SIZE], table_sort_line_col[N_SIZE][N_SIZE], table_sort_col_line[N_SIZE][N_SIZE];

FILE * file_open(char *file_mode, char *fname)
{
    FILE *fp;
    fp = fopen(fname, file_mode);
    if(!fp)
    {
        printf("Error while opening file %s for write!!!\n", fname);
    }
    return fp;
}


void file_fill()
{
    int i, x, y;
    double val;
    FILE *fp = file_open("w", ELEMENTS_FILENAME);
    FILE *fp2 = file_open("w", ELEMENTS_FILENAME2);
    srand(time(NULL));
    if(fp && fp2)
    {
        for(i=0;i<M_max;i++)
        {
            x = rand() % N_SIZE;
            y = rand() % N_SIZE;
            val = (double)rand();//DBL_MAX;
            fprintf(fp, "%d %d %.0lf\n",x,y,val);
        }
        fclose(fp);
        for(i=0;i<M_max;i++)
        {
            x = rand() % N_SIZE;
            y = rand() % N_SIZE;
            val = (double)rand();//DBL_MAX;
            fprintf(fp2, "%d %d %.0lf\n",x,y,val);
        }
        fclose(fp2);
    }
    else
    {
        printf("Error while opening file %s or %s for write!!!\n", ELEMENTS_FILENAME, ELEMENTS_FILENAME2);
        exit(1);
    }
    return;
}

void file_fill_SparseMatrix_tables()
{
    int i;
    FILE *fp = file_open("r", ELEMENTS_FILENAME);
    FILE *fp2 = file_open("r", ELEMENTS_FILENAME2);
    size_t nread;
    SparseElement tmp_element;
    if(fp && fp2)
    {
        i = 0;
        while(fscanf(fp, "%d %d %lf", &tmp_element.col, &tmp_element.line, &tmp_element.val)>0)
        {
            SparseMatrix[i++] = tmp_element;
            //printf("%d %d %.0lf\n",tmp_element.col, tmp_element.line, tmp_element.val);
        }
        if (ferror(fp)) {
            printf("Error while reading  file %s for read!!!\n", ELEMENTS_FILENAME);
            exit(1);
        }
        fclose(fp);

        i = 0;
        while(fscanf(fp2, "%d %d %lf", &tmp_element.col, &tmp_element.line, &tmp_element.val)>0)
        {
            SparseMatrix2[i++] = tmp_element;
            //printf("%d %d %.0lf\n",tmp_element.col, tmp_element.line, tmp_element.val);
        }
        if (ferror(fp2)) {
            printf("Error while reading  file %s for read!!!\n", ELEMENTS_FILENAME2);
            exit(1);
        }
        fclose(fp2);
    }
    else
    {
        printf("Error while opening file %s or %s for write!!!\n", ELEMENTS_FILENAME, ELEMENTS_FILENAME2);
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

//Fill table1 from SparseMatrix2
void fill_table2()
{
    int col, line;
    SparseElement tmp_element;
    for(col=0;col<N_SIZE;col++)
    {
        for(line=0;line<N_SIZE;line++)
        {
            table2[col][line] = 0;
        }
    }
    for(col=0;col<M_max;col++)
    {
        tmp_element = SparseMatrix2[col];
        table2[tmp_element.col][tmp_element.line] = tmp_element.val;
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

void print_table(double table_for_print[N_SIZE][N_SIZE])
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

void sort_line(double table_for_sort[N_SIZE][N_SIZE])
{
    int col,line;
    double tmp;
    for(col=0;col<N_SIZE;col++)
    {
        for(line=0;line<N_SIZE;line++)
        {
            if(line>0 && table_for_sort[col][line]<table_for_sort[col][line-1])
            {
                tmp = table_for_sort[col][line-1];
                table_for_sort[col][line-1] = table_for_sort[col][line];
                table_for_sort[col][line] = tmp;
                line = -1;
            }
        }

    }
}

void sort_col(double table_for_sort[N_SIZE][N_SIZE])
{
    int col,line;
    double tmp;
    for(line=0;line<N_SIZE;line++)
    {
        for(col=0;col<N_SIZE;col++)
        {
            if(col>0 && table_for_sort[col][line]<table_for_sort[col-1][line])
            {
                tmp = table_for_sort[col-1][line];
                table_for_sort[col-1][line] = table_for_sort[col][line];
                table_for_sort[col][line] = tmp;
                col = -1;
            }
        }

    }
}

void sort_line_col()
{
    sort_line(table_sort_line_col);
    sort_col(table_sort_line_col);
    print_table(table_sort_line_col);
}

void sort_col_line()
{
    sort_col(table_sort_col_line);
    sort_line(table_sort_col_line);
    print_table(table_sort_col_line);
}

void add_tables()
{
    int col,line;
    for(line=0;line<N_SIZE;line++)
    {
        for(col=0;col<N_SIZE;col++)
        {
            printf("%.0lf ", (table1[col][line] + table2[col][line]));
        }
        printf("\n");

    }
}

void substruct_tables()
{
    int col,line;
    for(line=0;line<N_SIZE;line++)
    {
        for(col=0;col<N_SIZE;col++)
        {
            printf("%.0lf ", (table1[col][line]-table2[col][line]));
        }
        printf("\n");

    }
}

void multiply_tables()
{
    int col, line, line2, col2;
    double tmp;
    for(line=0;line<N_SIZE;line++)
    {
        for(col=0;col<N_SIZE;col++)
        {
            tmp = 0;
            col2 = line;
            for(line2=0;line2<N_SIZE;line2++)
            {
                tmp = tmp + (table1[col][line]*table2[col][line]);
            }
            printf("%.0lf ", tmp);
        }
        printf("\n");

    }
}

int main()
{
    int select;
    file_fill();
    file_fill_SparseMatrix_tables();
    fill_table1();
    fill_table2();
    copy_table1_to_others();

    printf("Select operation 1:sort row-col, 2:sort col-row, 3:add 2 tables, 4:subtract tables, 5:multiply tables :");
    scanf("%d",&select);
    if(select==1)
    {
        sort_line_col();
    }
    else if(select==2)
    {
        sort_col_line();
    }
    else if(select==3)
    {
        add_tables();
    }
    else if(select==4)
    {
        substruct_tables();
    }
    else if(select==5)
    {
        multiply_tables();
    }


    return 0;
}
