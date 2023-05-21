#include"Functions/stack-array/array_function.c"
#include"Functions/stack-ll/ll_function.c"
int main()
{
    int type; int menu; int size; int data; int temp;
    printf("Enter 1 for Stack Implementation using Array\nEnter 2 for Stack Implementation using Linked List\nWrong input leads to termination:\n");
    scanf("%d" , &type);
   

    switch(type)
    {
        case 1:
            printf("Enter Size of Array:\t");
            scanf("%d" , &size);

            struct StArr stack;
            stack.arr = malloc(size * sizeof(int));

            stack.size = size;
            stack.top = -1;

            for(int i = 0 ; i<size ; i++)
            {
                printf("Enter Data (-1 Quits):\t");
                scanf("%d" , &data);
                if(data == -1) break;
                push_arr(&stack , data);
            }

            printf("1. isEmpty()\n2. isFull()\n3. push()\n4. pop()\n5. peek()\n");

            scanf("%d" , &menu);

            switch(menu)
            {
                case 1: 
                    temp = isEmpty(&stack); 
                    if(temp == 1)printf("Stack is EMPTY"); 
                    else printf("Stack is NOT Empty\n");
                    break;

                case 2: 
                    temp = isFull(&stack); 
                    if(temp == 1)printf("Stack is FULL"); 
                    else printf("Stack is NOT Full\n");
                    break;

                case 3: 
                    printf("Enter Data:\t"); scanf("%d" , &data); 
                    push_arr(&stack , data); 
                    display_array(stack);
                    break;

                case 4: printf("%d\n" , pop_arr(&stack));break;

                case 5: printf("%d\n" , peek(stack));
            }   

            break;
        
        case 2: break;
            
    }
    

    return 0;
}