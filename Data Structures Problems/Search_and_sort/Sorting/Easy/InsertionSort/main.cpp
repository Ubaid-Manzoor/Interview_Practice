// { Driver Code Starts
// C program for insertion sort
#include <stdio.h>
#include <math.h>
void insert(int arr[], int i);

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
   int i;
   for (i = 1; i <n; i++)
      insert(arr, i);
}


/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends


/* The task is to complete insert() which is used
   as shown below to implement insertionSort() */

/* Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
   int i;
   for (i = 1; i < n; i++)
      insert(arr, i);
} */

void swap(int* x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert(int arr[], int i){
    for(int j = i-1 ; j >= 0 ; j--){
        if(arr[j] > arr[i]){
            swap(arr + i, arr + j);
            i = j;
        }else
            break;
    }

}s
