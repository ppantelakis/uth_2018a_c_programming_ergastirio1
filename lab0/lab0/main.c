#include <stdio.h>
#include <stdlib.h>
//Global variable of type integer
int age;
int main()
{
    printf("Hello world!\n");
    printf("Please, type your age: ");
    scanf("%d", &age);
    printf("Your age is %d!\n", age);
    printf("You were born in year %d\n", 2018-age);
    return 0;
}
