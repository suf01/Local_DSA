#include<bits/stdc++.h>
using namespace std;

bool camp(pair<int, int> a, pair<int, int> b){
    return a < b;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int, int> > v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(), v.end(), camp);

    for(auto &it : v){
        cout<<it.first<<" "<<it.second<<endl;
    }
}