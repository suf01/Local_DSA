#include<bits/stdc++.h>
using namespace std;

maxsum(vector<int> v){
    int n = v.size();

    int cur = 0;
    int max = 0;

    for(int i = 0; i < n; i++){
        cur += v[i];

        if(cur > max){
            max = cur;
        }
        if(cur < 0){
            cur = 0;
        }
    }
    return max;
}


int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    cout<<maxsum(v);
}