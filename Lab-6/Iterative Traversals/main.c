#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct stack
{
    int top;
    int size;
    struct Tree **arr;
};

// Function Declarations:
void push(struct stack *head, struct Tree *data);
struct Tree *pop(struct stack *head);
int isEmpty(struct stack *head);
int isFull(struct stack *head);
struct Tree *createTree(struct Tree *root, int data);
void PreOrder(struct Tree *root);
void InOrder(struct Tree *root);
void PostOrder(struct Tree *root);

// Driver Code:
int main()
{
    struct Tree *root = NULL;
    int data;
    printf("Enter data for Root:\t");
    scanf("%d", &data);
    root = createTree(root, data);

    printf("Preorder traversal: \n");
    PreOrder(root);
    printf("\n");

    printf("Inorder traversal: \n");
    InOrder(root);
    printf("\n");

    printf("Postorder traversal: \n");
    PostOrder(root);
    printf("\n");

    return 0;
}

// Function Definitions:
int isEmpty(struct stack *head)
{
    return (head->top == -1);
}

int isFull(struct stack *head)
{
    return (head->top == head->size - 1);
}

void push(struct stack *head, struct Tree *data)
{
    if (!isFull(head))
        head->arr[++head->top] = data;
    else
        printf("Stack is full. Cannot push element.\n");
}

struct Tree *pop(struct stack *head)
{
    if (!isEmpty(head))
        return head->arr[head->top--];
    return NULL; // Added return statement for the empty case
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

struct stack *createStack(int size)
{
    struct stack *stk = malloc(sizeof(struct stack));
    stk->top = -1;
    stk->size = size;
    stk->arr = malloc(stk->size * sizeof(struct Tree *));

    return stk;
}

void PreOrder(struct Tree *root)
{
    if (root == NULL)
        return;

    struct stack *stk = createStack(10);

    push(stk, root);
    while (!isEmpty(stk))
    {
        struct Tree *temp = pop(stk);
        printf("%d\t", temp->data);

        if (temp->right != NULL)
            push(stk, temp->right);
        if (temp->left != NULL)
            push(stk, temp->left);
    }
}

void InOrder(struct Tree *root)
{
    if (root == NULL)
        return;

    struct stack *stk = createStack(10);
    struct Tree *current = root;

    while (current != NULL || !isEmpty(stk))
    {
        while (current != NULL)
        {
            push(stk, current);
            current = current->left;
        }

        current = pop(stk);
        printf("%d\t", current->data);
        current = current->right;
    }
}

void PostOrder(struct Tree *root)
{
    if (root == NULL)
        return;

    struct stack *stk1 = createStack(10);
    struct stack *stk2 = createStack(10);
    push(stk1, root);

    struct Tree *current = NULL;

    while (!isEmpty(stk1))
    {
        current = pop(stk1);
        push(stk2, current);

        if (current->left != NULL)
            push(stk1, current->left);
        if (current->right != NULL)
            push(stk1, current->right);
    }

    while (!isEmpty(stk2))
    {
        current = pop(stk2);
        printf("%d\t", current->data);
    }
}
