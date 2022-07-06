#include <stdio.h>
#include <stdlib.h>

//describing global variable so that update easily
struct Node* f = NULL;
struct Node* r = NULL;

struct Node{
    int data;
    struct Node* next;
};

void LinkedListTraversal(struct Node* ptr){
    printf("Printing Linked List Elements\n");
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

void enQueue(int val){

    struct Node* n =(struct Node*)malloc(sizeof(struct Node));
    
    if(n==NULL){
        printf("Queue Is Full\n");
    }
    else{
        n->data=val;
        n->next=NULL;
        if (f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

int deQueue(){
    int val = -1;
    struct Node* ptr=f;
    if (f==r){
        printf("queue is empty");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}

int main(){  
    enQueue(5);
    enQueue(6);
    enQueue(7);
    LinkedListTraversal(f);
    printf("Element Deleted is %d\n",deQueue());
    LinkedListTraversal(f);
    
}