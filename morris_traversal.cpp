#include<bits/stdc++.h>
using namespace std;

vector<int> morris_inorder(node* root){
    vector<int> inorder;

    if(root == NULL){
        return inorder;
    }

    node* curr = root;

    while(curr!=NULL){
        if(curr->left == NULL){
            inorder.push_back(curr->data);
            curr = curr->right;
        }else{
            node* prev = curr->left;

            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

vector<int> morris_preorder(node* root){
    vector<int> preorder;

    if(root == NULL){
        return preorder;
    }

    node* curr = root;

    while(curr!=NULL){
        if(curr->left == NULL){
            preorder.push_back(curr->data);
            curr = curr->right;
        }else{
            node* prev = curr->left;

            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                preorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return preorder;
}

int main(){
    node* root = new node(-3);
    root->left = new node(5);
    root->right = new node( 1);
    
    root->left->left = new node(-6);
    root->left->right = new node(-2);

    vector<int> ans = morris_inorder(root);

    for(auto it: ans){
        cout<<it<<" ";
    }   
}
