#include<stdio.h>

int main()
{
    char c = 'A';
    char *ptr = &c;
    int a = 10;
    int *ptrInt = &a;

    printf("%c\n", *ptr);
    printf("%d", *ptrInt);
}