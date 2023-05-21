#include<stdio.h>
#include"doublycircular.h"

void add_end_doubly_circular(struct Doubly * head , int data)
{
    struct Doubly * tail = malloc(sizeof(struct Circular));

    tail->data = data;
    tail->prev = NULL;
    tail->next = head;

    struct Doubly * temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    tail->prev = temp;
    temp->next = tail;

}
void print_doubly_circular(struct Doubly * head)
{
    struct Doubly * temp = head;
    do
    {
        printf("%d\t" , temp->data);
        temp = temp->next;
    }while(temp != head);

    printf("\n");
}

void print_doubly_rev_circular(struct Doubly * head)
{
  
}

struct Doubly * add_beg_doubly_circular(struct Doubly * head , int data)
{
    struct Doubly * new = malloc(sizeof(struct Doubly));

    struct Doubly * temp = head;

    new->data = data;
    new->prev = NULL;
    new->next = temp;

    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = new;
    head = new;

    return head;
}

struct Doubly * add_random_doubly_circular(struct Doubly * head , int data , int pos)
{
    struct Doubly * new = malloc(sizeof(struct Doubly));

    struct Doubly * temp = head;
    struct Doubly * ptr = head;

    new->data = data;
    new->prev = NULL;
    new->next = temp;
    
    while(pos>1)
    {
        temp = temp->next;
        pos--;
    }

    ptr = temp->next;

    temp->next = new;
    new->next = ptr;
    ptr->prev = new;
    new->prev = temp;
    
    return head;
}

struct Doubly * delete_random_doubly_circular(struct Doubly * head , int pos)
{
    struct Doubly * temp = head;
    struct Doubly * ptr = head;

    while(pos > 1)
        {
            temp = temp->next;
            pos--;
        }

    ptr = temp->prev;
    temp->next->prev = ptr;
    ptr->next = temp->next;

    return head;
}

struct Doubly * delete_element_doubly_circular(struct Doubly * head)
{
    struct Doubly * temp = head;
    struct Doubly * ptr = head;

    while(temp->next != head)
    {
        temp = temp->next;
    }

    head = head->next;
    head->prev = temp;
    temp->next = head;

    free(ptr);
    ptr = NULL;


    return head;
}

struct Doubly * delete_last_doubly_circular(struct Doubly * head)
{
    struct Doubly * temp = head;
    struct Doubly * ptr = head;

    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->prev = temp->next;
    

    return head;
}