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

void topview(node* root){
    if(root == NULL){
        return;
    }

    // line, node
    map<int, int> mpp;
    //node, line
    queue<pair<node*, int> > q;

    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        node* node = it.first;
        int line = it.second;

        q.pop();

        if(mpp.find(line) == mpp.end()){
            mpp[line] = node->data;
        }

        if(node->left){
            q.push({node->left, line-1});
        }

        if(node->right){
            q.push({node->right, line+1});
        }
    }

    vector<int> ans;

    for(auto ele : mpp){
        ans.push_back(ele.second);
    }

    for(auto ele : ans){
        cout<<ele<<" ";
    }
}

void bottomview(node* root){
    if(root == NULL){
        return;
    }

    //node, line
    queue<pair<node*, int> > q;
    //line, node
    map<int, int> mpp;

    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();

        node* node = it.first;
        int line = it.second;

        q.pop();

        mpp[line] = node->data;

        if(node->left){
            q.push({node->left, line-1});
        }

        if(node->right){
            q.push({node->right, line+1});
        }
    }

    vector<int> ans;

    for(auto ele : mpp){
        ans.push_back(ele.second);
    }

    for(auto ele : ans){
        cout<<ele<<" ";
    }
}

void findview(node* &node, int level, vector<int> &ans){
    if(node == NULL){
        return;
    }

    if(level == ans.size()){
        ans.push_back(node->data);
    }

    //for right view
    if(node->right){
        findview(node->right, level+1, ans);
    }
    if(node->left){
        findview(node->left, level+1, ans);
    }

    /* for left view
    if(node->left){
        findview(node->left, level+1, ans);
    }
    if(node->right){
        findview(node->right, level+1, ans);
    }
    */
}

void leftrightview(node* root){
    vector<int> ans;
    findview(root, 0, ans);

    for(auto ele : ans){
        cout<<ele<<" ";
    }
}


int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);

    root->right = new node(5);
    root->right->right = new node(7);
    root->right->left = new node(8);

    topview(root);
    bottomview(root);
    leftrightview(root);
}