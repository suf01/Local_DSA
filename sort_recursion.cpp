#include<bits/stdc++.h>
using namespace std;

void insert_ele(vector<int> &v, int temp){
    int m = v.size();
    if(m == 0 || v[m-1] <= temp){
        v.push_back(temp);
        return;
    }

    int temp2 = v[m-1];
    v.pop_back();
    
    insert_ele(v, temp);

    v.push_back(temp2);
}

void R_sort(vector<int> &v){
    int n = v.size();
    if(n == 0){
        return;
    }

    int temp = v[n-1];
    v.pop_back();
    R_sort(v);
    insert_ele(v, temp);
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    R_sort(v);

    for(auto it: v){
        cout<<it<<" ";
    }
}

#include<bits/stdc++.h>
using namespace std;

void insert_in_stack(stack<int> &st, int temp){
    int m = st.size();
    int temp2 = st.top();
    if(m == 1 || temp > temp2){
        st.push(temp);
        return;
    }

    st.pop();
    insert_in_stack(st, temp);

    st.push(temp2);
}

void stack_sort(stack<int> &st){
    int n = st.size();

    if(n == 1){
        return;
    }

    int temp = st.top();
    st.pop();
    stack_sort(st);

    insert_in_stack(st, temp);
}

void print_stack(stack<int> st){
    if(st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();
    print_stack(st);
    cout<<temp<<" ";
    st.push(temp);
}

int main(){

    stack<int> st;

    st.push(8);
    st.push(7);
    st.push(83);
    st.push(6);
    st.push(72);

    stack_sort(st);

    print_stack(st);
}