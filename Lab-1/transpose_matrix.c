#include<stdio.h>
#include"Functions/Matrix/matrix_function.c"

int main()
{
    int m,n;
    int i,j;
    printf("Enter Rows:\t");
    scanf("%d" , &m);
    printf("Enter Cols:\t");
    scanf("%d" , &n);

    int size;

    int matrix [m][n];

    for(i = 0 ; i<m ; i++)
    {
        for(j = 0; j<n ; j++)
        {
            printf("Enter Element for Row %d and Col %d:\t" , i+1 , j+1);
            scanf("%d" , &matrix[i][j]);
        }
    }
    
    int transpose[n][m];

    transpose_matrix(m,n,matrix, transpose);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
        printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }


}