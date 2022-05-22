#include<bits/stdc++.h>
using namespace std;

string serialize(node* root){
    string ans = "";

    if(root == NULL){
        return ans;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp){
            ans+=to_string(temp->data)+',';
            q.push(temp->left);
            q.push(temp->right);
        }else{
            ans+="#,";
        }
    }
    return ans;
}

node* deserialize(string tree){
    if(tree.size() < 1 && tree[0]=='#'){
        return NULL;
    }

    stringstream s(tree);

    string str;

    getline(s, str, ',');

    node* root = new node(stoi(str));

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        getline(s, str, ',');

        if(str == "#"){
            temp->left = NULL;
        }else{
            temp->left = new node(stoi(str));
            q.push(temp->left);
        }

        getline(s, str, ',');

        if(str == "#"){
            temp->right = NULL;
        }else{
            temp->right = new node(stoi(str));
            q.push(temp->right);
        }
    }
    return root;
}

int main(){
    node* root = new node(-3);
    root->left = new node(5);
    root->right = new node( 1);
    
    root->left->left = new node(-6);
    root->left->right = new node(-2);

    string str = serialize(root);
    for(auto it: str){
        cout<<it;
    }

    node* root2 = deserialize(str);

    preorder(root2);   
}
