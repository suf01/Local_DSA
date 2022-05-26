#include<bits/stdc++.h>
using namespace std;

node* prevs = NULL;
void flatten(node* root){
    if(root == NULL){
        return;
    }

    flatten(root->right);
    flatten(root->left);

    root->right = prevs;
    root->left = NULL;

    prevs = root;
}

int main(){
    node* root = new node(-3);
    root->left = new node(5);
    root->right = new node( 1);
    
    root->left->left = new node(-6);
    root->left->right = new node(-2);
  
    flatten(root);
}
