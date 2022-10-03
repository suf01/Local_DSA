#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& candidates, int i, int target, vector<int> temp, vector<vector<int> > &ans){
    if(i == candidates.size() || i > candidates.size()){
        return;
    }    
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    if(target < 0){
        return;
    }

    solve(candidates, i+1, target, temp, ans);
        
    temp.push_back(candidates[i]);
    solve(candidates, i, target-candidates[i], temp, ans);
    temp.pop_back();
}
    
vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<int> temp;
    vector<vector<int> > ans;
    solve(candidates, 0, target, temp, ans);

    return ans;
}
