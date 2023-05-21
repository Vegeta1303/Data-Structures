#include<stdio.h>
#include<stdlib.h>

struct StLL
{
    int data;
     struct StLL * link;
};

struct StLL * push_ll(struct StLL * head , int data);
int pop_ll(struct StLL * head);
int isEmpty_ll(struct StLL * head);
int peek_ll(struct StLL * head);