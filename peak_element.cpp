#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    int lo = 0;
    int hi = n-1;

    if(n == 1){
        return 0;
    }

    while(lo <= hi){
        int mid = lo+(hi-lo)/2;

        if(mid > 0 && mid < n-1){
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }

            if(nums[mid-1] > nums[mid]){
                hi = mid-1;
                continue;
            }else if(nums[mid+1] > nums[mid]){
                lo = mid+1;
                continue;
            }
        }else if(mid == 0){
            if(nums[mid] > nums[mid+1]){
                return mid;
            }else{
                 return mid+1;
            }
        }else if(mid == n-1){
            if(nums[mid] > nums[mid-1]){
                return mid;
            }else{
                return mid-1;
            }
        }
    }
    return -1;
}
