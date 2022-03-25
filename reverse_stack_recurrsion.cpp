#include<bits/stdc++.h>
using namespace std;

void print_stack(stack<int> &st){
    int n = st.size();

    if(n == 0){
        return;
    }

    int temp = st.top();
    cout<<temp<<" ";
    st.pop();

    print_stack(st);
    st.push(temp);
}

void delete_middle(stack<int> &st){
    int n = st.size();
    int k = (n/2)+1;

    if(n == k){
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    delete_middle(st);
    st.push(temp);
}

void insert_bottom(stack<int> &st, int ele){
    int n = st.size();

    if(n == 0){
        st.push(ele);
        return;
    }

    int temp = st.top();
    st.pop();
    insert_bottom(st, ele);
    st.push(temp);
}

void reverse_stack(stack<int> &st){
    int n = st.size();

    if(n == 1){
        return;
    }

    int temp = st.top();
    st.pop();
    reverse_stack(st);

    insert_bottom(st, temp);
}

int main(){
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(5);
    st.push(8);

    print_stack(st);
    cout<<endl;
    cout<<st.size()<<endl;
    reverse_stack(st);

    print_stack(st);
    
}