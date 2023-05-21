#include<stdio.h>
#include"doubly.h"

struct Doubly * add_end_doubly(struct Doubly * head , int data)
{
    struct Doubly * tail = malloc(sizeof(struct Circular));

    tail->data = data;
    tail->prev = NULL;
    tail->next = NULL;

    struct Doubly * temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    tail->prev = temp;
    temp->next = tail;

    return head;

}
void backward_print_doubly(struct Doubly * head)
{
    struct Doubly * temp = head;
}

void print_doubly(struct Doubly * head)
{
    struct Doubly * temp = head;
    while(temp != NULL)
    {
        printf("%d\t" , temp->data);
        temp = temp->next;
    } 
    printf("\n");
}

struct Doubly * add_beg_doubly(struct Doubly * head , int data)
{
    struct Doubly * newHead = malloc(sizeof(struct Circular));

    newHead->data = data;
    newHead->prev = NULL;
    newHead->next = NULL;

    newHead->next = head;
    head->prev = newHead;
    head = newHead;

    return head;
}

void add_random_doubly(struct Doubly * head , int data , int pos)
{
    struct Doubly * temp = head;
    struct Doubly * ptr = head;
    struct Doubly * new = malloc(sizeof(struct Circular));

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    while(pos != 1)
    {
        temp = temp->next;
        pos--;
    }

    ptr = temp->next;

    temp->next = new;
    new->next = ptr;
    ptr->prev = new;
    new->prev = temp;

}

struct Doubly * delete_element_doubly(struct Doubly * head)
{
    struct Doubly * temp = head;
    struct Doubly * ptr = head;
    
         head = head->next;
         free(temp);
         temp = NULL;
         head->prev = NULL;

         return head;
}

void delete_last_doubly(struct Doubly * head)
{
    struct Doubly * temp = head;
    struct Doubly * ptr = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    ptr = temp->prev;
    ptr->next = NULL;
    free(temp);
    temp = NULL;
}

struct Doubly * delete_random_doubly(struct Doubly * head , int pos)
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

    free(temp);

    temp = NULL;

    return head;
}