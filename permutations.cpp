#include<bits/stdc++.h>
using namespace std;

void find_permute(vector<int> nums, vector<int> temp, vector<vector<int> > &ans){
    if(nums.size() == 0){
        ans.push_back(temp);
        return;
    }

    for(int i = 0; i < nums.size(); i++){
        temp.push_back(nums[i]);

        vector<int> nums2;
        for(int j = 0; j < nums.size(); j++){
            if(i != j){
                nums2.push_back(nums[j]);
            }
        }
            
        find_permute(nums2, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int> > permute(vector<int>& nums){
    vector<vector<int> > ans;
    vector<int> temp;

    find_permute(nums, temp, ans);
    return ans;
}
