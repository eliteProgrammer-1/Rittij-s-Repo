#include<stdio.h>
#include<stdlib.h>

int minimum(int *arr, int size)
{
    int mini = 999999, index;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] < mini && arr[i] != -1)
        {   
            index = i;
            mini = arr[i];
        }
    }
    arr[index] = -1;
    return mini;
}

int* selectionSort(int *arr, int size)
{   
    int *newArr = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        int mini = minimum(arr, size);
        newArr[i] = mini;
    }
    return newArr;
}

int main()
{
    int arr[6] = {5, 12, 4, 1, 3, 2};
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int* newArr = selectionSort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", newArr[i]);
    }
    return 0;   
}