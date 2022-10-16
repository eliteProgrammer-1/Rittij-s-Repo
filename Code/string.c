#include<stdio.h>

int main()
{
    // char arr[7] = {'R', 'i', 't', 't', 'i', 'j'};
    // for (int i = 0; i < 7; i++)
    // {
    //     printf("%c", arr[i]);
    // }

    char *c = "Rittij";
    for (int i = 0; i < 7; i++)
    {
        printf("%c", *(c + i));
    }
}