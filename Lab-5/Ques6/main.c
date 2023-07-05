#include"Functions/function.c"

int main()
{
    int i = 0;
    int data;
    for(i = 0 ; i<10 ; i++)
    {
        scanf("%d" , &data);
        enqueue(data);
    }
    display();
    solve(4);
    display();
    return 0;
}