#include<bits/stdc++.h>
using namespace std;

bool can_place(vector<int> &stalls, int k, int dis){
    int n = stalls.size();
    
    int prev = stalls[0];
    k--;
        
    for(int i = 1; i < n; i++){
        if(stalls[i]-prev >= dis){
            prev = stalls[i];
            k--;
        }
        if(k == 0){
            return true;
        }
    }
    return false;
}

int solve(int n, int k, vector<int> &stalls){
    
    sort(stalls.begin(), stalls.end());
        
    int lo = 1;
    int hi = stalls[n-1]-stalls[0];
        
    int ans = 0;
    while(lo <= hi){
        int mid = lo+(hi-lo)/2;
            
        if(can_place(stalls, k, mid)){
            ans = mid;
            lo = mid+1;
            continue;
        }else{
            hi = mid-1;
        }
    } 
    return ans;
}
