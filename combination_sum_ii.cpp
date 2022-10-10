#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &candidates, int i, int target, vector<int> temp, vector<vector<int> > &ans){
    
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    if(target < 0){
        return;
    }
    if(i >= candidates.size()){
        return;
    }

    for(int j = i; j < candidates.size(); j++){
        if(candidates[j] > target){
            return;
        }
        if(j > i && candidates[j] == candidates[j-1]){
            continue;
        }
        
        temp.push_back(candidates[j]);
        solve(candidates, j+1, target-candidates[j], temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int> > ans;
    sort(candidates.begin(), candidates.end());
    vector<int> temp;

    solve(candidates, 0, target, temp, ans);
    return ans;
}
