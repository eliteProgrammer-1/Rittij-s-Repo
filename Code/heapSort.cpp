#include<iostream>

class minHeap
{
private:
    int *arr;
    int size, capacity;

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    int left(int index)
    {
        return (2 * index) + 1;
    }
    int right(int index)
    {
        return (2 * index) + 2;
    }

    int smallestChild(int index)
    {
        int l = left(index), r = right(index), smallestChildIndex = index;
        if (l < this->size and this->arr[l] < this->arr[index] and this->arr[l] < this->arr[r])
        {
            smallestChildIndex = l;
        }
        else if (r < this->size and this->arr[r] < this->arr[index] and this->arr[r] < this->arr[l])
        {
            smallestChildIndex = r;
        }
        return smallestChildIndex;
    }

    void heapifyBottomUp(int index)
    {
        if (index == 0)
        {
            return;
        }

        int parentIndex = parent(index);
        if (this->arr[parentIndex] > this->arr[index])
        {
            std::swap(this->arr[index], this->arr[parentIndex]);
            heapifyBottomUp(parentIndex);
        }
        return;
    }

    void heapifyTopDown(int index)
    {
        int smallestChildIndex = smallestChild(index);
        std::swap(this->arr[index], this->arr[smallestChildIndex]);

        if (smallestChildIndex != index)
        {
            heapifyTopDown(smallestChildIndex);
        }
    }

public:
    minHeap(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        arr = new int[this->capacity];
    }

    void insert(int val)
    {
        int index = this->size;
        this->size++;
        arr[index] = val;
        heapifyBottomUp(index);
    }

    int top()
    {
        return this->arr[0];
    }

    void pop()
    {
        std::swap(this->arr[0], this->arr[this->size - 1]);
        this->size--;
        heapifyTopDown(0);
    }

    int getSize()
    {
        return this->size;
    }

    void print()
    {
        for (int i = 0; i < this->size; i++)
        {
            std::cout << this->arr[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
};


void heapSort(int* arr, int size)
{   
    int currIndex = 0;
    minHeap heap(100);
    
    for (int i = 0; i < size; i++)
    {
        heap.insert(arr[i]);
    }

    while(heap.getSize() > 0)
    {
        int mini = heap.top();
        arr[currIndex] = mini;
        heap.pop();
        currIndex++;
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

    heapSort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }
}