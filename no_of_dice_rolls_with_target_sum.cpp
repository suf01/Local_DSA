#include<bits/stdc++.h>
using namespace std;

// recursion + memoziation
int M = 1e9+7;
long long find_ways(long long n, long long k, long long target, vector<vector<long long> > &dp){
    if(target < 0 || n < 0){
        return 0;
    }
        
    if(n == 0 && target != 0){
        return 0;
    }
    
    if(target == 0 && n != 0){
        return 0;
    }
    
    if(n == 0 && target == 0){
        return 1;
    }
        
    if(dp[n][target] != -1){
        return dp[n][target];
    }
    
    long long ans = 0;
    for(int i = 1; i <= k; i++){
        ans = ans + find_ways(n-1, k, target-i, dp);
        ans = ans%M;
    }
    return dp[n][target] = ans;
}

int numRollsToTarget(int n, int k, int target){
    vector<vector<long long> > dp(n+1, vector<long long>(target+1, -1));
    return find_ways(n, k, target, dp);
}

// top down
int numRollsToTarget(int n, int k, int target) {
    int M = 1e9+7;

    vector<vector<long long> > dp(n+1, vector<long long> (target+1, 0));
        
    dp[0][0] = 1;
        
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= target; j++){
            long long temp = 0;
            for(int p = 1; p <= k; p++){
                if(p > j){
                    break;
                }
                temp += dp[i-1][j-p];
            }
            dp[i][j] = temp%M;
        }
    }
    return dp[n][target];
}
