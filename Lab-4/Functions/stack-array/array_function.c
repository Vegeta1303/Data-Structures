#include"array_function.h"

int isEmpty(struct StArr * stack)
{
    if(stack->top == -1)    return 1;
    else return 0;
}

int isFull(struct StArr * stack)
{
    if(stack->top == stack->size-1)    return 1;
    else return 0;
}

void push_arr(struct StArr * stack , int data)
{
    if(isFull(stack))
        printf("Stack OVERFLOW\n");

    else
    {
        stack->top++;
        stack->arr[stack->top] = data;
    }
}

int pop_arr(struct StArr * stack)
{
    int x = -1; //Sentinel
    if(isEmpty(stack))
        printf("Stack UNDERFLOW\n");

    else
    {
        x = stack->arr[stack->top];
        stack->top--;
    }
    return x;
}

int peek(struct StArr stack)
{
    return stack.arr[stack.top];
}

void display_array(struct StArr stack)
{
    int i = 0;
    for(i = 0 ; i<=stack.top ; i++)
        printf("%d\t" , stack.arr[i]);
    printf("\n");
}
