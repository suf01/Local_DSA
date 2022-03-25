#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > possible_arr;

void generate(vector<int> &subset, int i, vector<int> &v){
    if(i == v.size()){
        possible_arr.push_back(subset);
        return;
    }

    //dont include element
    generate(subset, i+1, v);

    //include element
    subset.push_back(v[i]);
    generate(subset, i+1, v);
    subset.pop_back();
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    vector<int> empty;

    generate(empty, 0, v);

    for(auto subset : possible_arr){
        for(auto ele : subset){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}
/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            for(int k = i; k <= j; k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > sub(vector<int> &v){
    int n = v.size();
    vector<vector<int> > subsets;
    int sub_ct = (1<<n);

    for(int mask = 0; mask < sub_ct; mask++){
        vector<int> subset;
        for(int i = 0; i < n; i++){
            if((mask & (1<<i)) != 0){
                subset.push_back(v[i]);
            }
        }
        subsets.push_back(subset);
    }
    return(subsets);
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    auto subbs = sub(v);

    for(auto subset : subbs){
        for(int ele : subset){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

}