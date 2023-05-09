#include<stdio.h>
#include"Functions/Arrays/array_function.c"

int main()
{
    int size1;
    
    printf("Enter Size of Set-1:\t");
    scanf("%d",&size1);

    int set1[size1];  

    int i = 0;

    for(i = 0 ; i<size1 ; i++)
    {
        printf("Enter Element %d:\t" , i+1);
        scanf("%d" , &set1[i]);
    }

        int size2;
    
    printf("Enter Size of Set-2:\t");
    scanf("%d",&size2);

    int set2[size2];  

    i = 0;

    for(i = 0 ; i<size2 ; i++)
    {
        printf("Enter Element %d:\t" , i+1);
        scanf("%d" , &set2[i]);
    }

    sub_set_checker(set1 , set2 , size1, size2);

    return 0;

}