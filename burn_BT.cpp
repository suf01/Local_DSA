#include<bits/stdc++.h>
using namespace std;

int burn_BT(node* root, int target){

    if(root == NULL){
        return 0;
    }

    unordered_map<node*, node*> parent;
    queue<node*> p;

    p.push(root);

    node* start = NULL;

    int dis = 0;
    while(!p.empty()){
        node* temp = p.front();
        p.pop();

        if(temp->data == target){
            start = temp;
        }

        if(temp->left){
            parent[temp->left] = temp;
            p.push(temp->left);
        }

        if(temp->right){
            parent[temp->right] = temp;
            p.push(temp->right);
        }
    }

    queue<node*> q;
    unordered_map<node*, int> vis;

    q.push(start);
    vis[start] = 1;

    while(!q.empty()){
        int n = q.size();
        int flag = 0;

        for(int i = 0; i < n; i++){
            node* temp = q.front();
            q.pop();

            if(temp->left && vis[temp->left]!=1){
                q.push(temp->left);
                vis[temp->left] = 1;
                flag = 1;
            }

            if(temp->right && vis[temp->right]!=1){
                q.push(temp->right);
                vis[temp->right] = 1;
                flag = 1;
            }

            if(parent.find(temp)!=parent.end()){
                node* par = parent[temp];
                if(vis[par]!=1){
                    q.push(par);
                    vis[par] = 1;
                    flag = 1;
                }
            }
        }

        if(flag){
            dis++;
        }
    }
    return dis;
}

int main(){
    node* root = new node(3);
    node* A = root->left = new node(5);
    root->right = new node(1);
    
    root->left->left = new node(6);
    root->left->right = new node(2);

    root->left->right->left = new node(7);
    root->left->right->right = new node(4);

    root->right->left = new node(0);
    root->right->right = new node(8);
    
    cout<<burn_BT(root, 4);
}
