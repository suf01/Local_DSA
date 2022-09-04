#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> verticalTraversal(TreeNode* root) {
    
    vector<vector<int> > ans;
        
    if(root == NULL){
        return ans;
    }
    
    //stores node, vertical, level    
    queue<pair<TreeNode*, pair<int,int> > > q;
        
    q.push({root, {0, 0}});
        
    /*
    stores vertical -> level -> nodes
    
    use of multiset is because of question constraint, it may contain duplicate nodes,
    if there exists overlap, i,e if the same vertical contains many nodes we want them in
    ascending order or sorted by value;

    */
    map<int, map<int, multiset<int>> > mpp;
        
    while(!q.empty()){
        
        int n = q.size();
            
        for(int i = 0; i < n; i++){
            auto temp = q.front();
            q.pop();
                
            TreeNode* cur_node = temp.first;
            int vertical = (temp.second).first;
            int level = (temp.second).second;
                
            mpp[vertical][level].insert(cur_node->val);
                
            if(cur_node->left){
                q.push({cur_node->left, {vertical-1, level+1}});
            }
            
            if(cur_node->right){
                q.push({cur_node->right, {vertical+1, level+1}});
            }
        }
    }
        
    for(auto it: mpp){
        vector<int> temp;
        for(auto i: it.second){
            for(auto j: i.second){
                temp.push_back(j);
            }
        }
        ans.push_back(temp);
    }
    
    return ans;
}
