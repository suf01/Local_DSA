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

bool leafnode(node* temp){
    if(temp->left==NULL && temp->right==NULL){
        return true;
    }else{
        return false;
    }
}

void addleft(node* root, vector<int> &ans){
    node* temp = root;

    while(temp){
        if(!leafnode(temp)) ans.push_back(temp->data);

        if(temp->left!=NULL){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
}

void addrigth(node* root, vector<int> &ans){
    node* temp = root->right;
    stack<node*> st;

    while(temp){
        if(!leafnode(temp)){
            st.push(temp);
        }

        if(temp->right!=NULL){
            temp = temp->right;
        }else{
            temp = temp->left;
        }
    }

    while(!st.empty()){
        node* ele = st.top();
        st.pop();
        ans.push_back(ele->data);
    }
}

void addleaf(node* root, vector<int> &ans){
    node* temp = root;

    if(leafnode(temp)){
        ans.push_back(temp->data);
    }

    if(temp->left!=NULL){
        addleaf(temp->left, ans);
    }

    if(temp->right!=NULL){
        addleaf(temp->right, ans);
    }
}

vector<int> boundary_traversal(node* root){
    vector<int> ans;
    if(root == NULL) return ans;

    addleft(root, ans);
    addleaf(root, ans);
    addrigth(root, ans);

    return ans;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);

    root->right = new node(5);
    root->right->right = new node(7);
    root->right->left = new node(8);

    bector<int> ans = boundary_traversal(root);
    
    for(auto it: ans){
        cout<<it<<" ";
    }
}
