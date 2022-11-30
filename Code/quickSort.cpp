#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

int partition(int* arr, int start, int end)
{   
    int index = start;
    for (int i = start; i < end; i++)
    {
        if(arr[i] < arr[end])
        {
            std:: swap(arr[i], arr[index]);
            index++;
        }
    }
    std:: swap(arr[index], arr[end]);
    return index;
}

void quickSort(int* arr, int start, int end)
{  
    if(start < end)
    {   
        int partitionIndex = partition(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
    return;
}

int main()
{   
    int size = 9;
    int arr[size] = {5, 12, 7, 1, 13, 2 ,23, 11, 18};
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}