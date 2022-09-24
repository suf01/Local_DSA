#include<bits/stdc++.h>
using namespace std;

//read interviewbit problem

int divide(int A, int B) {
    //A, B > 0 given

    long long sign = 1;
    
    if(A < 0 && B < 0){
        sign = 1;
    }else if(A < 0 || B < 0){
        sign = -1;
    }
    
    long long quotient = 0;
    long long rem = 0;
    long long dividend = abs(A*1ll);
    long long divisor = abs(B*1ll);
    
    for(int i = 31; i >= 0; i--){
        if( (divisor*(1ll<<i)) <= (dividend*1ll) ){
            long long temp = (divisor*(1ll<<i));
            rem = dividend-temp;
            dividend = rem;
            quotient += (1ll<<i);
        }
    }
    
    if(sign == 1 && quotient > INT_MAX) return INT_MAX;
    return quotient*sign;
}

int main(){
    int p = 43;
    int q = 8;
    
    cout<<p/q<<endl;

    /* repeated substraction

       43 - 8 = 35  cnt = 1
       35 - 8 = 27  cnt = 2
       27 - 8 = 19  cnt = 3
       19 - 8 = 11  cnt = 4
       11 - 8 = 3   cnt = 5   stop here since 3 < 8

       no of steps i.e 5 is the answer, t.c O(dividend)

    */

    /* 43 - (x)*8
       where x is the highest number and can be represented by power of 2 and (x*8 < 43)
       here 2^2 cnt = 4;

       p = 11 > 8
       11 = x*8
       2^0 cnt = 1

       p = 3 < 8
       stop
    */ 

    /*
      similarly p = 43 q = 8

      8 < 43
      8+8 = 16 < 43
      8+8+8 = 24 < 43
      8+8+8+8 = 32 < 43
      8+8+8+8+8 = 40 < 43
      8+8+8+8+8+8 = 48 > 43 stop

      cnt = 5
    */
}
