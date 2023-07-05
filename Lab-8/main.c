#include"Functions/function.c"

int main()
{
    //Initializations
    int i;
    int data;
    int vertices;
    int menu;
    int start;

    //main()
    printf("Enter No. of Vertices:\t");
    scanf("%d", &vertices);

    int visited[vertices];

    for(i = 0; i < vertices; i++)
        visited[i] = 0;

    struct node * adjacencyList[vertices];

    for(i = 0; i < vertices; i++)
        adjacencyList[i] = NULL;

    createGraph(adjacencyList, vertices);
    printf("\n\nThe Graph entered by User is:\n");
    display(vertices, adjacencyList);

    // menu
    do
    {
        printf("1. BFS\n2. DFS\n3. Exit\nWrong input ends in termination:\t");
        scanf("%d", &menu);

        switch (menu)
        {
            case 1:
                printf("\n\nBFS:\n");
                BFS(adjacencyList, vertices);
                break;

            case 2:
                printf("\n\nDFS:\n");
                printf("Enter Start:\t");
                scanf("%d", &start);
                DFS(adjacencyList, start, visited, 0, vertices);
                printf("\n");   
                break;

            case 3:
                printf("Exiting...\n");
                break;
                
            default:
                return 0;
        }
    } while (menu != 3 && !plagiarism());

    return 0;
}