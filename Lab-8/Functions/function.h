#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure Declarations
struct node
{
    int data;
    int flag; 
    struct node * next;
};

/*
    Description about Flag:
        0 == WHITE == UNDISCOVERED
        1 == GRAY == DISCOVERED
        2 == BLACK == EXPLORED
*/

struct Queue
{
    int size;
    int front;
    int rear;
    int * arr;
};

//Function Declarations:
void createGraph(struct node * adjacencyList[], int vertices);
void display(int vertices, struct node * adjacencyList[]);
struct node * createNode();
struct node * addEnd(struct node * head, int data);
void BFS(struct node * adjacencyList[], int vertices);
void DFS(struct node * adjacencyList[], int start, int visited[], int i, int vertices);
void discovered(struct node * adjacencyList[], int data, int vertices);
void explored(struct node * adjacencyList[], int data, int vertices);
void enqueue(struct Queue * queue, int data);
void dequeue(struct Queue * queue);
int isEmpty(struct Queue * queue);
int returnNode(struct node * adjacencyList[], int data, int vertices);
int plagiarism();
