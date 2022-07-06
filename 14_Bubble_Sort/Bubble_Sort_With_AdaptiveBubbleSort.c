#include <stdio.h>

void BubbleSort(int* A,int n){
    int temp;
    for (int i = 0; i < n-1; i++) //For number of pass
    {
        for (int j = 0; j < n-1-i; j++) //For Comparision In each pass
        {
            if (A[j] > A[j+1]) //checking swaping condition
            {
            temp = A[j];
            A[j]=A[j+1];
            A[j+1] = temp;
            }
        }        
    }
}

void BubbleSortAdaptive(int* A,int n){
    int temp;
    int isSorted=0;
    for (int i = 0; i < n-1; i++) //For number of pass
    {
        printf("working on pass number %d\n", i+1);
        isSorted=1;
        for (int j = 0; j < n-1-i; j++) //For Comparision In each pass
        {
            if (A[j] > A[j+1]) //checking swaping condition
            {
            temp = A[j];
            A[j]=A[j+1];
            A[j+1] = temp;
            isSorted=0;
            }
        }
        if (isSorted){
            return;
        }        
    }
}

void printArray(int* A,int n){
    for (int i = 0; i < n ; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");    
}

int main(){

    int A[] = {12,54,65,7,23,9};
    int B[] = {1,2,3,4,5,6};
    int n = 6;
    int n2 = 6;
    printArray(A,n); //Printing Array before sorting
    BubbleSort(A,n); //Function to sort
    printArray(A,n); //Printing Array after sorting
    BubbleSortAdaptive(B,n2);
    printArray(B,n2); //Printing Array after sorting

    return 0;
}