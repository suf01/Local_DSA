#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;
    int min = * min_element(v.begin(), v.end());
    int max = * max_element(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0);
    int ct = count(v.begin(), v.end(), 2);
    int it = * find(v.begin(), v.end(), 3);
    reverse(v.begin(), v.end());
    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;

    auto fun = [](int x, int y){ return x+y; };
    cout<<fun(1, 2)<<endl;

    cout<<[](int x, int y){ return x+y; }(1, 2);

    cout<< all_of(v.begin(), v.end(), [](int x){return x > 0;});
    cout<< any_of(v.begin(), v.end(), [](int x){return x > 0;});
    cout<< none_of(v.begin(), v.end(), [](int x){return x > 0;});

}