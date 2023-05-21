#include"Functions/stack-min/min.c"

int main()
{
    int data;
    while(1)
    {
        printf("Enter Values(-1 Quits):\t");
        scanf("%d" , &data);
        if(data == -1) break;
        push(data);
    }
    int x;
    printf("Current Min:\t%d\n" , min());
    int menu;
    printf("1. Push\n2. Pop()\n3.Peek()\n");
    scanf("%d" , &menu);
    switch(menu)
    {
        case 1: printf("Enter Data:\t"); scanf("%d" , &data); push(data); printf("Current Min:\t%d\n" , min()); break;
        case 2: x = pop(); printf("Popped Element:\t%d\n" , x); printf("Current Min:\t%d\n" , min());break;
        case 3: peek(); break;
        default: return 0;
    }
    return 0;
}