#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createNode(int val)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
}

void addNode(struct node *head, int val)
{
    struct node *newNode = createNode(val);

    while ((*head).next != NULL)
    {
        head = (*head).next;
    }
    (*head).next = newNode;
    return;
}

// int main()
// {
//     struct node n1, n2, n3, n4, n5, n6;
//     n1.data = 1;
//     n2.data = 2;
//     n3.data = 3;
//     n4.data = 3;
//     n5.data = 4;
//     n6.data = 5;

//     n1.next = &n2;
//     n2.next = &n3;
//     n3.next = &n4;
//     n4.next = &n5;
//     n5.next = &n6;
//     n6.next = NULL;

//     struct node *ptr = &n1;
//     while (ptr != NULL)
//     {
//         printf("%d ", (*ptr).data);
//         ptr = (*ptr).next;
//     }

//     printf("\n\n");
//     addNode(&n1, 10);
//     addNode(&n1, 15);

//     ptr = &n1;
//     while (ptr != NULL)
//     {
//         printf("%d ", (*ptr).data);
//         // ptr = (*ptr).next;
//         ptr = ptr->next;
//     }
// }