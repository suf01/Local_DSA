#include<bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target){
    //let target = sum of all +ve values + sum of all -ve values;
    // s1 + s2 = total sum
    // s1(sum of all +ve) - s2(sum of all -ve) = target
    // adding the above equations
    // 2*s1 = totalsum + target
    // s1 = (totalsum + target)/2
    // we just need to find how many subsets with sum s1 is possible

    int sum = 0;
    int n = nums.size();
        
    for(int i = 0; i < n; i++){
        sum += nums[i];
    }
        
    if(sum < target){
        return 0;
    }
        
    if(target < (-sum)){
        return 0;
    }
        
    if((target+sum)%2 != 0){
        return 0;
    }
        
    int s1 = (sum+target)/2;
        
    int dp[n+1][s1+1];
        
    dp[0][0] = 1;
        
    for(int j = 1; j < s1+1; j++){
        dp[0][j] = 0; 
    }
        
        
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < s1+1; j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
        
    return dp[n][s1];
}
