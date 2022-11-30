#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

int partition(int* arr, int start, int end)
{   
    int index = 0, pivotElement = arr[end];
    int* temp = new int[end - start + 1];
    for (int i = start; i <= end; i++)
    {
        if(arr[i] < pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }

    temp[index] = pivotElement;
    index++;

    for (int i = start; i < end; i++)
    {
        if(arr[i] > pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }
    
    int pivotIndex;
    index = 0;
    for (int i = start; i <= end; i++)
    {   
        if(arr[i] == pivotElement)
        {
            pivotIndex = i;
        }
        arr[i] = temp[index];
        index++;
    }
    return pivotIndex;
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