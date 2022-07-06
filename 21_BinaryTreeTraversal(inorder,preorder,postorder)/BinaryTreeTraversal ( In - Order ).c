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

void inOrder(struct node * root){
    if (root != NULL){
        inOrder(root->left);
        printf("%d",root->data);
        inOrder(root->right);
    }
}

int main(){
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    //calling preorder funcion
    inOrder(p);
    
return 0;
}