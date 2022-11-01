#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int arr[10];
    int top;
};

void push(struct stack* s, int val) // dalana
{   
    s->top++;
    if(s->top == 10)
    {
        return;
    }
    s->arr[s->top] = val;
    return;
}

int top(struct stack* s)
{
    return s->arr[s->top];
}

void isEmpty(struct stack* s)
{
    if (s->top == -1)
    {
        printf("Empty\n");
    }
    else
    {
        printf("Not Empty");
    }
    return;
}

void pop(struct stack* s) // nikalana
{
    if(s->top != -1)
    {
        s->top--;
    }
    return;
}

int main()
{
    struct stack s1;
    s1.top = -1;

    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 5);

    pop(&s1);
    pop(&s1);
    push(&s1, 100);
    printf("%d\n", top(&s1));
}
