#include<stdio.h>

void bubbleSort(int* arr, int size)
{
    while(size)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        size--;
    }
    return;
}

int main()
{   
    int size = 5;
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}