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

bool isSymmetricHelp(node* root1, node* root2){
    if(root1 == NULL || root2 == NULL){
        return root1 == root2;
    }

    if(root1->data != root2->data){
        return false;
    }

    return isSymmetricHelp(root1->left, root2->right) && isSymmetricHelp(root1->right, root2->left);
}

bool isSymmetric(node* root){
    if(root == NULL){
        return false;
    }
    
    return isSymmetricHelp(root->left, root->right);
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
