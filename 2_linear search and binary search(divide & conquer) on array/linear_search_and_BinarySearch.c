#include <stdio.h>

int LinearSearch(int arr[],int size,int search){
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==search){
            return i;
        }
    }
    return -1;
}

int BinarySearch(int arr[],int size,int search){
    int low, mid, high;
    low=0;
    high=size-1;
    //searching start
    while (low<=high){
        mid = (low + high) / 2;
        if (arr[mid] == search){
            return mid;
        }
        if(arr[mid]<search){
            low=mid+1;      //as the mid is already check so cheacking just after mid
        }
        else{
            high=mid-1;     //as the mid is already check so cheacking just before mid
        }
    }
    //searching stops
    return -1;
      
}

int main(){
    int arr[100]={10,20,30,40,55,65,70};
    int size=7;
    int search=55;
    
    //for linear search
    
    //int res = LinearSearch(arr,size,search);
    
    //for binary search (will give the result of only one record, i.e might be the 2nd one as it is sorted so occouence will be just adjecent only )

    int res = BinarySearch(arr,size,search);

    printf("Found %d at Index %d\n",search,res);

    return 0;
}

