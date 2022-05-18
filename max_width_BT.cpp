#include<bits/stdc++.h>
using namespace std;

int max_width(node* root){
    long ans = 0;

    if(root == NULL){
        return ans;
    }

    queue<pair<node*, long> > q;

    q.push({root, 0});

    while(!q.empty()){
        int n = q.size();

        long start = q.front().second;
        long end = q.back().second;

        ans = max(ans, end-start+1);

        for(int i = 0; i < n; i++){
            pair<node*, long> item = q.front();

            node* temp = item.first;
            long prev_index = item.second;

            if(temp->left!=NULL) q.push({temp->left, prev_index*2+1});
            if(temp->right!=NULL) q.push({temp->right, prev_index*2+2});

            q.pop();
        } 
    }

    return ans;
}

int main(){
    node* root = new node(6);
    root->left = new node(5);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(7);
    int ans = max_width(root);
    cout<<ans;
}
