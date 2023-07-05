#include"Functions/function.c"

int main()
{
    int menu;
    int data = 0;
    int flag = 1;
    do
    {
        printf("Enter data(-1 Quits):\t");
        scanf("%d" , &data);

        (data == -1) ? flag = 0: addFront(data);

    }while(flag);

    display();


    printf("1. Insert at Front\n2.Insert at Rear\n3.Delete at Front\n4.Delete at Rear\nWrong input terminates:\t");

    scanf("%d" , &menu);

    switch (menu)
    {
        case 1:     printf("Enter data:\t");
                    scanf("%d" , &data);
                    addFront(data);
                    display();
                    break;
        case 2:     printf("Enter data:\t");
                    scanf("%d" , &data);
                    addRear(data);
                    display();
                    break;
        case 3:     data = delRear();
                    printf("Data:\t%d" , data);
                    display();
                    break;
        case 4:     data = delFront();
                    printf("Data:\t%d" , data);
                    display();
                    break;
        default: return 0;
    }

    return 0;
}