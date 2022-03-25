#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return(n);
}

void insert(struct node* root, int key){
    struct node* previous = NULL;
    while (root!=NULL)
    {
        previous = root;
        if(root->data == key){
            printf("Cannot be inserted\n");
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    
    struct node* new = createnode(key);
    if(key < previous->data){
        previous->left = new;
    }
    else{
        previous->right = new;
    }
}
int main(){
    struct node* p = createnode(7);
    struct node* p2 = createnode(4);
    struct node* p3 = createnode(8);
    //struct node* p4 = createnode(2);
    struct node* p5 = createnode(5);

    p->left = p2;
    p->right = p3;
    //p2->left = p4;
    p2->right = p5;

    insert(p, 2);
    printf("%d", p->left->left->data);

}