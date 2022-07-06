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
        //printf("Enqued element: %d\n", data);
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
    que->size=400;
    que->rear=0;
    que->front=0;
    que->arr = (int *)malloc(que->size * sizeof(int));
    
    // BFS Implementation 
    int node;
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
                    {0,1,1,1,0,0,0},
                    {1,0,1,0,0,0,0},
                    {1,1,0,1,1,0,0},
                    {1,0,1,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0}, 
                    {0,0,0,0,1,0,0} 
                    };
    printf("%d", i);
    visited[i] = 1;
    Enqueue(que, i); // Enqueue i for exploration
    while (!isEmpty(que))
    {
        int node = Dequeue(que);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1;
                Enqueue(que, j);
            }
        }
    }
    return 0;
}
