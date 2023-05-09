#include<stdio.h>
#include "matrix_function.h"

void print_matrix(int *matrix , int size)
{
	int i , j;
	for(i = 0 ; i < size ; i++)
	{
		for(j = 0 ; j < size ; j++)
		{
			printf("%d\t" , *(matrix + (i*size) + j));
		}
		printf("\n");
	}
}

void matrix_addition(int *matrix_1 , int *matrix_2 , int size)
{
    int i , j;
	for(i = 0 ; i < size ; i++)
	{
		for(j = 0 ; j < size ; j++)
		{
            *(matrix_1 + (i*size) + j) = *(matrix_1 + (i*size) + j) + *(matrix_2 + (i*size) + j);
		}
	}
}

void multiply_matrix_by_int (int * matrix , int size , int integer)
{
    int i , j;
    for(i = 0 ; i < size ; i++)
	{
		for(j = 0 ; j < size ; j++)
		{
            *(matrix + (i*size) + j) = *(matrix + (i*size) + j) * integer;
		}
	}
}

void matrix_subtraction(int *matrix_1 , int *matrix_2 , int size)
{
    multiply_matrix_by_int(matrix_2 , size ,-1);
    matrix_addition(matrix_1 , matrix_2 , size);
}

void add_matrix_after_multipy_by_int(int *matrix_1 , int *matrix_2 , int size)
{
    int x , y;

    printf("Enter X:\t");
    scanf("%d" ,&x);
    printf("Enter Y:\t");
    scanf("%d" ,&y);

    multiply_matrix_by_int(matrix_1 , size , x);
    
    multiply_matrix_by_int(matrix_2 , size , y);

    matrix_addition(matrix_1 , matrix_2 , size);
}
void matrix_multiplication (int *matrix_1 , int*matrix_2 , int size)
{
    int i , j , k;
    int product[size][size];
    for (i = 0 ; i<size ; i++)
    {
        for(j = 0 ; j<size ; j++)
        {
            product[i][j] = 0;
            {
                for(k = 0 ; k<size;k++)
                {
                    product[i][j] += *(matrix_1 + (i*size) + k) * *(matrix_2 + (k*size)+j);
                }
            }
        }
    }

    print_matrix(&product[0][0] , size);
}

void transpose_matrix(int m , int n ,int matrix[][n], int transpose[][m])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

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
void print_array(int *arr , int size)
{
	int i;
	for(i = 0 ; i<size ; i++)
	{
		printf("%d\t" , *(arr+i));
	}

	printf("\n");

}
void sort_matrix(int size , int matrix[size][size] ,int *temp , int new_size)
{
	int i , j ,k = 0;
	for(i = 0 ; i < size ; i++)
	{
		for(j = 0 ; j < size ; j++)
		{
            *(temp+k) = matrix[i][j];
            k++;
		}
	}
}