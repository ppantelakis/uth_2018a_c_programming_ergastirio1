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

void print_shape()
{
    int h, l;
    printf("\nPrinting shape\n\n");
    for(h=0;h<MAX_H;h++)
    {
        for(l=0;l<MAX_W;l++)
        {
            printf("%c",t_chars[h][l]);
        }
        printf("\n");
    }
    return;
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
    int ret = 1;
    print_shape();
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
    print_shape();
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
