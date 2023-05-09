#include<stdio.h>
#include "array_function.h"
void reverse_array(int *arr , int size)
{
	int i = 0 , j = 0;
	for( i = 0 ,  j = size-1; i<size/2 ; i++ , j--)
	{
		int temp = *(arr+i);
		*(arr+i) = *(arr+j);
		*(arr+j) = temp;
	}

	print_array(arr ,size);

}

void sort_array(int *arr , int size)
{	
	int i,j;
	for(i = 0; i<size ; i++)
	{
		for(j = 0 ; j < size ; j++)
		{
			if(*(arr+i) < *(arr+j))
			{
				int temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp;
			}
		}
	}
}

void kth_elements(int *arr , int size)
{
	int k = 0;
	int flag = 1;

	do{
		printf("Enter valid k:\t");
		scanf("%d" , &k);
	}while(k>size/2);

	sort_array(arr , size);
	print_array(arr , size);
	printf("kth largest element:\t %d\n" , *(arr+size-k));
	printf("Kth smallest element:\t %d\n" , *(arr+k-1));
}

void print_array(int *arr , int size)
{
	int i;
	for(i = 0 ; i<size ; i++)
	{
		printf("%d\t" , *(arr+i));
	}

	printf("\n");

}

void sub_array(int *arr , int size)
{
	int i , sum_of_array = 0 , j , k , temp = 0, flag = 0;
	for(i = 0 ; i<size ; i++)
	{
		sum_of_array = sum_of_array + *(arr+i);
	}
	int sum;

	do{
		printf("Enter valid Sum:\t");
		scanf("%d" , &sum);
	}while(sum > sum_of_array);

	for(i = 0 ; i<size ; i++)
	{
		for(j = i ; j<size ; j++)
		{
			temp = temp + *(arr+j);
			if(temp == sum)
			{
				for(k = i ; k<=j ; k++)
				{
					printf("%d\t" , *(arr+k));
				}
				printf("\n");
				flag = 1;
				break;
			}

		}

		temp = 0;

		if(flag == 1) break;
	}

	if(flag == 0)
	{
		printf("Sub-Array was not found for the corresponding Sum");
	}

}

void negative_elements(int *arr ,int size)
{
	int i = 0 , j = 0 , temp;
	for(j = 0 ; j < size ; j++)
	{ 	
		for(i = 0 ; i < size ; i++)
		{
			if(*(arr+i) > 0 && *(arr+i+1) < 0)
			{
				temp = *(arr+i);
				*(arr+i) = *(arr+i+1);
				*(arr+i+1) = temp;
			}
		}
	}

	print_array(arr,size);
}

void repeating(int *arr , int size)
{
	int i , j , flag = 0;
	int duplicate_element;
	for(i = 0 ; i < size ; i++)
	{
		for(j = i+1 ; j<size ; j++)
		{
			if(*(arr+i) == *(arr+j))
			{
				duplicate_element = *(arr+i);
				flag = 1;
			}
		}

		if(flag == 1) break;
	}

	printf("First Duplicate Element:\t%d\n" , duplicate_element);
}

void non_repeating(int *arr, int size)
{
	int flag = 0;
	int i = 0 , j = 0 , k = 0;
	for(i = 0 ; i < size; i++)
	{
		for(j = i+1 ; j < size ; j++)
		{
			if(*(arr+i) == *(arr+j))
			{
				*(arr+i) = 0;
				*(arr+j) = 0;
			}
		}
	}

	for(i = 0 ; i < size ; i++)
	{
		if(*(arr+i) != 0)
		{
			flag = 1;
			printf("First Non-Repeating Element:\t%d\n" , *(arr+i));
		}
		if(flag == 1) break;
	}
	
}

void sub_array_product(int *arr , int size)
{
	int i , j , x;
	int sum1 , sum2;
	int curr , max = 0;
	int temp;

	for(x = 1 ; x<size ; x++)
	{
		int sub_array1[x];

		int y = size-x;

		int sub_array2[y];

		for(i = 0 ; i<x ; i++)
		{
			sub_array1[i] = *(arr+i);
		}
		sum1 = sum_of_array(sub_array1 , x);

		for(i = 0,j = x ; j < size ; i++,j++)
		{
			sub_array2[i] = *(arr+j);
		}	
		sum2 =sum_of_array(&sub_array2[0] , y);

		curr = sum1 * sum2;
		if(curr>max)
		{
			max = curr;
			temp = x;
		}
	}

	for(i = 0 ; i < size ; i++)
	{
		if(i == temp)
		{
			printf("\n%d\t" , *(arr+i));
		}

		else
		{
			printf("%d\t", *(arr+i));
		}
	}

	printf("\n");
}

int sum_of_array(int *arr , int size)
{
	int sum = 0;
	int i = 0;
	for(i = 0 ;i<size ; i++)
	{
		sum = sum + *(arr + i);
	}

	return sum;
}

int max_of_array(int *arr , int size)
{
	int max = 0;	
	int i;

	for(i = 0 ; i<size ; i++)
	{
		if(*(arr+i) > max )
		{
			max = *(arr+i);
		}
	}

	return max;
}

void remove_duplicates(int *arr , int size)
{
	int i , j;
	for(i = 0 ; i<size ; i++)
	{
		for(j = i+1 ; j<size ; j++)
		{
			if(*(arr+i) == *(arr+j))
			{
				delete_element(arr , size , j);
				size--;
			}
		}
	}

	print_array(arr , size);
}

void delete_element(int *arr , int size , int index)
{
	int i,j;

	for(i = 0 ; i<size ; i++)
	{
		if(i == index)
		{
			for(j = i ; j<size ;j++)
			{
				*(arr+j) = *(arr+j+1); 
			}	
		}
	}
}

void difference_of_sub_array(int *arr , int size)
{
	int i , j , x , p;
	int difference_array[size-1];
	int sum_left, sum_right;

	for(x = 1 , p = 0; x<size ; p++, x++)
	{
		int sub_array_left[x];

		int y = size-x;

		int sub_array_right[y];

		for(i = 0 ; i<x ; i++)
		{
			sub_array_left[i] = *(arr+i);
		}
		sum_left = sum_of_array(sub_array_left , x);

		for(i = 0,j = x ; j < size ; i++,j++)
		{
			sub_array_right[i] = *(arr+j);
		}	
		sum_right =sum_of_array(&sub_array_right[0] , y);

		difference_array[p] = sum_left - sum_right;

	}

	print_array(difference_array , size-1);

}

void sub_set_checker(int *set1 , int *set2, int size1 , int size2)
{
	int i,j;
	int count = 0;
	for(i = 0 ; i<size2 ; i++)
	{
		for(j = 0 ; j<size1 ; j++)
		{
			if( *(set2+i)== *(set1+j))
			{
				count++;
			}
		}
	}

	if(count == size2)
	{
		printf("Set A2 is a Subset of A1\n");
	}
	else
	{
		printf("Set A2 is NOT a Subset of A1\n");
	}
}