#include<bits/stdc++.h>
using namespace std;

//make calculations in long long

//floor value of square root

int find_root_floor(int n){
    int lo = 1;
    int hi = n;

    int temp;
    while(lo <= hi){
        int mid = (lo+hi)/2;

        if(mid*mid == n){
            return mid;
        }

        if(mid*mid > n){
            hi = mid-1;
        }else{
            temp = lo;
            lo = mid+1;
        }
    }
    return temp;
}


//square root of a number
double square_root(int n){
    double lo = 1;
    double hi = n;

    //number of decimal places upto require accuracy
    double esp = 1e-6;

    while(hi-lo > esp){
        double mid = lo+(hi-lo)/2;

        if(mid*mid > n){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    //both lo and hi gives the answer
    return lo;
}

//nth root of a number

double find_val(int n, double mid){
    double ans = 1;
    for(int i = 0; i < n; i++){
        ans = ans*mid;
    }
    return ans;
}

double find_root(double n, double m){
    double lo = 1;
    double hi = m;

    double esp = 1e-6;

    while(hi-lo > esp){
        double mid = lo+(hi-lo)/2;

        double temp = find_val(n, mid);

        if(temp > m){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    return hi;
}

int main(){
    int n = 2;

    cout<<square_root(n)<<endl;
    cout<<setprecision(10)<<pow(2, 1.0/2)<<endl;
    cout<<find_root(2.0, 2.0)<<endl;
    cout<<find_root_floor(5)<<endl;
}
