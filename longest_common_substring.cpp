#include<bits/stdc++.h>
using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
        
    if(n < 1 || m < 1){
        return 0;
    }
        
    int dp[n+1][m+1];
        
    dp[0][0] = 0;
        
    for(int i = 0; i < n+1; i++){
        dp[i][0] = 0;
    }
        
    for(int j = 0; j < m+1; j++){
        dp[0][j] = 0;
    }
        
    int maxi = 0;
        
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(nums1[i-1] == nums2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                if(dp[i][j] > maxi){
                    maxi = dp[i][j];
                }
            }else{
                dp[i][j] = 0;
            }
        }
    }
        
    return maxi;
}

int main(){

}
