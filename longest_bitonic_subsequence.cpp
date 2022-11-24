#include<bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(vector<int>nums){
        
    int n = nums.size();
        
    vector<int> increasing(n, 1);
    vector<int> decreasing(n, 1);
        
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                increasing[i] = max(increasing[i], increasing[j]+1);
            }
        }
    }
    
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(nums[j] < nums[i]){
                decreasing[i] = max(decreasing[i], decreasing[j]+1);
            }
        }
    }
        
    int ans = INT_MIN;
        
    for(int i = 0; i < n; i++){
        ans = max(ans, increasing[i]+decreasing[i]-1);
    }
    return ans;
}
