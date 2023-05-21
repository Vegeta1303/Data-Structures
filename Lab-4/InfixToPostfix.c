#include"Functions/stack/stack.c"

int main()
{
    char * string;
    char * postfix;
    char * prefix;
    char * infix;
    char c;

    int i = 0 , j = 1;

    string = (char *)malloc(sizeof(char));
    postfix = (char *)malloc(sizeof(char));
    prefix = (char *)malloc(sizeof(char));
    infix = (char *)malloc(sizeof(char));

    printf("Enter Expression:\n");
    while(c != '\n')
    {
        scanf("%c" , &c);

        string = (char *)realloc(string , j*sizeof(char));

        string[i] = c;
        i++; j++;
    }

    postfix = (char *)realloc(postfix , (j-1)*sizeof(char));

    // prefix = (char *)realloc(prefix , (j-1)*sizeof(char));

    
    string[i] = '\0';
  
    printf("%s\n" , InfixToPostfix(string,postfix));
    // printf("%s\n" , InfixToPrefix(string , prefix));

    // infix = PostfixToInfix(string , infix);
    // printf("%s\n" , infix);

    // display();
    return 0;
}