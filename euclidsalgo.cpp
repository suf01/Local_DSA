
// (18, 12)
// ( a, b )
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    /*
    if(a%b == 0) return b;
    return gcd(b, a%b);
    */

    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    cout<<gcd(12, 4)<<endl;
    cout<<gcd(18, 12)<<endl;
    cout<<"LCM : "<< (18 * 12) / gcd(18, 12)<<endl;
    cout<<__gcd(18, 12);
    // min fraction of a/b = (a/gcd(a, b)) / (b/gcd(a, b))

}