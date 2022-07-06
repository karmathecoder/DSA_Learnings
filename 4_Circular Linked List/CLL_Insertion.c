#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};


void TraversalCircularLinkedList(struct Node* head){
    struct Node* p=head;
    /*
    while (p->next != head)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
    */
    do
    {
        printf("%d\n",p->data);
        p=p->next;
    } while (p != head);
    
}

struct Node* InsertAtFirst(struct Node* head,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=head;
    ptr->data=data;
    p=head->next;
    while (p->next != head)
    {
        p=p->next;
    }
    //my p is now pointing at last node
    p->next=ptr;
    ptr->next=head;
    head=ptr;
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
    fourth->next=head;

    TraversalCircularLinkedList(head);
    printf("\n");

    head=InsertAtFirst(head,11);

    TraversalCircularLinkedList(head);
    printf("\n");
}
