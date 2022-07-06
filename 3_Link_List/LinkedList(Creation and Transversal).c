#include <stdio.h>
#include <stdlib.h>

 
struct Node{
    
    int data;
    struct Node * next;
};


//traversing linked list 
void LinkedListTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
     //printing data of head i.e ptr   
    printf("%d\n",ptr->data);
    //after printing data of ptr(head) we update prt to next
    //so that can be used to print the data of second in next loop
    ptr=ptr->next;
    }
    
}



int main(){
    
    //initializing the data type of linkedlist variable

    struct Node *head; 
    struct Node *second;
    struct Node *third;

    //allocated for the nodes in linked list in heap memory 
    head = (struct Node *)malloc(sizeof(struct Node)); 
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    //linking nodes 
    //First and Second Nodes
    head->data=7; 
    head->next=second;

    //Second and Third Nodes
    second->data=8;
    second->next=third;

    //Third and Forth Nodes (Terminating with NULL as 4th)
    third->data=22;
    third->next=NULL;
    
    LinkedListTraversal(head);

    return 0;
}