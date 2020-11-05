// { Driver Code Starts
// C Program for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 255

// The main function that sort the given string arr[] in
// alphabatical order
char* countSort(char arr[]);

// Driver program to test above function
int main()
{
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        long int n;
        scanf("%ld",&n);
        char arr[n+1];
        scanf("%s",arr);
        printf("%s\n", countSort(arr));
    }
    return 0;
}

// } Driver Code Ends


// The main function that sort the given string arr[] in
// alphabatical order
// return the sorted char array
#include <iostream>
using namespace std;
char* countSort(char arr[]){
    int size = strlen(arr);
    int count[RANGE + 1];
    memset(count, 0, sizeof(count));

    char output[size + 1];
    for(int i = 0 ; arr[i] ; ++i)
        count[arr[i]] += 1;

    for(int i = 1 ; i <= RANGE ; ++i)
        count[i] += count[i-1];

    for(int i = 0 ; arr[i] ; ++i){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]] -= 1;
    }

    for (int i = 0; arr[i]; ++i)
        arr[i] = output[i];
    return arr;
}






