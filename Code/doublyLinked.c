#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *createNode(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = val;
    
    return newNode;
}

struct node* addNodeAtHead(struct node* head, int val)
{
    struct node* newNode = createNode(val);
    newNode->next = head;
    head->prev = newNode;
    return newNode; // new head of given linkedList
}

void addNodeAtTail(struct node *head, int val)
{

    struct node *newNode = createNode(val);
    // (*newNode).data = val;
    while (head->next != NULL)
    {   
        // printf("%d ", head->data);
        head = head->next;
    }
    newNode->prev = head;
    head->next = newNode;
}

void forwardTravsersal(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

struct node *getTail(struct node *head)
{
    struct node *tail;
    while (head->next != NULL)
    {
        head = head->next;
    }
    tail = head;
    return tail;
}

void backwardTraversal(struct node *head)
{
    struct node *tail = getTail(head);
    while (tail != NULL)
    {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
}

struct node* addNodeAtMid(struct node* head, int index, int val)
{   
    struct node* newHead = head;
    struct node* newNode = createNode(val);
    if (index == 0)
    {
        // insertion at head
    }
    else
    {
        int currIndex = 0;
        while (currIndex < index - 1)
        {   
            head = head->next;
            currIndex++;
        }
        newNode->next = head->next;
        head->next->prev = newNode;

        head->next = newNode;
        newNode->prev = head;
    }
    return newHead;
}

int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 2;
    head->prev = NULL;
    head->next = NULL;

    addNodeAtTail(head, 5);
    addNodeAtTail(head, 6);
    addNodeAtTail(head, 7);

    // head = addNodeAtHead(head, 10);
    // head = addNodeAtHead(head, 12);

    head = addNodeAtMid(head, 2, 100);

    forwardTravsersal(head);
    printf("\n");
}