#include<stdio.h>
#include<stdlib.h>
#include "linkedList_02.c"

// we can add as many as nodes in Linked list because of no barrier of contigous memory. so, size is not needed in this stack
struct stack
{   
    struct node* top;
};

void push(struct stack* s, int val)
{
    struct node* newNode = createNode(val);
    newNode->next = s->top;
    s->top = newNode;
    return;
}

int top(struct stack* s)
{   
    // s->top = node of linked list and s->top->data is data of that node.
    return s->top->data;
}

void pop(struct stack* s)
{   
    struct node* currTop = s->top;
    s->top = currTop->next;
    free(currTop);
    return;
}

int main()
{   
    struct stack* s1 = (struct stack*)malloc(sizeof(struct stack));
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
}