#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};


void TraversalLinkedList(struct Node* head){
    while (head!=NULL)
    {
        printf("%d\n",head->data);
        head=head->next;

    }
    
}

struct Node* DeletionAtFirst(struct Node* head){

    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct Node* DeletionAtIndex(struct Node* head,int index){

    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    p=head;
    int i=0;
    while(i < index-1){
        p=p->next;
        i++;
    }
    struct Node* q=(struct Node*)malloc(sizeof(struct Node));
    q=p->next;
    p->next=q->next;
    free(q);
    return head;
}

struct Node* DeletionAtEnd(struct Node* head){
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    struct Node* q=(struct Node*)malloc(sizeof(struct Node));
    p=head;
    q=p->next;
    while (q->next != NULL){
        q=q->next;
        p=p->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct Node* DeleteAtNodeWithValue(struct Node* head,int value){
    //will delete the first dta if 2 8 are there then 1st in traversing
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    struct Node* q=(struct Node*)malloc(sizeof(struct Node));
    p=head;
    q=p->next;
    int i=q->data;
    while (i != value)
    {
        q=q->next;
        p=p->next;
        i=q->data;
    }
    p->next=q->next;
    free(q);
    return head;

}

int main(){

    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    //first
    head->data=4;
    head->next=second;

    second->data=3;
    second->next=third;

    third->data=8;
    third->next=fourth;

    fourth->data=1;
    fourth->next=NULL;

    TraversalLinkedList(head);
    printf("\n");

    //head = DeletionAtFirst(head);

    //head= DeletionAtIndex(head,1);

    //head = DeletionAtEnd(head);
    
    head = DeleteAtNodeWithValue(head,8);

    TraversalLinkedList(head);
    printf("\n");

}
