#include <stdio.h>
#include <stdlib.h>

//constructing node structure
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; //creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); //allocating memory in heap dynamically
    n->data = data; //setting data to data
    n->left = NULL; //setting left children to NULL
    n->right = NULL; //setting right children to NULL
    return n; //returning the node
}

int main(){
    /*
    //constructing root node
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    //constructing second node
    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p1->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // constructing third node
    struct node *p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p2->data = 4;
    p2->left = NULL;
    p2->right = NULL;
    
    //linking root node with left and right children
    p->left = p1;
    p->right = p2;

    */

    //creating root node
    struct node *p = createNode(2);

    //constructing second node
    struct node *p1 = createNode(1);

    // constructing third node
    struct node *p2 = createNode(4);

    //linking root node with left and right children
    p->left = p1;
    p->right = p2;

return 0;
}