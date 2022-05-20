#include<bits/stdc++.h>
using namespace std;

vector<int> node_at_distance_K(node* root, node* target, int k){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    queue<node*> q;

    unordered_map<node*, node*> parent;
    q.push(root);

    while(!q.empty()){
        int n = q.size();

        for(int i = 0; i < n; i++){
            node* temp = q.front();
            q.pop();

            if(temp->left){
                parent[temp->left] = temp;
                q.push(temp->left);
            }

            if(temp->right){
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

    for(auto it: parent){
        cout<<it.first->data<<" "<<it.second->data<<endl;
    }

    queue<node*> qq;
    unordered_map<node*, int> vis;
    int dis = 0;

    qq.push(target);
    vis[target] = 1;

    while(!qq.empty()){

        if(dis == k){
            break;
        }

        int n = qq.size();
        for(int i = 0; i < n; i++){

            node* curr = qq.front();
            qq.pop();
            cout<<"curr "<<curr->data<<endl;

            if(curr->left && vis[curr->left]!=1){
                qq.push(curr->left);
                vis[curr->left] = 1;
                cout<<"curr left "<<curr->left->data<<endl;
            }
            if(target->right && vis[curr->right]!=1){
                qq.push(curr->right);
                vis[curr->right] = 1;
                cout<<"curr right "<<curr->right->data<<endl;
            }

            if(parent.find(curr)!=parent.end()){
                node* par = parent[curr];
                if(vis[par]!=1){
                    qq.push(par);
                    vis[par] = 1;
                }
            }
        }
        dis++;
    }

    while(!qq.empty()){
        ans.push_back(qq.front()->data);
        qq.pop();
    }
    return ans;
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
    
    vector<int> ans = node_at_distance_K(root, A, 2);
    for(auto it: ans){
        cout<<it<<" ";
    }
}
