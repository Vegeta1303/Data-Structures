#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue * next;
} * q = NULL;

int stack[100];
int top = -1;

int dequeue();
void display();
int isEmpty();
void enqueue(int data);
int queueSize();