#include <stdio.h>
#include <stdlib.h>

//Maximum table height
#define MAX_H 60

//Maximum table width
#define MAX_W 60

//Table of chars 60X60
char t_chars[MAX_H][MAX_W];
//Enumerator of shapes
enum enum_shapes{Triangle = 1, Square = 2, Parallelogram = 3, Trapeze = 4, Circle = 5};

int print_shape()
{
    int ret = 0;
    int h, l;
    printf("\nPrinting shape\n\n");
    for(h=0;h<MAX_H;h++)
    {
        for(l=0;l<MAX_W;l++)
        {
            printf("%c%c",t_chars[h][l], t_chars[h][l]);
        }
        printf("\n");
    }
    return ret;
}

void init_shape()
{
    int h, l;
    for(h=0;h<MAX_H;h++)
    {
        for(l=0;l<MAX_W;l++)
        {
            t_chars[h][l] = '-';
        }
    }
    return;
}

int design_Triangle()
{
    int ret = 1;
    print_shape();
    return ret;
}
int design_Square()
{
    int ret = 0;
    int side, startx, starty, i;
    printf("Give side for the square : ");
    scanf("%d", &side);
    startx = starty = (MAX_W/2) - (side/2);
    for(i=startx;i<(side+startx);i++)
    {
        t_chars[starty][i] = '*';
        t_chars[starty+side][i] = '*';
        t_chars[i][startx] = '*';
        t_chars[i][startx+side] = '*';
    }
    ret = print_shape();
    return ret;
}
int design_Parallelogram()
{
    int ret = 1;
    print_shape();
    return ret;
}
int design_Trapeze()
{
    int ret = 1;
    print_shape();
    return ret;
}
int design_Circle()
{
    int ret = 0;
    int radius;
    printf("Give radius for the circle : ");
    scanf("%d", &radius);
    ret = print_shape();
    return ret;
}

int main()
{
    enum enum_shapes shape;
    while(1)
    {
        printf("Select shape to design : \nTriangle = 1 \nSquare = 2 \nParallelogram = 3 \nTrapeze = 4 \nCircle = 5 \nYour choice 1-5: ");
        scanf("%d", &shape);
        init_shape();
        switch(shape)
        {
            case Triangle  :
                design_Triangle();
                break;
            case Square  :
                design_Square();
                break;
            case Parallelogram  :
                design_Parallelogram();
                break;
            case Trapeze  :
                design_Trapeze();
                break;
            case Circle  :
                design_Circle();
                break;
            default : /* Optional */
                printf("No correct selection. Please try again");
        }
        printf("\n\nYou selected %d\n\n\n", shape);
    }
    return 0;
}
