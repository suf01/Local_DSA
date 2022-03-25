#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return(n);
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int isBST(struct node* root){
    
    static struct node* previous = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return(0);
        }
        if(previous!=NULL && root->data <= previous->data){
            return(0);
        }
        previous = root;
        return(isBST(root->right));

    }
    else{
        return(1);
    }
}

int main(){
    struct node* p = createnode(7);
    struct node* p2 = createnode(4);
    struct node* p3 = createnode(8);
    struct node* p4 = createnode(2);
    struct node* p5 = createnode(5);

    p->left = p2;
    p->right = p3;
    p2->left = p4;
    p2->right = p5;

    inorder(p);
    printf("\n");
    printf("%d", isBST(p));

}