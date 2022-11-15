#include<stdio.h>

void insert(int* arr, int size, int insertElementIndex)
{   
    int insertElement = arr[insertElementIndex];
    for (int i = insertElementIndex - 1; i >= 0; i--)
    {
        if(insertElement < arr[i])
        {   
            arr[i + 1] = arr[i];
        }
        else
        {
            arr[i + 1] = insertElement;
            return;
        }
    }
    arr[0] = insertElement;
    return;
}

void insertionSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        insert(arr, size, i + 1);
    }
}

int main()
{
    int size = 5;
    int arr[] = {1, 0, 12, 8, 5};
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}