#include<bits/stdc++.h>
using namespace std;

maxprofit(vector<int> v){
    int n = v.size();

    int max = 0;
    int min = INT_MAX;
    int diff;

    for(int i = 0; i < n; i++){
        if(v[i] < min){
            min = v[i];
        }

        diff = v[i] - min;

        if(diff > max){
            max = diff;
        }
    }
    return max;
}

multimaxprofit(vector<int> v){
    int n = v.size();
    int max = 0;

    for(int i = 1; i < n; i++){
        if(v[i] > v[i-1]){
            max += v[i]-v[i-1];
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

    cout<<multimaxprofit(v);
}