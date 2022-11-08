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

void display(struct stack* s)
{

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
    struct stack* s1 = intializeStack(20);
    while (1)
    {
        int choice;
        printf("Select your choice : 1 for push, 2 for pop, 3 for top\n\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        if(choice == 1)
        {   
            int num;
            printf("Enter Number to push : ");
            scanf("%d", &num);
            push(s1, num);
            printf("Number Pushed Succefully\n");
        }
        else if(choice == 2)
        {
            pop(s1);
            printf("Number Popped Succefully\n");
        }
        else if(choice == 3)
        {
            printf("Top : %d\n", top(s1));
        }
        else
        {
            break;
        }
    }
    return 0;
}