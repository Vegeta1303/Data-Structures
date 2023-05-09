#include<stdio.h>
#include "Functions/Arrays/array_function.c"


int main()
{
		int menu;
	printf(" What can I help you with the given array?\n\n1. Reverse the Input array\n2. Find kth Largest and Smallest Element from the Given Array.\n3. Find a Sub-Array for a Given Sum\n4. Move all the Negative-Elements to one Side of the Array\n5. Find the First Repeating and Non-Repeating Element from the Given Array\n\nEnter a Number from 1-5, Wrong input will result in Termination of the Program!\n ");

	scanf("%d" , &menu);
	
	int size;
	printf("Enter the Size of the array:\t");
	scanf("%d" , &size);

	int arr[size];

	for(int i = 0 ; i<size ; i++)
	{
		printf("Enter the %d element:\t" , i+1);
		scanf("%d" , &arr[i]);
	}

	switch(menu)
	{
		case 1: reverse_array(arr , size); break;

		case 2: kth_elements(arr , size); break;

		case 3: sub_array(arr , size); break;

		case 4: negative_elements(arr,size); break;

		case 5: repeating(arr,size); non_repeating(arr,size); break;

		default:
			return 0;
	}



	return 0;
}
