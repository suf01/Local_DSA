#include<bits/stdc++.h>
using namespace std;

//523 if subarray exist with two or more elements
bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int, int> mpp;
    mpp[0] = -1;

    long long sum = 0;
    long long rem = 0;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        rem = sum%k;

        if(mpp.find(rem) == mpp.end()){
            mpp[rem] = i;
        }else{
            if(i-mpp[rem] > 1){
                return true;
            }
        }
    }
    return false;   
}

//974 count of subarrays
int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mpp;
    mpp[0] = 1;

    int sum = 0;
    int rem = 0;
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        sum += nums[i];
        rem = sum%k;

        if(rem < 0){
            rem += k;
        }

        if(mpp.find(rem) == mpp.end()){
            mpp[rem]++;
        }else{
            ans += mpp[rem];
            mpp[rem]++;
        }
    }
    return ans;
}

