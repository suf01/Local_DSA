#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int> preorder_it(node* root){
    stack<node*> st;
    vector<int> ans;

    if(root == NULL) return ans;

    st.push(root);

    while(!st.empty()){
        node* temp = st.top();
        st.pop();
        ans.push_back(temp->data);

        if(temp->right!=NULL){
            st.push(temp->right);
        }

        if(temp->left!=NULL){
            st.push(temp->left);
        }
    }

    return ans;
}

vector<int> inorder_it(node* root){
    stack<node*> st;
    node* temp = root;
    vector<int> ans;

    while(1){
        if(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }else{
            if(st.empty()){
                break;
            }
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

vector<int> postorder_it(node* root){
    stack<node*> st1;
    stack<node*> st2;

    st1.push(root);

    while(!st1.empty()){
        node* temp = st1.top();
        st1.pop();
        st2.push(temp);

        if(temp->left!=NULL){
            st1.push(temp->left);
        }
        if(temp->right!=NULL){
            st1.push(temp->right);
        }
    }

    vector<int> ans;
    while(!st2.empty()){
        node* temp = st2.top();
        st2.pop();
        ans.push_back(temp->data);
    }
    return ans;
}

int main(){
    node* root = new node(6);
    root->left = new node(5);
    root->right = new node(4);
    root->left->left = new node(9);
    root->left->right = new node(7);

    vector<int> v = postorder_it(root);

    for(auto it: v){
        cout<<it<<" ";
    }
}