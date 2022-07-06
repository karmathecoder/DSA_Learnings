#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int *A,int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}

void countSort(int *A,int n){
    //Find the maximum element in A
    int max = maximum(A,n);

    //now creating count array by  of size max dynamic memory allocation
    int* count = (int *)malloc((max+1)*sizeof(int));

    //initializing count array to 0
    for (int i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }

    //now incrementing of 1 to count array where A array element matches to index
    for (int i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]]+1;
    }
    int i=0;
    int j=0;
    while (i <= max){
        if (count[i] > 0){
            A[j] = i;
            count[i]=count[i] - 1;
            j++; 
        }
        else{
            i++;
        }
    }
    

}

int main()
{
    int A[] = {3,1,9,7,1,2,4};
    int n = 7;
    printArray(A, n);
    countSort(A,6);
    printArray(A, n);
}