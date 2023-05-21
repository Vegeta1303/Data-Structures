#include<stdio.h>
#include<stdlib.h>
#include"circular.h"

void add_end_circular(struct Circular * start , int data)
{
    struct Circular * temp = start;
    while(temp->next != start)
    {
        temp = temp->next;
    }

    struct Circular * tail = malloc(sizeof(struct Circular));

    tail->data = data;
    temp->next = tail;
    tail->next = start;
}

void print_circular(struct Circular * start)
{
    struct Circular * temp = start;
    do
    {
        printf("%d\t" , temp->data);
        temp = temp->next;
    }while(temp != start);

    printf("\n");
}

struct Circular * add_beg_circular(struct Circular * head , int data)
{
    struct Circular * newHead = malloc(sizeof(struct Circular));
    newHead->data = data;
    newHead->next = head;

    struct Circular * temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newHead;
    head = newHead;

    return head;
}

struct Circular * add_random_circular(struct Circular * head , int data , int pos)
{
    struct Circular * temp = head;
    struct Circular * ptr = head;
    struct Circular * new = malloc(sizeof(struct Circular));
    new->data = data;
    new->next = NULL;

    while(pos>1)
    {
        temp = temp->next;
        pos--;
    }

    ptr = temp->next;
    temp->next = new;
    new->next = ptr;
    return head;
}

struct Circular * delete_last_circular(struct Circular * head)
{
    struct Circular * temp = head;
    struct Circular * ptr = head;
    
    do
    {
        temp = temp->next;
    }while(temp->next->next != head);

    ptr = temp->next;
    temp->next = head;

    free(ptr);
    ptr = NULL;
    return head;
}

struct Circular * delete_random_circular(struct Circular * head , int pos)
{
    struct Circular * temp = head;
    struct Circular * ptr = head;

    while(pos>1)
    {
        temp = temp->next;
        pos--;
    }

    ptr = temp->next;
    temp->next = ptr->next;

    free(ptr);

    return head;
}

struct Circular * delete_element_circular(struct Circular * head)
{
    struct Circular * temp = head;
    struct Circular * ptr = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;

    free(ptr);
    ptr = NULL;
    return head;
}
