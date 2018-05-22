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
            printf("%c",t_chars[h][l]);
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
            t_chars[h][l] = ' ';
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
    int side=MAX_W, startx, starty, i;
    //While the user inserts side>MAX_W or side<0
    while(side>(MAX_W-3) || side<=0)
    {
        printf("Give side for the square 0<side<=%d: ",(MAX_W-3));
        scanf("%d", &side);
        if(side<=(MAX_W-3))
        {
            startx = starty = (MAX_W/2) - (side/2);
            for(i=startx;i<(side+startx+1);i++)
            {
                t_chars[starty][i] = '*';
                t_chars[starty+side][i] = '*';
                t_chars[i][startx] = '*';
                t_chars[i][startx+side] = '*';
            }
            ret = print_shape();
        }
    }
    return ret;
}
int design_Parallelogram()
{
    int ret = 0;
    int side_w=MAX_W, side_h=MAX_H, start_h, start_w, i;
    //While the user inserts side>MAX_W or side<0
    while(side_w>(MAX_W-3) || side_w<=0 || side_h>(MAX_H-3) || side_h<=0)
    {
        printf("Give side_w(width) for the Parallelogram 0<side_w<=%d: ",(MAX_W-3));
        scanf("%d", &side_w);
        if(side_w<=(MAX_W-3))
        {
            printf("Give side_h(height) for the Parallelogram 0<side_h<=%d: ",(MAX_H-3));
            scanf("%d", &side_h);
            if(side_h<=(MAX_H-3))
            {
                start_w = (MAX_W/2) - (side_w/2);
                start_h = (MAX_H/2) - (side_h/2);
                for(i=start_h;i<(side_h+start_h+1);i++)
                {
                    t_chars[i][start_w] = '*';
                    t_chars[i][start_w+side_w] = '*';
                }
                for(i=start_w;i<(side_w+start_w+1);i++)
                {
                    t_chars[start_h][i] = '*';
                    t_chars[start_h+side_h][i] = '*';
                }


                ret = print_shape();
            }
        }
    }
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
    int radius = MAX_W/2, start_h, start_w, i, k, j;
    //While the user inserts radius>=MAX_W/2 or side<0
    while(radius>=(MAX_W/2) || radius<=0)
    {
        printf("Give radius for the circle 0<radius<=%d: ",(MAX_W/2));
        scanf("%d", &radius);
        if(radius<(MAX_W/2))
        {
            start_h = start_w = (MAX_W/2);
            j = radius;
            for(k=start_h;k>=0;k--)
            {
                for(i=start_w;i<(start_w+j);i++)
                {
                    t_chars[k][i] = '*';
                    t_chars[k][start_w-(i-start_w)] = '*';
                    t_chars[start_h+start_h-k][i] = '*';
                    t_chars[start_h+start_h-k][start_w-(i-start_w)] = '*';
                }
                j=j-2;
            }
            ret = print_shape();
        }
    }
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
