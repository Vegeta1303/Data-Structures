#include"function.h"

struct stack * createNode()
{
    struct stack * new = malloc(sizeof(struct stack));

    return new;
}

void push(int data , struct stack * start)
{
    if(start == NULL)
    {
        start = malloc(sizeof(struct stack));
        start->data = data;
        start->next = NULL;
    }

    else
    {
        struct stack * new = createNode();
        new->data = data;
        new->next = start;
        start = new;
    }

}

int pop(struct stack * start)
{
    struct stack * temp = start;
    int num = start->data;
    start = start->next;

    free(start);

    return(num);
}

int isEmptyStack(struct stack * head)
{
    return (head == NULL);
}

void enqueue(int data)
{
    push(data , head); 
}

int dequeue()
{
    while(!(isEmptyStack(head)))
        push(pop(head) , head_temp);

    int x = pop(head_temp);

    while(!isEmptyStack(head_temp))
        push(pop(head_temp) , head);

    return x;
}

 void display()
 {
    struct stack * temp = head;

    while(temp != NULL)
    {
        printf("%d" , temp->data);
        temp = temp->next;
    }

    printf("\n");
}