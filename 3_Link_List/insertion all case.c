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

//function defining for insertion at first 
struct Node * InsertionAtFirst(struct Node *head,int data){

    //dynamically allocating ptr in heap
    struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
    
    ptr->next=head;
    ptr->data= data;
    
    //this is returning new head in ptr
    return ptr;


}

//function defining for insertion at Last (END) 
struct Node * InsertionAtEnd(struct Node *head,int data){

    //dynamically allocating ptr in heap
    struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
    
    ptr->data= data;
    
    //creating "p" pointer to goto last
    //is = to head so that traversing easily without loosing head 
    struct Node *p=head;

    while (p->next != NULL)
    {
        p=p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    
    //this is returning new head 
    return head;


}

struct Node * InsertionAfterNode(struct Node *head,struct Node *prevNode,int data){

    //dynamically allocating ptr in heap
    struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));
    
    ptr->data= data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    
    
    //returning head 
    return head;


}

//function defining for insertion in between
struct Node * InsertAtIndex(struct Node *head,int data,int index){

    //dynamically allocating ptr in heap
    struct Node *ptr =(struct Node *)malloc(sizeof(struct Node));

    //creating "p" pointer to goto index
    //is = to head so that traversing easily without loosing head 
    struct Node *p=head;
    int i=0;

    while (i != index-1){
        
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next= p->next;
    p->next=ptr;

    //just returning head no changes
    return head;
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
    
    //using InseartionAtFirst
    //storing in head as head is returned and will be new
    head = InsertionAtFirst(head,12);

    //now checking new Linked List
    printf("new list\n");
    LinkedListTraversal(head);

    //using InsertionAtIndex (insertion in between)
    //just storing the return head in this head variable ( althogh will not change)
    head = InsertAtIndex(head,6,2);

    //now checking new Linked List
    printf("new list\n");
    LinkedListTraversal(head);

    //using InsertionAtEnd
    //just storing the return head in this head variable ( althogh will not change)
    head = InsertionAtEnd(head,1);
    
    //now checking new Linked List
    printf("new list\n");
    LinkedListTraversal(head);
    
    //using InsertionAfterNode
    //pasing second as it have adress to second node
    head = InsertionAfterNode(head,second,10);
    
    //now checking new Linked List
    printf("new list\n");
    LinkedListTraversal(head);

    return 0;
}