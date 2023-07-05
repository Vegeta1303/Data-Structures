#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue * next;
} * q = NULL;

int dequeue();
void display();
int isEmpty();
void enqueue(int data);