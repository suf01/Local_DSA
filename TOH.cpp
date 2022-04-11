#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

long long TOH(int N, int from, int to, int aux){
    cnt++;
    if(N == 1){
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        return cnt;
    }

    TOH(N-1, from, aux, to);
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    TOH(N-1, aux, to, from);
    return cnt;
}

int main(){
    int from = 1;
    int to = 3;
    int aux = 2;

    int N = 2;

    int n = TOH(N, from, to, aux);
    cout<<n;
}