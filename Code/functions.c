#include<stdio.h>

int add(int, int);

int main()
{   
    int sum = add(2, 3);
    printf("%d\n", sum);
    sum = add(10, 100);
    printf("%d", sum);
}

int add(int a, int b)
{
    return a + b;
}