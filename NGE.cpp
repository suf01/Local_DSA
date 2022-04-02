#include<bits/stdc++.h>
using namespace std;

void NGE(vector<int> &v){
    int n = v.size();

    stack<int> st;
    unordered_map<int, int> mpp;

    for(int i = 0; i < n; i++){
        while(!st.empty() && st.top() <= v[i]){
            mpp[st.top()] = v[i];
            st.pop();
        }
        st.push(v[i]);
    }

    while(!st.empty()){
        mpp[st.top()] = -1;
        st.pop();
    }

    for(auto it: mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    NGE(v);
}