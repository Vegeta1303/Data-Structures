#include "function.h"
void BubbleSort(int arr[], int length)
{
    int i;
    int j;

    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int length)
{
    int i;
    for (i = 0; i < length; i++)
        printf("%d\t", arr[i]);

    printf("\n");
}

void SelectionSort(int arr[], int length)
{
    int i, j, min, temp;

    for (i = 0; i < length - 1; i++)
    {
        min = i;
        for (j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void InsertionSort(int arr[], int length)
{
    int i, j, key;

    for (i = 1; i < length; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void MergeSort(int arr[] , int p , int r)
{
    int q;
    if(p<r)
    {
        q = (p+r)/2;
        MergeSort(arr , p , q);
        MergeSort(arr , q+1 , r);
        merge(arr , p , q , r);
    }
}

void merge(int arr[] , int p , int q , int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1];
    int right[n2];

    int i, j, k;

    for (i = 0; i < n1; i++)
        left[i] = arr[p + i];

    for (j = 0; j < n2; j++)
        right[j] = arr[q + 1 + j];

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k] = left[i++];

        else
            arr[k] = right[j++];
        
        k++;
    }

    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];
}

int plagiarism()
{
    int bool;

    printf("Is the code plagiarised?\n1 - True\n0 - False\n");
    scanf("%d" ,&bool);

    return bool;
}