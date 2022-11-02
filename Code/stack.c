#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top, size;
    int *arr;
};


int isFull(struct stack* s)
{
    if(s->top + 1 >= s->size)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack* s)
{
    if(s->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack* s, int val)
{
    if(isFull(s) == 1)
    {   
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = val;
    return;
}

int top(struct stack* s)
{
    if(isEmpty(s) == 1)
    {   
        printf("Stack is Underflow");
        return -1;
    }
    return s->arr[s->top];
}

void pop(struct stack* s)
{
    if(isEmpty(s) == 1)
    {
        printf("Stack is Underflow");
        return;
    }
    s->top--;
}

struct stack* intializeStack(int size)
{
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->arr = (int*)malloc(sizeof(int) * size);
    s->top = -1;
    s->size = size;
    return s;
}

int main()
{
    struct stack* s = intializeStack(3);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printf("%d\n", top(s));
    printf("%d\n", isFull(s));
}