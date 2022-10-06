#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int> > ans;

    for(int i = 0; i < n-1; i++){
        int req_sum = -nums[i];

        int j = i+1;
        int k = n-1;

        while(j < k){
            if(nums[j]+nums[k] == req_sum){
                ans.push_back({nums[i], nums[j], nums[k]});
                    
                while(j < k && nums[j] == nums[j+1]){
                    j++;
                }
                while(j < k && nums[k] == nums[k-1]){
                    k--;
                }
                j++;
                k--;
            }else if(nums[j]+nums[k] < req_sum){
                j++;
            }else{
                k--;
            }
        }
            
        while(i < n-1 &&nums[i] == nums[i+1]){
            i++;
        }
    }
    return ans;
}
