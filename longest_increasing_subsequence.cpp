int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    //stores length of longest subsequence ith index ending with ith num
    vector<int> dp(n, 0);

    dp[0] = 1;
    int ans = 1;

    for(int i = 1; i < n; i++){
        int maxi = 0;
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                maxi = max(maxi, dp[j]);
            }
        }
        dp[i] = maxi+1;
        ans = max(ans, dp[i]);
    }
        
    return ans;
}
