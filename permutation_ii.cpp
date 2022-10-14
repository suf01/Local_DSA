#include<bits/stdc++.h>
using namespace std;

//approach 1
void find_permutations(vector<int> &nums, int index, vector<vector<int> > &ans){
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    unordered_set<int> s;
    for(int j = index; j < nums.size(); j++){
        if(s.find(nums[j]) != s.end()){
            continue;
        }

        s.insert(nums[j]);
        swap(nums[index], nums[j]);
        find_permutations(nums, index+1, ans);
        swap(nums[index], nums[j]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int> > ans;
    find_permutations(nums, 0, ans);
    return ans;
}
