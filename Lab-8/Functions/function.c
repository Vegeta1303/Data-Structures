#include"function.h"

void createGraph(struct node * adjacencyList[], int vertices)
{
    int i;
    int j;
    int vertex;
    int neighbours;
    int data;

    for(i = 0; i < vertices; i++)
    {
        printf("Enter value of Vertex:\t");
        scanf("%d", &vertex);
        adjacencyList[i] = addEnd(adjacencyList[i], vertex);
        printf("Enter Number of Adjacent Vertices of %d:\t", vertex);
        scanf("%d", &neighbours);

        for(j = 0; j < neighbours; j++)
        {
            printf("Enter Node:\t");
            scanf("%d", &data);
            adjacencyList[i] = addEnd(adjacencyList[i], data);   
        }
    }
}

void display(int vertices, struct node * adjacencyList[])
{
    int i;
    struct node * temp;
    
    for(i = 0; i < vertices; i++)
    {
        printf("Vertices Adjacent to %d:\t", adjacencyList[i]->data);

        temp = adjacencyList[i]->next;

        while(temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

struct node * createNode()
{
    struct node * newNode = malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->flag = 0;

    return newNode;
}

struct node * addEnd(struct node * head, int data)
{   
    struct node * temp = head;

    if(head == NULL)
    {
        head = malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
    }
    else
    {
        struct node * newNode = createNode();

        while(temp->next != NULL)
            temp = temp->next;

        newNode->data = data;
        temp->next = newNode;
    }
    return head;
}   

void BFS(struct node * adjacencyList[], int vertices)
{
    int result[vertices];
    int i = 0;
    int j = -1;

    struct Queue * queue = malloc(sizeof(struct Queue));

    queue->size = vertices;
    queue->front = -1;
    queue->rear = -1;
    queue->arr = malloc(vertices * sizeof(int));

    struct node * temp = NULL;

    enqueue(queue, adjacencyList[i]->data);
    result[++j] = adjacencyList[i]->data;

    do
    {
        temp = adjacencyList[i];

        discovered(adjacencyList, temp->data, vertices);

        dequeue(queue);

        while(temp != NULL)
        {
            if(temp->flag == 0)
            {
                discovered(adjacencyList , temp->data, vertices);

                if(temp->flag == 1)
                    result[++j] = temp->data;
                
                enqueue(queue , temp->data);
            }

            temp = temp->next;
        }
        explored(adjacencyList , adjacencyList[i]->data , vertices);
        i++;

        if(i >= vertices)
            break;

    } while(1);

    for(i = 0 ; i < vertices ; i++)
        printf("%d\t" , result[i]);

    printf("\n");
}

void DFS(struct node * adjacencyList[] , int start , int visited[], int i , int vertices)
{
    printf("%d\t" , start);
    start = returnNode(adjacencyList , start , vertices);
    visited[start] = 1;
    int pos;
    
    struct node * temp;
    temp = adjacencyList[start];

    while(temp != NULL)
    {
        pos = returnNode(adjacencyList , temp->data , vertices);
        if(visited[pos] == 0)
            DFS(adjacencyList , temp->data , visited, i++ , vertices);
        temp = temp->next;
    }

}

void enqueue(struct Queue * queue , int data)
{   
    queue->arr[++queue->rear] = data;
}

void dequeue(struct Queue * queue)
{
    queue->arr[queue->front++] = 0;
}

int isEmpty(struct Queue * queue)
{
    return (queue->front == queue->rear);
}

void discovered(struct node * adjacencyList[] , int data , int vertices)
{
    int i = 0;
    struct node * temp = NULL;
    for(i = 0 ; i < vertices ; i++)
    {
        temp = adjacencyList[i];

        while(temp!=NULL)
        {
            if(temp->data == data)
                temp->flag = 1;
            temp = temp->next;
        }
    }
}

void explored(struct node * adjacencyList[] , int data , int vertices)
{
    int j = 0;
    struct node * temp = NULL;
    for(j = 0 ; j < vertices ; j++)
    {
        temp = adjacencyList[j];

        while(temp!=NULL)
        {
            if(temp->data == data)
                temp->flag = 2;
            temp = temp->next;
        }
    }
}

int returnNode(struct node * adjacencyList[] , int data , int vertices)
{
    int i;

    for(i = 0 ; adjacencyList[i]->data != data ; i++);
    return i;
}

int plagiarism()
{
    int bool;

    printf("Is the code plagiarised?\n1 - True\n0 - False\n");
    scanf("%d" ,&bool);

    return bool;
}