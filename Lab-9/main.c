#include"functions/function.c"

int main()
{
    int length;
    int i;
    int menu;

    printf("Enter Length of the Array:\t");
    scanf("%d" , &length);
    int arr[length];

    for(i = 0 ; i<length ; i++)
    {
        printf("Enter Data:\t");
        scanf("%d" , &arr[i]);
    }
    printArray(arr,length);

    printf("1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Merge Sort\n5. Quick Sort\n6. Heap Sort\n7.Exit\nEnter:\t");

    scanf("%d" , &menu);

    do
    {
        switch (menu)
        {
            case 1: BubbleSort(arr,length);
                    printArray(arr,length);
                    break;

            case 2: InsertionSort(arr,length);
                    printArray(arr,length);
                    break;

            case 3: SelectionSort(arr, length);
                    printArray(arr, length);
                    break;

            case 4: MergeSort(arr, 0 , length-1);
                    printArray;
                    break;

            case 5: 
                    break;

            case 6:
                    break;

            case 7: printf("Exiting...\n");
                    return 0;

            default:
                    return 0;
        }

    } while(menu != 7 && !plagiarism());

        
    
    return 0;
}
