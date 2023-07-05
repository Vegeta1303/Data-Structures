#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};

// Function Declarations:
struct Tree *createTree(struct Tree *root, int data);
struct Tree *searchKey(struct Tree *root, int key);
int treeMin(struct Tree *root);
int treeMax(struct Tree *root);
int findSuccessor(struct Tree *root, int data);

// Driver Code
int main()
{
    struct Tree *root = NULL;
    int data;
    int menu;
    int successor;
    struct Tree * succtemp;

    printf("Enter data for Root:\t");
    scanf("%d", &data);
    root = createTree(root, data);


    while(data!=-1)
    {
        printf("Enter data(-1 Quits):\t");
        scanf("%d", &data);
        if(data != -1)
            root = createTree(root, data);
        else break;
    }


    do
    {
        printf("1. SearchKey()\n2. TreeMin() & TreeMax()\n3. FindSuccessor()\n-1. Quit\n");
        printf("Enter the menu option: ");
        scanf("%d", &menu);

        switch (menu)
        {
            case 1:
                printf("Enter key to be Found:\t");
                scanf("%d", &data);
                searchKey(root, data);
                printf("\n");
                break;

            case 2:
                printf("Tree Minimum:\t%d\n", treeMin(root));
                printf("Tree Maximum:\t%d\n", treeMax(root));
                printf("\n");
                break;

            case 3:
                printf("Enter Key for Successor:\t");
                scanf("%d", &data);
                successor = findSuccessor(root, data);
                succtemp = searchKey(root,data);
                succtemp = (succtemp);
                printf("SuccTemp: %d\n" , succtemp->data );
                if (successor == -1)
                    printf("Not Found\n");
                else
                    printf("Successor: %d\n", successor);
                break;

            case -1:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid menu option. Please try again.\n");
                break;
        }

    } while (menu != -1);

    return 0;
}

// Function Definitions:
struct Tree *createTree(struct Tree *root, int data)
{
    if (root == NULL)
    {
        root = (struct Tree *)malloc(sizeof(struct Tree));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (data < root->data)
    {
        root->left = createTree(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = createTree(root->right, data);
    }

    return root;
}

struct Tree *searchKey(struct Tree *root, int key)
{
    if (root == NULL)
    {
        printf("Key NOT Found\n");
        return NULL;
    }

    if (root->data > key)
        return searchKey(root->left, key);

    else if (root->data < key)
        return searchKey(root->right, key);

    else if (root->data == key)
    {
        printf("Key Found\n");
        return root;
    }

    return root;
}

int treeMin(struct Tree *root)
{
    if (root == NULL)
        return -1;

    if (root->left == NULL)
        return root->data;
    else
        return treeMin(root->left);
}

int treeMax(struct Tree *root)
{
    if (root == NULL)
        return -1;

    if (root->right == NULL)
        return root->data;
    else
        return treeMax(root->right);
}

int findSuccessor(struct Tree *root, int data)
{
    struct Tree *temp = searchKey(root, data);

    if (temp == NULL) 
        return -1;

    if (temp->right != NULL)
        return treeMin(temp->right);

    struct Tree *successor = NULL;

    while (root != NULL)
    {
        if (temp->data > root->data)
            root = root->right;
            
        else if (temp->data < root->data)
        {
            successor = root;
            root = root->left;
        }

        else
            break;
    }

    if (successor != NULL)
        return successor->data;
    else
        return -1;
}