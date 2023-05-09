#include "Functions/Linked-List/linked_list_function.c"

int main()
{
    FILE *fp = fopen("data_dup.txt" , "r");

    struct Employee * head = malloc(sizeof(struct Employee));

    struct Employee * temp = malloc(sizeof(struct Employee));

    temp = head;

    char nameBuff[10];
    char buffer[10];
    char c;

    while(1)
    {

        fscanf(fp , "%d" , &temp->id);
        fscanf(fp , "%s" , nameBuff);
        fscanf(fp , "%s" , buffer);
        fscanf(fp , "%d" , &temp->expense);
        c = fgetc(fp);
        strcpy(temp->name , nameBuff);
        strcpy(temp->expense_type , buffer);
        // printf("%d\n" , temp->id);
        // printf("%s\n" , temp->name);
        // printf("%s\n" , temp->expense_type);
        // printf("%d\n" , temp->expense);

        if(c == '\n')
        {
            struct Employee * new = malloc(sizeof(struct Employee));
            temp->link = new;
            temp = new;
        }

        if(c == EOF)
        {
            break;
        }

    }

    printf("\n");

    printf("Before Sort:\n\n");

    for(temp = head ; temp!=NULL ; temp = temp->link)
    {
        printf("%d\t" , temp->id);
        printf("%s\t" , temp->name);
        printf("%s\t" , temp->expense_type);
        printf("%d\t" , temp->expense);
        printf("\n");
    }

    printf("\n");


    printf("After Sort:\n\n");

    head = bubble_sort(head);

    for(temp = head ; temp!=NULL ; temp = temp->link)
    {
        printf("%d\t" , temp->id);
        printf("%s\t" , temp->name);
        printf("%s\t" , temp->expense_type);
        printf("%d\t" , temp->expense);
        printf("\n");
    }

    printf("\n");


    printf("After Removing Duplicates:\n\n");

    head = remove_duplicate_entries(head);

    for(temp = head ; temp!=NULL ; temp = temp->link)
    {
        printf("%d\t" , temp->id);
        printf("%s\t" , temp->name);
        printf("%s\t" , temp->expense_type);
        printf("%d\t" , temp->expense);
        printf("\n");
    }



}