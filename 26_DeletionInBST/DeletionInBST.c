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
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void BSTinsert(struct node *root, int key){
   struct node *prev = NULL;
   while(root!=NULL){
       prev = root;
       if(key==root->data){
           printf("Cannot insert %d, already in BST", key);
           return;
       }
       else if(key<root->data){
           root = root->left;
       }
       else{
           root = root->right;
       }
   }
   struct node* new = createNode(key);
   if(key<prev->data){
       prev->left = new;
   }
   else{
       prev->right = new;
   }
}

struct node * inOrderPredecessor(struct node * root){
    root = root -> left;
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node * DelNodeBST(struct node * root,int value){
    struct node * iPre;
    if (root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    //searching for node to be deleted
    if (value < root->data){
        root -> left = DelNodeBST(root->left,value);
    }
    else if (value > root->data){
        root -> right = DelNodeBST(root->right,value);
    }

    //deletion stategy when the node is found
    else{
        iPre=inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = DelNodeBST(root->left,iPre->data);
    }
    return root;
}

int main(){
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;


    inOrder(p);
    printf("\n");
    DelNodeBST(p,4);
    inOrder(p);
    return 0;
}