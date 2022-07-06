#include <stdio.h>
#include <stdlib.h>

//constructing node structure
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int main(){
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
return 0;
}