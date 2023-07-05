#include"function.h"

struct queue * createNode()
{
    struct queue * new = malloc(sizeof(struct queue));
    return new;
}

void enqueue(int data)
{
    if (q == NULL)
    {
         q = malloc(sizeof(struct queue));
         q->data = data;
         q->next = NULL;
    }

    else{
        struct queue * temp = q;
        struct queue * new = createNode();

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new;
        new->data = data;
        new->next = NULL;
    }
}

int dequeue()
{
    if(isEmpty())
    {
        printf("UNDERFLOW\n");
        return 0;
    }

    int data = q->data;
    struct queue * temp = q;
    q = q->next;

    free(temp);
    return data;
}

int isEmpty()
{
    return (q==NULL);
}

void display()
{
    struct queue * temp = q;
    
    while(temp != NULL)
    {
        printf("%d\t" , temp->data);
        temp = temp->next;
    }

    printf("\n");
}