#include<stdio.h>

int main()
{
    int array[5];
    *(array) = 10;
    *(array + 1) = 9;
    printf("%d", *(array + 1));

    array[0] = 11;
    array[1] = 12; 
    array[2] = 15; 
    array[3] = 15;
    array[4] = 15;  

    
}