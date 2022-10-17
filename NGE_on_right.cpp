#include<bits/stdc++.h>
using namespace std;

vector<int> findLeastGreater(vector<int>& arr, int n) {
    set<int> s;
    vector<int> ans;
        
    for(int i = arr.size()-1; i >= 0; i--){
        s.insert(arr[i]);
        auto it = s.upper_bound(arr[i]);
        if(it == s.end()){
            ans.push_back(-1);
        }else{
            ans.push_back(*it);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
