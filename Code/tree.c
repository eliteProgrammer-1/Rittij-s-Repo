#include <stdio.h>

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

struct node* insertion(struct node *root, int value) // recursive
{
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
    }
    else if(value > root->value)
    {
        insertion(root->right, value);
    }

    return root;
}

int main()
{
}