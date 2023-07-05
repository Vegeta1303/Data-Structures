#include"function.h"

int isEmpty()
{
    return(front == -1);
}

int isFull()
{
    return((front == rear + 1) || (front == 0 && rear == size - 1));
}

void enqueue(int data)
{
    if (isFull())
    printf ("OVERFLOW\n");

  else
    {
      if (front == -1)
	    front = 0;
        rear = (rear + 1) % size;
        queue[rear] = data;
    }
}

int dequeue()
{
    int variable;
    if(isEmpty())
    {
        printf ("UNDERFLOW\n");
        return -1;
    }
    else
    {
        variable = queue[front];

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
        return variable;
    }
}

void display()
{
    int i = 0;
    for(i = front ; i!=rear ; i = (i+1) % size)
    {
        printf("%d\t" , queue[i]);
    }
    printf("%d\n" , queue[i]);
}