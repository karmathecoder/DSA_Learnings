# include <stdio.h>

void disp(int arr[],int size){
    for (int i = 0; i < size ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

void insert(int arr[],int size,int capacity,int index, int element){

    if (size >= capacity){
        printf("pverflown");
    } 
    else{
        for (int i = size-1; i >= index; i--)
        {
            arr[i+1]=arr[i];
        }
        arr[index]=element;

        
    }
}

void del(int arr[],int size,int index){

        for (int i = index; i <= size; i++)
        {
            arr[i]=arr[i+1];
        }       
}

int main( ){
    int arr[100]={10,12,14,18,20};
    int size=5, capacity=100, element=19, index=2;
    disp(arr,size);
    
    //insertion functions
    //herer set index to 4
    //insert(arr,size,capacity,index,element);
    //disp(arr,size+1);

    //deletion functions
    //here setting index to 2
     del(arr,size,index);
    disp(arr,size-1);
    
}