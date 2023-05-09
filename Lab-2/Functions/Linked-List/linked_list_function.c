#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linked_list_function.h"

void print_linked_list_data(struct Node * head)
{
    struct Node * temp = malloc(sizeof(struct Node));

    temp = head;
    while(temp!=NULL)
    {
        printf("%d\t" , temp->data);
        temp = temp->link;
    }

    printf("\n");

}

void print_linked_list_id(struct Node * head)
{
    struct Node * temp = malloc(sizeof(struct Node));

    temp = head;
    while(temp!=NULL)
    {
        printf("%d\t" , temp->id);
        temp = temp->link;
    }

    printf("\n");

}

void add_element_at_beg(struct Node * head , int data)
{
    struct Node * new = malloc(sizeof(struct Node));

    new->data = data;
    new->link = head;

    print_linked_list_data(new);
    printf("\n");

}

void add_element_at_end(struct Node * head , int new_data , int id)
{
    struct Node * temp = head;

    temp = head;

    while(temp->link!=NULL)
    {
        temp = temp->link;
    }  

    temp->link = malloc(sizeof(struct Node));
    temp = temp->link;
    temp->data = new_data;
    temp->id = id;
    temp->link = NULL;
  
}

void delete_last_in_element_linked_list(struct Node * head)
{
    struct Node * temp = head;
    while(temp->link->link != NULL)
    {
        temp = temp->link;
    }

    temp->link= NULL;   
}

int count_items_in_linked_list(struct Node * head)
{

    struct Node * temp = malloc(sizeof(struct Node));

    int count = 1;

    temp = head;

    while(temp->link != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;
}

struct Node * reverse(struct Node * head)
{
    if(head->link == NULL)
        return head;

    struct Node * last = reverse(head->link);
    struct Node * next = head->link;  
    next->link = head;
    head->link = NULL;

    return last;
}

void detect_loop(struct Node * head)
{
    struct Node * slow = head;
    struct Node * fast = head;

    int flag = 0;

    while(1)
    {
        slow = slow->link;
        fast = fast->link->link;

        if(slow->id == fast->id)
        {
            flag = 1;
            break;
        }
        
        else if(fast->link == NULL)
        {
            flag = 0;
            break;
        }
    }

    if(flag == 1)
    {
        printf("Loop Detected\n");
    }

    else 
    {
        printf("No Loop Detected\n");
    }

}

struct Employee * bubble_sort(struct Employee * head)
{
    struct Employee * prev = head;
    struct Employee * curr = head;
    struct Employee * next = curr->link; 
    struct Employee * temp = head; 

    int count = 1;

    while(temp->link != NULL)
    {
        count++;
        temp = temp->link;
    }

    int i = 0;

    for(i = 0 ; i<count ; i++)
    {
        for(curr = head ; curr->link!=NULL ; curr = curr->link)
        {
            next = curr->link;

            if(curr->id > next->id)
            {

                if(curr == head)
                {
                    head = next;
                    curr->link = head->link;
                    head->link = curr;

                }

                else if(next->link != NULL)
                {
                    while(prev->link != curr)
                    {
                        prev = prev->link;
                    }

                    prev->link = curr->link;
                    curr->link = next->link;
                    next->link = curr; 
                }
                else if(next->link == NULL)
                {

                    while(prev->link != curr)
                    {
                        prev = prev->link;
                    }

                    prev->link = curr->link;
                    next->link = curr;
                    curr->link = NULL;
                    break;
                }
            }
            prev = head;
        }
    }
    temp = head;
    int id[count];
    i = 0;

    return head;
}

int get_expense_by_type(struct Employee * head)
{
    int type;
    printf("Enter Expense Type:\n1.Flight Fare\n2.Train Fare\n3.Food Fare\n4.Phone Fare\nEnter a Number between 1-4\nWrong Input results in termination:\n");
    scanf("%d" , &type);

    int sum = 0;

    struct Employee * temp = head;

    for(temp = head ; temp!=NULL; temp = temp->link)

    {
       if(type == 1)
       {
            if(!(strcmp("Flight" , temp->expense_type)))
            {
                sum = sum+ temp->expense;
            }
       }

       else if(type == 2)
       {
            if(!(strcmp("Train" , temp->expense_type)))
            {
                sum = sum+ temp->expense;
            }
       }

       else if(type == 3)
       {
            if(!(strcmp("Food" , temp->expense_type)))
            {
                sum = sum+ temp->expense;
            }
       }

       else if(type == 4)
       {
            if(!(strcmp("Phone" , temp->expense_type)))
            {
                sum = sum+ temp->expense;
            }
       }
    }

    return sum;

}

int get_expense_by_id(struct Employee * head)
{
    int sum = 0;

    struct Employee * temp = head;

    int id;
    printf("Enter Employee ID:\t");
    scanf("%d" , &id);

    for(temp = head ; temp!=NULL; temp = temp->link)
    {
        switch (id)
        {
            case 98: if(temp->id == 98) sum += sum+temp->expense; break;
            case 66: if(temp->id == 66) sum += sum+temp->expense; break;
            case 26: if(temp->id == 26) sum += sum+temp->expense; break;
            case 37: if(temp->id == 37) sum += sum+temp->expense; break;
            case 84: if(temp->id == 84) sum += sum+temp->expense; break;
            default: return 0;
        }
    }

    return sum;
}

struct Employee * swap(struct Employee * head , int pos1 , int pos2)
{
   struct Employee * node1 = head;
   struct Employee * node2 = head;
   struct Employee * prev_node1 = head;
   struct Employee * prev_node2 = head;

   int count = 0;

    while(1)
    {
        count++;
        if(count == pos1) break; 
        node1 = node1->link;
    }

    count = 0;

    while(1)
    {
        count++;
        if(count == pos2) break;
        node2 = node2->link;
    }

    printf("%d\t%d\n" , node1->id , node2->id);

    if(pos1 != 1)
    {
        while(prev_node1->link != node1)
            {
                prev_node1 = prev_node1->link; 
            }
    }    
    
    if(pos2 != 1)
    {
        while(prev_node2->link != node2)
            {
                prev_node2 = prev_node2->link; 
            }
    }

  

    // printf("%d\t%d\n" , prev_node1->id , prev_node2->id);
    if(pos1 != 1 && pos2 != 1)
    {
        prev_node1->link = node2;
        prev_node2->link = node1;
        struct Employee * temp = node1->link;
        node1->link = node2->link;
        node2->link = temp;
    }

    else if(pos1 == 1 || pos2 == 1)
    {
        if(pos1 == 1)
        {
            struct Employee * temp = node1->link;
            head = node2;
            prev_node2->link = node1; 
            node1->link = node2->link;
            node2->link = temp;  
        }

        else if(pos2 == 1)
        {
             struct Employee * temp = node2->link;
             head = node1;
             prev_node1->link = node2;
             node2->link = node1->link;
             node1->link = temp;
        }
    }

    return head;

}

struct Employee * remove_duplicate_entries(struct Employee * head)
{
    struct Employee * temp = head;
    
    for(temp = head ; temp->link!=NULL ; temp = temp->link)
    {
        if(temp->id == temp->link->id && temp->expense == temp->link->expense && !(strcmp(temp->expense_type , temp->link->expense_type)) && !(strcmp(temp->name , temp->link->name)))
        {
            temp->link = temp->link->link;
        }
    }
    return head;
}