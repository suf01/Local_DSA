#include<bits/stdc++.h>
using namespace std;

double neg_pow(double x, int n){
    if(n == -1){
        return 1/x;
    }

    double temp = neg_pow(x, n/2);

    if(n%2 == 0){
        return temp*temp;
    }else{
        return (1/x)*temp*temp;
    }
}
double pos_pow(double x, int n){
    if(n == 0){
        return 1;
    }
    double temp = pos_pow(x, n/2);

    if(n%2 == 0){
        return temp*temp;
    }else{
        return x*temp*temp;
    }
}
double myPow(double x, int n) {
    if(n < 0){
        return neg_pow(x, n);
    }else{
        return pos_pow(x, n);
    }
}
