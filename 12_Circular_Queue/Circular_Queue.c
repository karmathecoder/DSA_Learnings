#include <stdio.h>
#include <stdlib.h>

struct circularQueue{
    int size;
    int front;
    int rear;
    int* arr;
};

int isEmpty(struct circularQueue *qu){
    if (qu->rear == qu->front){
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *qu){
    if ((qu->rear+1)%qu->size == qu->front){
        return 1;
    }
    return 0;
}

// void Traversal(struct circularQueue* que){
//     int i = 0;
//     while (i<=que->rear){
//         printf("%d\n",que->arr[i]);
//         i++;
//     }
    
// }

void EnQueue(struct circularQueue *que,int data){
    if (isFull(que)){
        printf("Queue overflown\n");
    }
    else{
        que->rear=(que->rear+1)%que->size;
        que->arr[que->rear]=data;
        printf("Enqued element: %d\n", data);
    }
}

int DeQueue(struct circularQueue *que){
    int a = -1;
    if (isEmpty(que)){
        printf("Queue underflow\n");
    }
    else{
        que->front=(que->front+1)%que->size;
        a = que->arr[que->front];
    }
    return a;
}


int main(){
    struct circularQueue *que;
    que=(struct circularQueue *)malloc(sizeof(struct circularQueue));
    //size is 4 but we can use only 3 as 1 will be empty
    que->size=4;
    //this is the 0 that will remain empty forever
    que->rear=0;
    que->front=0;
    que->arr = (int *)malloc(que->size * sizeof(int));
    
    //inserting in circularQueue
    EnQueue(que,7);
    EnQueue(que,17);
    EnQueue(que,70);
   

    printf("Dequeuing element %d\n", DeQueue(que));
    printf("Dequeuing element %d\n", DeQueue(que));
    printf("Dequeuing element %d\n", DeQueue(que));
   


    if(isEmpty(que)){
        printf("Queue is empty\n");
    }
    if(isFull(que)){
        printf("Queue is full\n");
    }

    //Traversal(que);
}
