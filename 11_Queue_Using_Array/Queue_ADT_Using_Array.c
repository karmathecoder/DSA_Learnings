#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int* arr;
};

int isEmpty(struct queue *qu){
    if (qu->front == qu->rear){
        return 1;
    }
    return 0;
}

int isFull(struct queue *qu){
    if (qu->rear == qu->size-1){
        return 1;
    }
    return 0;
}

void Traversal(struct queue* que){
    int i = 0;
    while (i<=que->rear){
        printf("%d\n",que->arr[i]);
        i++;
    }
    
}

void Enqueue(struct queue *que,int data){
    if (isFull(que)){
        printf("queue overflown");
    }
    else{
        que->rear++;
        que->arr[que->rear]=data;
        printf("Enqued element: %d\n", data);
    }
}

int Dequeue(struct queue *que){
    int a = -1;
    if (isEmpty(que)){
        printf("queue underflow");
    }
    else{
        que->front++;
        a = que->arr[que->front];
    }
    return a;
}


int main(){
    struct queue *que;
    que=(struct queue *)malloc(sizeof(struct queue));
    que->size=4;
    que->rear=-1;
    que->front=-1;
    que->arr = (int *)malloc(que->size * sizeof(int));
    
    //inserting in queue
    Enqueue(que,7);
    Enqueue(que,17);
    Enqueue(que,70);
    Enqueue(que,77);

    printf("Dequeuing element %d\n", Dequeue(que));
    printf("Dequeuing element %d\n", Dequeue(que));
    printf("Dequeuing element %d\n", Dequeue(que));
    printf("Dequeuing element %d\n", Dequeue(que));

    Enqueue(que,77);

    //Traversal(que);
}
