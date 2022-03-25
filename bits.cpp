#include<bits/stdc++.h>
using namespace std;
void printbin(int num){
    //print bin
    for(int i = 10; i >= 0; i--){
        cout<<((num>>i) & 1);
    }
    cout<<endl;
}

int main(){
    int a = 5;
    printbin(a);

    // check set bit
    int i = 2;
    if(a & 1<<i){
        cout<<"set"<<endl;
    }else{
        cout<<"not set"<<endl;
    }
    //set bit
    printbin( a | (1<<i) );
    //unset bit
    printbin( a & ~(1<<i));
    //toggle bit 
    printbin( a ^ (1<<i));

    //no of set bits
    int b = 5;
    int ct = 0;
    for(int i = 31; i >= 0; i--){
        if((b & (1<<i)) != 0){
            ct++;
        }
    }
    cout<<ct<<endl;

    cout<< __builtin_popcount(5)<<endl;
    cout<< __builtin_popcountll(1LL<<32)<<endl;

    //oddd or even
    int c = 4;
    if(c & 1){
        cout<<"odd"<<endl;
    }else{
        cout<<"even"<<endl;
    }

    //multi n divide by 2
    int d = 6;
    int mult = d<<2;
    int div = d>>2;

    //up to low

    char H = 'H';
    char h = H | (1<<5);
    cout<<h<<endl;
    cout<< char(h & ~(1<<5))<<endl;

    cout<< char( 'C' | ' ')<<endl;
    cout<< char( 'c' & '_')<<endl;

    // clearing lsb bits till ith position
    int n = 34;
    printbin(n);
    i = 4;
    int m = n & (~((1<<(i+1))-1));
    printbin(m);
    //clearing msb bits till ith position
    n = 43;
    printbin(n);
    i = 2;
    m = n & ((1<<(i+1))-1);
    printbin(m);

    //power of 2
    n = 3;
    if( n & (n-1)){
        cout<<"not pow of 2"<<endl;
    }
    else{
        cout<<"pow of 2"<<endl;
    }

    // x ^ x = 0
    // x ^ 0 = x

    //swaping two numbers
    a = 2;
    b = 4;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout<<a<<" "<<b<<endl;

    //even count expect 1 in O(1)

    int N;
    cin>>N;
    int ans = 0;
    for(int i = 0; i < N; i++){
        int x;
        cin>>x;
        ans ^= x;
    }
    cout<<ans;


}