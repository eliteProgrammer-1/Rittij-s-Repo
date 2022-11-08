#include<stdio.h>

int binarySearch(int *arr, int size, int target)
{
    int index = -1, left = 0, right = size - 1, cnt = 0;
    while (left <= right)
    {   
        cnt++;
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            index = mid;
            break;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    printf("%d\n", cnt);
    return index;
}

int main()
{
    int arr[10] = {1, 2, 4, 6, 7, 8, 12, 14, 15, 18};
    printf("%d", binarySearch(arr, 10, 18));
}