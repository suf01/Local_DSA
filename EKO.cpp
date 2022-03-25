#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int tree[N];

int n;
long long m;

bool totalwood(int h){
    long long wood = 0;
    for(int i = 0; i < n; i++){
        if(tree[i] >= h){
            wood += (tree[i]-h);
        }
    }
    return wood >= m;
}

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>tree[i];
    }

    long long lo = 0, hi = 1e9, mid;

    // T T T T F F F F F F first true then false

    while((hi-lo) > 1){
        mid=(lo+hi)/2;
        if(totalwood(mid)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }
    if(totalwood(hi)){
        cout<<hi<<endl;
    }else{
        cout<<lo<<endl;
    }
    
}