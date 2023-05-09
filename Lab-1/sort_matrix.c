#include<stdio.h>
#include"Functions/Matrix/matrix_function.c"

int main()
{
    int size;
	printf("Enter Matrix Size:\t");
	scanf("%d" , &size);

    int matrix[size][size];

	int i , j;
	for(i = 0 ; i < size ; i++)
	{
		for(j = 0 ; j < size ; j++)
		{
			printf("Enter Value for Row %d Col %d:\t" , i+1 , j+1);
			scanf("%d" , &matrix[i][j]);
		}
	}
    int new_size = size*size;
    int temp[new_size];

    sort_matrix(size ,matrix , temp , new_size);

    sort_array(temp , new_size);

    print_array(temp, new_size);

    return 0;
}