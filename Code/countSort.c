#include<stdio.h>
#include<stdlib.h>

void countSort(int *arr, int size, int maxi)
{
    int *count = (int*)malloc(sizeof(int) * (maxi + 1));
    for (int i = 0; i <= maxi; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    
    // sorting
    int currIndex = 0;  
    for (int i = 0; i <= maxi; i++)
    {
        while(count[i] != 0)
        {
            arr[currIndex] = i;
            count[i]--;
            currIndex++;
        }
    }
    return;   
}

int main()
{
    int arr[6] = {5, 12, 4, 1, 3, 2};
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    countSort(arr, 6, 12);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;   
}