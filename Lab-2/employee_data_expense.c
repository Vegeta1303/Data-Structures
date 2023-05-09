#include "Functions/Linked-List/linked_list_function.c"

int main()
{
    FILE *fp = fopen("data.txt" , "r");

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

    int sum;

    int type;

    printf("Enter \'1\' to get Expense by Type\nEnter \'2\' to get Expense by ID\n");

    scanf("%d" , &type);

    switch (type)
    {
        case 1: sum = get_expense_by_type(head); printf("Total Expense: %d\n" , sum); break;

        case 2: sum = get_expense_by_id(head);
        if (sum == 0) printf("Invalid ID\n");
        else printf("Total Expense: %d\n" , sum); break;
    }

    return 0;
}