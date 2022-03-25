#include<bits/stdc++.h>
using namespace std;

/* inline function saves overhead time, no control transfer,
   linear execution of program and stack pointer */

inline int addition(int a, int b){
    return a+b;
}

int main(){
    cout<<addition(3,4);
}