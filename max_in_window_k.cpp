#include<bits/stdc++.h>
using namespace std;

vector <int> max_of_subarrays(int *arr, int n, int k){
    vector<int> ans;
    int i = 0;
    int j = 0;
        
    deque<int> q;
    while(j < n){
        while(!q.empty() && q.back() < arr[j]){
            q.pop_back();
        }
        q.push_back(arr[j]);
            
        if(j-i+1 < k){
            j++;
        }else{
            ans.push_back(q.front());
            if(q.front() == arr[i]){
                q.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}
