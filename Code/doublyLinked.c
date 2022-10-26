#include<stdio.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};


struct node* createNode()
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    return newNode;
}

void addNode(struct node* head, int val)
{
   
    struct node* newNode = createNode();
    // (*newNode).data = val;
    newNode->data = val;
    newNode->next = NULL;
    while (head->next != NULL)
    {
        head = head->next;
    }
    newNode->prev = head;
    head->next = newNode;
}

void forwardTravsersal(struct node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void backwardTraversal(struct node *tail)
{

}


int main()
{

}