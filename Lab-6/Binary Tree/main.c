#include<stdio.h>
#include<stdlib.h>

struct Tree 
{
    int data;
    struct Tree *left;
    struct Tree *right;
};

// Function Declarations:
struct Tree *createTree(struct Tree * root, int data);
void InOrder(struct Tree * root);
void PreOrder(struct Tree * root);
void PostOrder(struct Tree * root);
int Height(struct Tree * root);
int max(int a, int b);

// Driver Code
int main()
{
    struct Tree *root = NULL;
    int data;
    int menu;

    do
    {
        printf("1. Create Tree\n2. InOrder()\n3. PreOrder()\n4. PostOrder()\n5. Height of a Tree\n-1. Quit\n");
        printf("Enter the menu option: ");
        scanf("%d", &menu);

        switch (menu)
        {
            case 1:
                printf("Enter data for Root:\t");
                scanf("%d", &data);
                root = createTree(root, data);
                break;

            case 2:
                printf("Inorder Traversal:\t");
                InOrder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal:\t");
                PreOrder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal:\t");
                PostOrder(root);
                printf("\n");
                break;

            case 5:
                printf("Height of the tree:\t%d\n", Height(root));
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

void InOrder(struct Tree * root)
{
    if (root == NULL)
        return;
    
    InOrder(root->left);
    printf("%d\t", root->data);
    InOrder(root->right);
}

void PreOrder(struct Tree * root)
{
    if (root == NULL)
        return;
    
    printf("%d\t", root->data);
    PreOrder(root->left);
    PreOrder(root->right); 
}

void PostOrder(struct Tree * root)
{
    if (root == NULL)
        return;
    
    PostOrder(root->left);
    PostOrder(root->right); 
    printf("%d\t", root->data);
}

int Height(struct Tree * root)
{
    if (root == NULL)
        return 0;
    
    int left = Height(root->left);
    int right = Height(root->right);
    int result = max(left, right) + 1;
    return result;
}

int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}
