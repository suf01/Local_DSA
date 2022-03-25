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

bool gethpath(node* root, int target, vector<int> &ans){
    if(root == NULL){
        return false;
    }

    ans.push_back(root->data);

    if(root->data == target){
        return true;
    }

    if(gethpath(root->left, target, ans) || gethpath(root->right, target, ans)){
        return true;
    }

    ans.pop_back();
    return false;
}

vector<int> path(node* root, int target){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    gethpath(root, target, ans);
    return ans;
}


int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);

    root->right = new node(2);
    root->right->right = new node(8);
    root->right->left = new node(9);

    vector<int> arr = path(root, 6);
    for(auto it : arr){
        cout<<it<<" ";
    }
}