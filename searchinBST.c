#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return(n);
}

//recursive
struct node* search_recursive(struct node* root, int key){
    if(root == NULL){
        return(NULL);
    }
    else if(root->data == key){
        return(root);
    }
    else if(key < root->data){
        return(search_recursive(root->left, key));
    }
    else
    {
        return(search_recursive(root->right, key));
    }
    
}

//iterative
struct node* search_iterative(struct node* root, int key){
    while(root!=NULL){
    if(root->data == key){
        return(root);
    }
    else if(key < root->data){
        root = root->left;
    }
    else
    {
        root = root->right;
    }
    }
    return(NULL);

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

    struct node* ptr = search_iterative(p, 4);
    if(ptr != NULL){
    printf("Found %d", ptr->data);
    }
    else
    {
        printf("Not found\n");
    }
    
    return(0);

}