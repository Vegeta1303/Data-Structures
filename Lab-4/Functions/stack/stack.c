#include"stack.h"

void display()
{
    struct stack * temp = head;

    while(temp != NULL)
    {
        printf("%c" , temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void push(char c)
{
    struct stack * new = malloc(sizeof(struct stack));
    new->data = c;
    new->next = head;
    head = new;
}

char pop()
{
    struct stack * temp;
    char c;
    if(head == NULL)
        printf("UNDERFLOW\n");
    else
    {
        temp = head;
        head = head->next;
        c = temp->data;

        free(temp);
        temp = NULL;
    }

    return c;
}
char top()
{
    return head->data;
}
int Strlen(char * string)
{   
    int i;
    for(i = 0 ; *(string+i)!= '\0' ; i++);

    return i;
}

int isalphabet(char c)
{
    if(c >= 'a' && c <= 'z')
        return 1;
    else if(c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

int precedence(char c)
{
    switch(c)
    {
        case '+' : return 1;
        case '-' : return 1;
        case '/' : return 2;
        case '*' : return 2;
        case '^' : return 3;
        default : return -1;
    }
}

int isOperator(char c)
{
   switch(c)
    {
        case '+' : return 1;
        case '-' : return 1;
        case '/' : return 1;
        case '*' : return 1;
        case '^' : return 1;
        default : return 0;
    }
}

char * InfixToPostfix(char * string , char * postfix)
{
    int x = 0;
    int k = -1;

    while(x != Strlen(string))
    {
        if(isalphabet(*(string+x)))
            postfix[++k] = string[x];

        else if(string[x] == '(')
            push(string[x]);

        else if(string[x] == ')')
        {
            while(1)
            {
                char x = pop();
                if(x!= '(')
                    postfix[++k] = x;
                else    
                    break;
            }
        }
        else if(isOperator(*(string+x)))
        {
            while((head != NULL) && (precedence(string[x]) <= precedence(top())))
                postfix[++k] = pop();
            push(string[x]);

        }
        x++;
    }
    while(head!=NULL)
        postfix[++k] = pop();
    postfix[++k] = '\0';

    return postfix;
}

char * InfixToPrefix(char * string , char * prefix)
{
    string = reverseString(string);

    changeParantheses(string);

    prefix = InfixToPostfix(string , prefix);

    prefix = reverseString(prefix);

    return prefix;
}

char * reverseString(char * string)
{
    int i = 0 , j;
    char * temp = malloc(sizeof(char) * Strlen(string));
    for(i = 0 , j = Strlen(string)-1; i<Strlen(string) ; i++ , j--)
    {
        temp[i] = string[j];
    }

    temp[i] = '\0';
    return temp;
}

void changeParantheses(char * string)
{
    int i = 0;
    for(i = 0 ; i<Strlen(string) ; i++)
    {
        if(string[i] == '(') string[i] = ')';
        else if(string[i] == ')') string[i] = '(';
    }
}

void addMoreMemory(char * string)
{
    string = realloc(string , (Strlen(string)+1)*sizeof(char));
}

char * PostfixToInfix(char * string , char * infix)
{
    int x = 0;
    int k = -1;
    while(x!= Strlen(string))
    {
        if(isalphabet(string[x]))
            push(string[x]);
        else if(isOperator(string[x]))
        {
            char op1 = pop();
            char op2 = pop();

            sprintf(infix , "(%c%c%c)" , op2 , string[x] , op1);
        }
        x++;
    }

    return infix;
}