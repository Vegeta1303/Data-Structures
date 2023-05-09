#include<stdio.h>
#include"Functions/Arrays/array_function.c"

int main()
{
    int size;
    
    printf("Enter Size of Array:\t");
    scanf("%d",&size);

    int arr[size];  

    int i = 0;

    for(i = 0 ; i<size ; i++)
    {
        printf("Enter Element %d:\t" , i+1);
        scanf("%d" , &arr[i]);
    }
    
    remove_duplicates(arr , size);
    return 0;
}