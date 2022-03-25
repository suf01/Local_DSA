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

bool isSymmetricHelp(node* left, node* right){
    if(left == NULL || right == NULL){
        return left == right;
    }

    if(left->data != right->data){
        return false;
    }

    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(node* root){
    return root == NULL || isSymmetricHelp(root->left, root->right);
}


int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);

    root->right = new node(2);
    root->right->right = new node(3);
    root->right->left = new node(4);

    cout<<isSymmetric(root);
}