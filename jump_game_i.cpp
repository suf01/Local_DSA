#include<bits/stdc++.h>
using namespace std;

// greedy
bool check(vector<int> &nums, int pos, int i){
    if(pos == 0){
        return true;
    }

    if(i < 0){
        return false;
    }

    if(nums[i]+i >= pos){
        pos = i;
        if(check(nums, pos, i-1)){
            return true;
        }
    }else{
        if(check(nums, pos, i-1)){
            return true;
        }
    }
    return false;
}

bool canJump(vector<int>& nums) {
    int pos = nums.size()-1;
    int i = nums.size()-2;
    
    if(check(nums, pos, i)){
        return true;
    }
    return false;
}
