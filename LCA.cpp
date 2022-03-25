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

node* LCA(node* root, node* p, node* q){
    if(root == NULL || root == p || root == q){
        return root;
    }

    node* left = LCA(root->left, p, q);
    node* right = LCA(root->right, p, q);

    if(left == NULL){
        return right;
    }else if(right == NULL){
        return left;
    }else{
        return root;
    }
}


int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);

    root->right = new node(3);
    root->right->right = new node(8);
    root->right->left = new node(9);

    node* ans = LCA(root, root->left->left, root->left->right->left);

    cout<<ans->data;

}