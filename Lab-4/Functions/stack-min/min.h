#include<stdio.h>
#include<stdlib.h>
int arr[100];
int top = -1;

struct stack
{
    int data;
    struct stack * next;
} * head = NULL;

struct stack * createNode();
void push(int data);
int pop();
void display();
int min();
int isEmpty();
void peek();