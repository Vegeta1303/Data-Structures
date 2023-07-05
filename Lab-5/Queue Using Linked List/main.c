#include"Functions/function.c"
int main()
{
    int i;
    int data = 0;
    int flag = 1;
    do
    {
        printf("Enter data(-1 Quits):\t");
        scanf("%d" , &data);

        (data == -1) ? flag = 0: enqueue(data);

    }while(flag);

    display();

    int menu;
    printf("1.EnQueue()\n2.Dequeue()\n3.isEmpty()\nWrong input terminates:\t");
    scanf("%d" , &menu);

    switch (menu)
    {
        case 1: 
                printf("Enter data:\t");
                scanf("%d" , &data);
                enqueue(data);
                display();
                break;
        case 2:
                data = dequeue();
                printf("DeQueue'd Data:\t%d\n" , data);
                display();
                break;
        case 3: isEmpty() ? printf("Yes") :printf("No") ; break;
        default: return 0;
    }
    return 0;
}