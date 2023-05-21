#include<stdio.h>
#include<stdlib.h>

struct stack
{
    char data;
    struct stack * next;
} * head = NULL;

void display();
void push(char c);
char pop();
char top();
int Strlen(char * string);
int isalphabet(char c);
char * InfixToPostfix(char * string , char * postfix);
char * reverseString(char * string);
void changeParantheses(char * string);
void addMoreMemory(char * string);
char * PostfixToInfix(char * string , char * infix);