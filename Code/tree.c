#include <stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// struct node* insertion(struct node* root, int value) // loop
// {
//     if(root == NULL)
//     {
//         return createNode(value);
//     }

//     while (root != NULL)
//     {
//         if(value > root->value && root->right == NULL)
//         {
//             struct node* newNode = createNode(value);
//             root->right = newNode;
//             break;
//         }
//         else if(value < root->value && root->left == NULL)
//         {
//             struct node* newNode = createNode(value);
//             root->left = newNode;
//             break;
//         }
//         else if(value > root->value)
//         {
//             root = root->right;
//         }
//         else if(value < root->value)
//         {
//             root = root->left;
//         }
//     }
// }

int g = 0;

struct node* insertion(struct node *root, int value) // recursive
{   
    g++;
    if (root == NULL)
    {
        return createNode(value);
    }
    
    if (value > root->value && root->right == NULL)
    {
        struct node *newNode = createNode(value);
        root->right = newNode;
        return root;
    }
    else if (value < root->value && root->left == NULL)
    {
        struct node *newNode = createNode(value);
        root->left = newNode;
        return root;
    }
    else if(value < root->value)
    {
        insertion(root->left, value);
        printf("right-> %d\n", g);
    }
    else if(value > root->value)
    {
        insertion(root->right, value);
        printf("right-> %d\n", g);
    }

    return root;
}

void inorder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

int main()
{
    struct node* root = NULL;
    root = insertion(root, 6);
    g = 0;
    root = insertion(root, 5);
    g = 0;
    root = insertion(root, 4);
    g = 0;
    root = insertion(root, 7);
    g = 0;
    root = insertion(root, 3);
    g = 0;
    root = insertion(root, 1);
    g = 0;
    root = insertion(root, 2);
}