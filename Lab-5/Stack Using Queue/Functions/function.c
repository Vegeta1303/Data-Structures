#include"function.h"

int isEmpty1()
{
    return(front1 == -1);
}

int isEmpty2()
{
    return(front2 == -1);
}

int isFull()
{
    return((front == rear + 1) || (front == 0 && rear == size - 1));
}

void enqueue1(int data)
{
    if (isFull())
    printf ("OVERFLOW\n");

  else
    {
      if (front1 == -1)
	    front1 = 0;
        rear1 = (rear1 + 1) % size;
        queue[rear1] = data;
    }
}

void enqueue2(int data)
{
    if (isFull())
    printf ("OVERFLOW\n");

  else
    {
      if (front2 == -1)
	    front2 = 0;
        rear2 = (rear2 + 1) % size;
        queue[rear2] = data;
    }
}

int dequeue1()
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

        if (front1 == rear1)
            front1 = rear1 = -1;
        else
            front1 = (front1 + 1) % size;
        return variable;
    }
}

int dequeue2()
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

        if (front2 == rear2)
            front2 = rear2 = -1;
        else
            front2 = (front2 + 1) % size;
        return variable;
    }
}

void display()
{
    int i = 0;
    for(i = front ; i!=rear ; i = (i+1) % size)
    {
        printf("%d\t" , queue1[i]);
    }
    printf("%d\n" , queue1[i]);
}

void push(int data)
{
    enqueue2(data);

    while(!isEmpty1())
        enqueue2(dequeue1());
    
    while(!isEmpty2())
        enqueue1(dequeue2());
}

int pop()
{
    dequeue1();
}