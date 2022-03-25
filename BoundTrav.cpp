#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void leftboundary(node* root){
    if(root == NULL){
        return;
    }

    if(root->left != NULL){
        cout<<root->data<<" ";
        leftboundary(root->left);
    }else if(root->right != NULL){
        cout<<root->data<<" ";
        leftboundary(root->right);
    }
}

void leafboundary(node* root){
    if(root == NULL){
        return;
    }
    leafboundary(root->left);
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    leafboundary(root->right);
}

void rightboundary(node* root){
    if(root == NULL){
        return;
    }

    if(root->right != NULL){
        rightboundary(root->right);
        cout<<root->data<<" ";
    }else if(root->left != NULL){
        rightboundary(root->left);
        cout<<root->data<<" ";
    }
}

void boundarytrav(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    leftboundary(root->left);
    leafboundary(root->left);
    leafboundary(root->right);
    rightboundary(root->right);
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);

    root->right = new node(5);
    root->right->right = new node(7);
    root->right->left = new node(8);

    boundarytrav(root);
}