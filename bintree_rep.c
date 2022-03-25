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

int main(){
    struct node *p = createnode(1);
    struct node *p2 = createnode(2);
    struct node *p3 = createnode(3);

    p->left = p2;
    p->right = p3;

    return(0);
}