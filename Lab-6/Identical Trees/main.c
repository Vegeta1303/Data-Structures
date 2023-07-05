#include<stdio.h>
#include<stdlib.h>

struct Tree 
{
    int data;
    struct Tree *left;
    struct Tree *right;
};

// Function Declarations:
int identical(struct Tree *root1, struct Tree *root2);
struct Tree *createTree(struct Tree *root, int data);

// Driver Code
int main()
{
    int data;

    printf("Enter Root for Tree-1:\t");
    scanf("%d", &data);
    struct Tree * root1 = NULL;
    root1 = createTree(root1 , data);

    printf("\nTree 1 Complete\n\n");

    printf("Enter Root for Tree-2:\t");
    scanf("%d", &data);
    struct Tree * root2 = NULL;
    root2 = createTree(root2 , data);
    

    int result = identical(root1, root2);
    if (result)
        printf("Trees are Identical\n");
    else    
        printf("Trees are not Identical\n");

    return 0;
}

// Function Definitions:
int identical(struct Tree *root1, struct Tree *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 != NULL && root2 == NULL)
        return 0;
    if (root1 == NULL && root2 != NULL)
        return 0;

    int left = identical(root1->left, root2->left);
    int right = identical(root1->right, root2->right);
    int value = (root1->data == root2->data);

    if (left && right && value)
        return 1;
    else
        return 0;
}

struct Tree *createTree(struct Tree *root, int data)
{
    if (root == NULL)
    {
        root = (struct Tree *)malloc(sizeof(struct Tree));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }

    int temp;
    printf("Enter data for Left Node of %d (-1 for NULL):\t", data);
    scanf("%d", &temp);

    if (temp != -1)
    {
        root->left = createTree(root->left, temp);
    }

    printf("Enter data for Right Node of %d (-1 for NULL):\t", data);
    scanf("%d", &temp);

    if (temp != -1)
    {
        root->right = createTree(root->right, temp);
    }

    return root;
}