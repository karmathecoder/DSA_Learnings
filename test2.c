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

void preOrder(struct node * root){
    if (root != NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(4);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(5);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(3);
    struct node *p5 = createNode(6);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    2   5
    //   /   /  \
    //  1   3   6  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->left = p4;
    p2->right = p5;

    //calling preorder funcion
    preOrder(p);
    
return 0;
}