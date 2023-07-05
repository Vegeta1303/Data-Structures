#include "function.h"

void addRear(int data) {
    if (isFull())
        printf("OVERFLOW\n");
    else if (isEmpty()) {
        front = rear = 0;
        arr[rear] = data;
    } else {
        rear = (rear + 1) % size;
        arr[rear] = data;
    }
}

int delRear() {
    if (isEmpty()) {
        printf("UNDERFLOW\n");
        return -1;
    } else {
        int temp = arr[rear];
        if (rear == front)
            rear = front = -1;
        else
            rear = (rear - 1 + size) % size;
        return temp;
    }
}

void addFront(int data) {
    if (isFull())
        printf("OVERFLOW\n");
    else if (isEmpty()) {
        front = rear = 0;
        arr[front] = data;
    } else {
        front = (front - 1 + size) % size;
        arr[front] = data;
    }
}

int delFront() {
    if (isEmpty()) {
        printf("UNDERFLOW\n");
        return -1;
    } else {
        int temp = arr[front];
        if (rear == front)
            rear = front = -1;
        else
            front = (front + 1) % size;
        return temp;
    }
}

int isFull() {
    return ((front == 0 && rear == size - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void display() {
    int i = front;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (i != rear) {
        printf("%d ", arr[i]);
        i = (i + 1) % size;
    }
    printf("%d\n", arr[i]);
}
