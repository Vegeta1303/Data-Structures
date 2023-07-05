#include<stdio.h>

#define size 10
int arr[size];
int front = -1;
int rear = -1;

void addFront(int data);
void addRear(int data);
int delFront();
int delRear();
void display();
int isFull();
int isEmpty();