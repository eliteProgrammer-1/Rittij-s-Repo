#include<stdio.h>


void merge(int* arr, int start, int mid, int end)
{
    int i = start, j = mid + 1, k = 0;
    int tempArr[1000];

    while(i <= mid and j <= end)
    {
        if(arr[i] < arr[j])
        {
            tempArr[k] = arr[i];
            i++;
        }
        else
        {
            tempArr[k] = arr[j];
            j++;
        }
        k++;
    }
    
    while(i <= mid)
    {
        tempArr[k] = arr[i];
        i++;
        k++;
    }
    while(j <= end)
    {
        tempArr[k] = arr[j];
        j++;
        k++;
    }


    // copying
    k = 0;
    for (int i = start; i <= end; i++)
    {
        arr[i] = tempArr[k];
        k++;
    }
    return;
}

void mergeSort(int* arr, int start, int end) // start and end are indexes
{
    if(start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    int arr[6] = {5, 12, 4, 1, 3, 2};
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, 5); 
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
}