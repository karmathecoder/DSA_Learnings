#include <stdio.h>
#include <stdlib.h>

//using linked list
struct Node{
    int data;
    struct Node *next;
};

int isEmpty(struct Node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node* top){
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node* Push(struct Node *top,int x){
    if (isFull(top)){
        printf("stack overflow\n");
    }
    else{
        struct Node *n=(struct Node*)malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}

int Pop(struct Node **top){
    if (isEmpty(*top)){
        printf("stack is underflown");
    }
    else{
        /*
        int val=(*top)->data;
        *top=(*top)->next;
        return val;
        free(*top);
        */
       //for memory freeing

       struct Node *n=*top;
       *top=(*top)->next;
       int val = n->data;
       free(n);
       return val;
    }
}

void linkedlisttraversal(struct Node *top){
    while(top != NULL){
        printf("%d\n",top->data);
        top=top->next;
    }    
}

int main(){
    //as here head is top
    struct Node* top = NULL;
    top=Push(top,78);
    top=Push(top,7);
    top=Push(top,8);
    linkedlisttraversal(top);
    printf("element poped is %d\n",Pop(&top));
    linkedlisttraversal(top);

}