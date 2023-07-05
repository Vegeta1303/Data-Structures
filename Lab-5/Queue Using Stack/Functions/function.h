#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack * next;
} * head = NULL , * head_temp = NULL;

struct stack * createNode();
void push(int data , struct stack * head);
int pop(struct stack * head);
int isEmptyStack(struct stack * head);
void enqueue(int data);
int dequeue();
void display();

