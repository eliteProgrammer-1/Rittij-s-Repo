#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key, value;
    struct node *next = NULL;
};

struct hashMap
{
    struct node **arr;
    int size;
};

int hashFunction(int key, int size)
{
    return key % size;
}

void insert(struct hashMap *mp, int key, int value)
{
    int bucketIndex = hashFunction(key, mp->size);
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (mp->arr[bucketIndex] == NULL)
    {
        mp->arr[bucketIndex] = newNode;
    }
    else // collision
    {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
}

int search(struct hashMap *mp, int key)
{
    int bucketIndex = hashFunction(key, mp->size);
    struct node *temp = mp->arr[bucketIndex];
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }

    printf("Value not found!");
    return -1;
}

void erase(struct hashMap *mp, int key)
{
    int bucketIndex = hashFunction(key, mp->size);
    struct node *temp = mp->arr[bucketIndex];
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            if (temp->next == NULL) // last node
            {
                struct node *prev = mp->arr[bucketIndex];
                while (prev->next == temp)
                {
                    prev = prev->next;
                }

                prev->next = temp->next;
                free(temp);
                return;
            }
            else if (mp->arr[bucketIndex] == temp) // head node
            {
                mp->arr[bucketIndex] = temp->next;
                return;
            }
            else // middle node
            {
                struct node *prev = mp->arr[bucketIndex];
                while (prev->next == temp)
                {
                    prev = prev->next;
                }

                prev->next = temp->next;
                free(temp);
                return;
            }
        }
        temp = temp->next;
    }
    return;
}

int main()
{
    struct hashMap *mp = (struct hashMap *)malloc(sizeof(hashMap));
    mp->arr = (struct node **)malloc(sizeof(struct node *) * mp->size);
    mp->size = 6;

    insert(mp, 1, 10);
    insert(mp, 2, 20);
    insert(mp, 3, 30);
    insert(mp, 4, 40);

    printf("%d\n", search(mp, 2));
    erase(mp, 1);
    printf("%d\n", search(mp, 1));
}