#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int> > ans;
        
    if(n < 4){
        return ans;
    }

    int j, k, l;
    
    for(int i = 0; i <= n-4; i++){
        for(int j = i+1; j <= n-3; j++){
            int k = j+1;
            int l = n-1;
            long long temp = nums[i]+nums[j];
            long long req = target-temp;
                
            while(k < l){
                long long temp2 = nums[k]+nums[l];
                
                if(req == temp2){
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        
                    while(k < l && nums[k] == nums[k+1]){
                        k++;
                    }
                    while(k < l && nums[l] == nums[l-1]){
                        l--;
                    }
                    
                    k++;
                    l--;
                }else if(temp2 > req){
                    l--;
                }else{
                    k++;
                }
            }
                
            while(j <= n-3 && nums[j] == nums[j+1]){
                j++;
            }
        }
            
        while(i <= n-4 && nums[i] == nums[i+1]){
            i++;
        }
    }
    return ans;
}
