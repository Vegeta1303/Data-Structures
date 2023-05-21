#include"ll_function.h"
struct StLL * push_ll(struct StLL * head , int data)
{
    struct StLL * new = malloc(sizeof(struct StLL));

    new->data = data;
    new->link = head;
    head = new;

    return head;
}

int pop_ll(struct StLL * head) 
{
    int x = head->data;
    struct StLL * temp = head;
    head = head->link;

    free(temp);
    temp = NULL;

    return x;
}

int isEmpty_ll(struct StLL * head)
{
    if(head == NULL)
        return 1;
    else
        return 0;
}

int peek_ll(struct StLL * head)
{
    if(!isEmpty_ll(head))
        return head->data;
    else    
        return -1;
}