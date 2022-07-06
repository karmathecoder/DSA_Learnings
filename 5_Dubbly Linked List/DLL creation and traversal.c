#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

void TraversalInBothDirect(struct Node* head){
    struct Node* ptr=head;
    while (ptr->next != NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
    printf("new\n");
    while (ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->prev;
    }    
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

    head->data=23;
    head->next=second;
    head->prev=NULL;

    second->data=34;
    second->next=third;
    second->prev=head;

    third->data=56;
    third->next=fourth;
    third->prev=second;

    fourth->data=52;
    fourth->next=NULL;
    fourth->prev=third;

    TraversalInBothDirect(head);

}
