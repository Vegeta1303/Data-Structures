#include<stdio.h>
#include"Functions/Matrix/matrix_function.c"

int main()
{
	int menu;
	printf("What can I do for You?\n\n1. Addition of Matrix 1 and Matrix 2\n2. Subtraction of Matrix 1 and Matrix 2\n3. Multiplication of Matrix 1 and Matrix2 \n4. C[i][j] = X * a[i][j] + Y * b[i][j]\n\nEnter a Number from 1-4, Wrong input will result in Termination of the Program!");

	scanf("%d" , &menu);
	int size;
	printf("Enter Matrix Size:\t");
	scanf("%d" , &size);

	int matrix_1[size][size];
	int matrix_2[size][size];

	int i , j;
	for(i = 0 ; i < size ; i++)
	{
		for(j = 0 ; j < size ; j++)
		{
			printf("Enter Value for Row %d Col %d:\t" , i+1 , j+1);
			scanf("%d" , &matrix_1[i][j]);
		}
	}
		for(i = 0 ; i < size ; i++)
	{
		for(j = 0 ; j < size ; j++)
		{
			printf("Enter Value for Row %d Col %d:\t" , i+1 , j+1);
			scanf("%d" , &matrix_2[i][j]);
		}
	}


	switch(menu)
	{
		case 1: matrix_addition(&matrix_1[0][0] , &matrix_2[0][0] , size); print_matrix(&matrix_1[0][0] , size); break;

		case 2: matrix_subtraction(&matrix_1[0][0] , &matrix_2[0][0] , size); print_matrix(&matrix_1[0][0] , size); break;

		case 3: matrix_multiplication(&matrix_1[0][0] , &matrix_2[0][0] , size); break;

		case 4: 	add_matrix_after_multipy_by_int(&matrix_1[0][0], &matrix_2[0][0] , size); print_matrix(&matrix_1[0][0] , size); break;

		default: return 0;
	}
	

	
	return 0;
}


