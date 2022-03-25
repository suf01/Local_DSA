#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        cout<<v[i]<<" "; 
    }
    cout<<endl;

    auto it = upper_bound(v.begin(), v.end(), 8);
    //auto it = s.lower_bound(rand());

    if(it == v.end()){
        cout<<"Not found";
        return 0;
    }
    cout<<(*it)<<" ";
}

/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a+n);

    for(int i = 0; i < n; i++){
        cout<<a[i]<<" "; 
    }
    cout<<endl;

    int *ptr = upper_bound(a, a+n, 7);

    if(ptr == a+n){
        cout<<"Not found";
        return 0;
    }
    cout<<(*ptr)<<" ";
}
*/