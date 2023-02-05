#include <stdio.h>
#include <stdlib.h>

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

// int g = 0;

struct node *insertion(struct node *root, int value) // recursive
{
    // g++;
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
    else if (value < root->value)
    {
        insertion(root->left, value);
        // printf("right-> %d\n", g);
    }
    else if (value > root->value)
    {
        insertion(root->right, value);
        // printf("right-> %d\n", g);
    }

    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

void preorder(struct node* root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}


void postorder(struct node* root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}

struct node* predecessor(struct node* root)
{
    root = root->left;
    // printf("left....%d\n", root->value);
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node* delete(struct node* root, int target)
{
    if(root->left == NULL && root->right == NULL) // leaf node
    {   
        // printf("%d ", root->value);
        free(root);
        return NULL;
    }
    
    if(root->value == target)
    {
        struct node* predecessorNode = predecessor(root);
        // printf("%d ", predecessorNode->value);
        root->value = predecessorNode->value;
        root->left = delete(root->left, predecessorNode->value);
    }
    else if(root->value < target)
    {
        root->right = delete(root->right, target);
    }
    else // if root->value > target
    {
        root->left = delete(root->left, target);
    }
    root;
}

int main()
{
    struct node *root = NULL;
    root = insertion(root, 6);
    // g = 0;
    root = insertion(root, 5);
    // g = 0;
    root = insertion(root, 4);
    // g = 0;
    root = insertion(root, 7);
    // g = 0;
    root = insertion(root, 3);
    // g = 0;
    root = insertion(root, 1);
    // g = 0;
    root = insertion(root, 2);

    inorder(root);
    root = delete(root, 1);
    printf("\n");
    inorder(root);
    // preorder(root);
    // postorder(root);
}