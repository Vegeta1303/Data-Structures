#include<stdio.h>
#include<stdlib.h>

struct avl 
{
    int data;
    int height;
    struct avl *left;
    struct avl *right;
};

// Function Declarations
struct avl* insert(struct avl* root, int data);
int height(struct avl* root);
int balanceFactor(struct avl* root);
struct avl* LL_Rotation(struct avl* root);
struct avl* LR_Rotation(struct avl* root);
struct avl* RR_Rotation(struct avl* root);
struct avl* RL_Rotation(struct avl* root);
struct avl* deleteNode(struct avl* root, int data);
struct avl* findMin(struct avl* root);
struct avl* deleteMin(struct avl* root);
void inOrder(struct avl* root);

// Driver Code
int main()
{
    int menu, data = 0;
    struct avl* root = NULL;

    printf("Creating Tree:\n");
    
    while (data != -1)
    {
        printf("Enter data (-1 to quit): ");
        scanf("%d", &data);

        if (data != -1)
            root = insert(root, data);
    }

    printf("InOrder Traversal:\n");
    inOrder(root);
    printf("\n");

    while (1)
    {
        printf("\nAVL Tree Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu);

        switch (menu)
        {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Node inserted succteessfully!\n");
                printf("InOrder Traversal:\n");
                inOrder(root);
                printf("\n");
                break;
            case 2:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Node deleted successfully!\n");
                printf("InOrder Traversal:\n");
                inOrder(root);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                return 0;
        }
    }
    return 0;
}

// Function Definitions

void inOrder(struct avl* root)
{
    if (root == NULL)
        return;
    
    inOrder(root->left);
    printf("%d\t", root->data);
    inOrder(root->right);
}

struct avl* insert(struct avl* root, int data)
{
    if (!root)
    {
        root = (struct avl*) malloc(sizeof(struct avl));
        root->data = data;
        root->height = 0;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);

        if (height(root->left) - height(root->right) == 2)
            (data < root->left->data) ? root = LL_Rotation(root) : root = LR_Rotation(root);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);

        if (height(root->right) - height(root->left) == 2)
            (data > root->right->data) ? root = RR_Rotation(root) : root = RL_Rotation(root);
    }

    root->height = height(root->left) > height(root->right) ? height(root->left) + 1 : height(root->right) + 1;
    return root;
}

int height(struct avl* root)
{
    if (!root)
        return -1;
    else 
        return root->height;
}

struct avl* LL_Rotation(struct avl* root)
{
    struct avl* temp = root->left;
    root->left = temp->right;
    temp->right = root;

    root->height = height(root->left) > height(root->right) ? height(root->left) + 1 : height(root->right) + 1;

    temp->height = height(temp->left) > height(root) ? height(temp->left) + 1 : height(root) + 1;
    return temp;
}

struct avl* RR_Rotation(struct avl* root)
{
    struct avl* temp = root->right;
    root->right = temp->left;
    temp->left = root;

    root->height = height(root->right) > height(root->left) ? height(root->right) + 1 : height(root) + 1;

    temp->height = height(temp->right) > height(root) ? height(temp->right) + 1 : height(root) + 1;
    return temp;
}

struct avl* LR_Rotation(struct avl* root)
{
    root->left = RR_Rotation(root->left);
    return LL_Rotation(root);
}

struct avl* RL_Rotation(struct avl* root)
{
    root->right = LL_Rotation(root->right);
    return RR_Rotation(root);
}

struct avl* findMin(struct avl* root)
{
    if (root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    else
        return findMin(root->left);
}

struct avl* deleteMin(struct avl* root)
{
    if (root == NULL)
        return NULL;
    else if (root->left != NULL)
    {
        root->left = deleteMin(root->left);
        return root;
    }
    else
    {
        struct avl* temp = root->right;
        free(root);
        return temp;
    }
}

struct avl* deleteNode(struct avl* root, int data)
{
    if (root == NULL)
        return NULL;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        struct avl* leftChild = root->left;
        struct avl* rightChild = root->right;
        free(root);

        if (rightChild == NULL)
            return leftChild;

        struct avl* minNode = findMin(rightChild);
        minNode->right = deleteMin(rightChild);
        minNode->left = leftChild;
        return minNode;
    }

    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    if (balanceFactor(root) > 1 && balanceFactor(root->left) >= 0)
        return LL_Rotation(root);

    if (balanceFactor(root) > 1 && balanceFactor(root->left) < 0)
        return LR_Rotation(root);

    if (balanceFactor(root) < -1 && balanceFactor(root->right) <= 0)
        return RR_Rotation(root);

    if (balanceFactor(root) < -1 && balanceFactor(root->right) > 0)
        return RL_Rotation(root);

    return root;
}

int balanceFactor(struct avl* root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}