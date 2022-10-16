#include<stdio.h>

struct node
{
    char data;
    struct node* next;
};


int main()
{   
    struct node n1, n2, n3, n4, n5, n6;
    n1.data = 'R';
    n2.data = 'i';
    n3.data = 't';
    n4.data = 't';
    n5.data = 'i';
    n6.data = 'j';

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = NULL;


    struct node *ptr = &n1;
    while(ptr != NULL)
    {
        printf("%c", (*ptr).data);
        ptr = (*ptr).next;
    }
}