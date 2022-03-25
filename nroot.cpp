#include<bits/stdc++.h>
using namespace std;

double eps = 1e-7;

double timesn(double mid, int n){
    double res = 1;
    for(int i = 0; i < n; i++){
        res *=mid;
    }
    return res;
}
int main(){
    double x;
    cin>>x;

    int n;
    cin>>n;

    double lo = 1, hi = x;
    double mid;

    while((hi-lo) > eps){
        
        mid = (lo+hi)/2;

        if((timesn(mid, n)) < x){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    cout<<setprecision(10)<<lo<<"\n"<<hi;
}