#include<bits/stdc++.h>
using namespace std;

void find_combinations(vector<int> &v, int i, int k, vector<int> temp, vector<vector<int> > &ans){
    if(temp.size() == k){
        ans.push_back(temp);
        return;
    }

    if(i == v.size()){
        return;
    }

    for(int j = i; j < v.size(); j++){
        temp.push_back(v[j]);
        find_combinations(v, j+1, k, temp, ans);
        temp.pop_back();
    }
}
    
vector<vector<int>> combine(int n, int k) {
    vector<vector<int> > ans;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = i+1;
    }

    vector<int> temp;
    find_combinations(v, 0, k, temp, ans);
    return ans;
}
