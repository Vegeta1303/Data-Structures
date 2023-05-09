#include<stdio.h>
#include"Functions/Linked-List/linked_list_function.c"

int main()
{
    struct Node * head = malloc(sizeof(struct Node));

    int no_of_elements;
    printf("Enter Number of Elements in Linked List:\t");
    scanf("%d" , &no_of_elements);
    
    int i;
    int data;

    for(i = 1 ; i<=no_of_elements ; i++)
    {
        printf("Enter Data:\t");
        scanf("%d" , &data);

        if(i == 1) 
        {
            head->data = data;
            head->id = i;
        }
        else 
        {
            add_element_at_end(head , data , i);
        }
    }   

    int menu;
    printf("1. Insert Element at Beginning\n2.Delete Last Element\n3.Count Number of Elements\n4.Reverse a Linked List\n5.Find Loop in a Linked List\n\n Enter a Number between 1-5\nWrong input results in termination\n");
    scanf("%d" , &menu);

    switch (menu)
    {
        case 1: printf("Enter Element to be added at Beginning:\t"); scanf("%d" , &data); print_linked_list_data(head); add_element_at_beg(head , data); break;
        case 2: delete_last_in_element_linked_list(head); print_linked_list_data(head); break;
        case 3: printf("Number of Elements: %d\n" , count_items_in_linked_list(head)); break;
        case 4: print_linked_list_data(reverse(head)); break;
        case 5: detect_loop(head);
        default: return 0;;
    }
}