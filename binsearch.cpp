#include<bits/stdc++.h>
using namespace std;

int LB(vector<int> &v, int ele){
    int lo = 0, hi = v.size() - 1;
    int mid;

    while(hi-lo > 1){
        
        mid = (hi+lo)/2;
        
        if(v[mid] < ele){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    
    if(v[lo] >= ele){
        return lo;
    }
    
    if(v[hi] >= ele){
        return hi;
    }

    return -1;

}

int UB(vector<int> &v, int ele){
    int lo = 0, hi = v.size() - 1;
    int mid;

    while(hi-lo > 1){
        
        mid = (hi+lo)/2;
        
        if(v[mid] <= ele){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    
    if(v[lo] > ele){
        return lo;
    }
    
    if(v[hi] > ele){
        return hi;
    }

    return -1;

}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    int find;
    cin>>find;

    int lb = LB(v, find);
    int ub = UB(v, find);
    cout<<lb<<" "<<( lb == -1 ? -1 : v[lb])<<endl;
    cout<<ub<<" "<<( ub == -1 ? -1 : v[ub])<<endl;

}