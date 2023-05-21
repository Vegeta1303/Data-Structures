#include"min.h"
struct stack * createNode()
{
    struct stack * newNode = malloc(sizeof(struct stack));

    return newNode;
}

void push(int data)
{
    struct stack * newNode = createNode();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    if(top == -1)
        arr[++top] = data;
    else 
    {
        if(data < arr[top])
        {
            arr[++top] = data;
        }
    }
}
int pop()
{
    struct stack * temp = head;
    int x = head->data;
    
    head = head->next;

    free(temp);

    if(x != min())
        return x;
    else
    {
        arr[top--] = 0;
        return x;
    }
}
void display()
{
    struct stack * temp = head;

    while(temp != NULL)
    {
        printf("%d\t" , temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int min()
{
    return arr[top];
}
int isEmpty()
{
    return head == NULL;
}
void peek()
{
    printf("%d\n" , head->data);
}