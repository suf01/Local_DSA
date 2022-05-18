#include<bits/stdc++.h>
using namespace std;

void validate_Children_Sum_Property(node* &root){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    node* temp = root;
    int sum = 0;

    if(temp->left != NULL){
        sum+=temp->left->data;
    }

    if(temp->right != NULL){
        sum+=temp->right->data;
    }
    
    if(sum < temp->data){
        if(temp->left){
            temp->left->data = sum;
        }

        if(temp->right){
            temp->right->data = sum;
        }
    }else{
        temp->data = sum;
    }
    
    validate_Children_Sum_Property(root->left);
    validate_Children_Sum_Property(root->right);

    int val = 0;

    if(root->left) val+=root->left->data;
    if(root->right) val+=root->right->data;

    if(root->left!=NULL || root->right!=NULL){
        root->data = val;
    }
}

int main(){
    node* root = new node(6);
    root->left = new node(5);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(7);
    
    validate_Children_Sum_Property(root);
    preorder(root);
}
