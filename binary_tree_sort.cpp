#include<bits/stdc++.h>
using namespace std;

void find_cnt(vector<int> &v, int &cnt){
    vector<int> t = v;
    unordered_map<int, int> mpp;
    sort(t.begin(), t.end());

    int n = v.size();
        
    for(int i = 0; i < n; i++){
        mpp[v[i]] = i;
    }

    for(int i = 0; i < n; i++){
        if(v[i] != t[i]){
            int temp = mpp[t[i]];
            mpp[t[i]] = i;
            mpp[v[i]] = temp;
            swap(v[i], v[temp]);
            cnt++;
        }
    }
}

int minimumOperations(TreeNode* root) {
    if(root == NULL){
        return 0;
    }
        
    if(root->left == NULL && root->right == NULL){
        return 0;
    }
    queue<TreeNode*> q;
        
    if(root->left){
        q.push(root->left);
    }
    if(root->right){
        q.push(root->right);
    }
        
    int cnt = 0;
    vector<vector<int> > temp;
        
    while(!q.empty()){
        int n = q.size();
        vector<int> nums;
            
        for(int i = 0; i < n; i++){
            TreeNode* temp = q.front();
            q.pop();
            nums.push_back(temp->val);
                
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        temp.push_back(nums);
    }

    for(auto it: temp){
        find_cnt(it, cnt);
    }
    return cnt;
}
