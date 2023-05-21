#include"Functions/Circular/circular.c"
#include"Functions/Doubly/doubly.c"
#include"Functions/DoublyCircular/doublycircular.c"
#include<stdlib.h>
int main()
{
    int input;
    printf("Enter Type of List:\n1.Circular\n2.Doubly\n3.Doubly-Circular\nWrong input ends in termination\n");

    scanf("%d" , &input);

    struct Circular * head = malloc(sizeof(struct Circular));

    struct Doubly * start =  malloc(sizeof(struct Doubly));

    int data;

    if(input == 1)
    {

        printf("Enter Data:\n-1 Quits:\t");
        scanf("%d" , &data);
        head->data = data;
        head->next = head;

        do
        {
            printf("Enter Data:\n-1 Quits:\t");
            scanf("%d" , &data);
            if(data != -1) add_end_circular(head , data);

        }while(data != -1);

        head = add_beg_circular(head , 10);
        print_circular(head);
        head = add_random_circular(head , 20 , 3);
        print_circular(head);
        head = delete_last_circular(head);
        head = delete_random_circular(head , 3);
        head = delete_element_circular(head);
        print_circular(head);
    }

    else if(input == 2)
    {
        printf("Enter Data:\n-1 Quits:\t");
        scanf("%d" , &data);
        start->data = data;
        start->next = NULL;
        start->prev = NULL;

        do
        {
            printf("Enter Data:\n-1 Quits:\t");
            scanf("%d" , &data);
            if(data != -1) start = add_end_doubly(start , data);

        }while(data != -1);

        start = add_beg_doubly(start , 45);
        add_random_doubly(start , 30 , 4);
        start = delete_element_doubly(start);
        start = delete_random_doubly(start , 4);
        delete_last_doubly(start);
        print_doubly(start);
        // backward_print_doubly(start);
    }


    else if(input == 3)
    {
        printf("Enter Data:\n-1 Quits:\t");
        scanf("%d" , &data);
        start->data = data;
        start->next = start;
        start->prev = NULL;

        do
        {
            printf("Enter Data:\n-1 Quits:\t");
            scanf("%d" , &data);
            if(data != -1) add_end_doubly_circular(start , data);

        }while(data != -1);

        start = add_beg_doubly_circular(start , 10);
        start = delete_element_doubly_circular(start);
        start = add_random_doubly_circular(start , 20 , 3);
        start = delete_random_doubly_circular(start , 3);
        print_doubly_circular(start);
        // print_doubly_rev_circular(start);
    }

    return 0;
}