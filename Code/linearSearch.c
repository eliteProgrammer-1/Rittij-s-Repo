#include<stdio.h>

int linearSearch(int *arr, int size, int target)
{

}

int main()
{   
    int target = 1;
    int arr[10] = {1, 3, 2, 6, 5, 4, 9, 8, 7, 9};
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == target)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}