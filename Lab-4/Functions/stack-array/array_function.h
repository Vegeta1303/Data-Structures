#include<stdio.h>
#include<stdlib.h>

struct StArr
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct StArr * stack);
int isFull(struct StArr * stack);
void push_arr(struct StArr * stack , int data);
int pop_arr(struct StArr * stack);
int peek(struct StArr stack);