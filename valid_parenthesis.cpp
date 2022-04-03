#include<bits/stdc++.h>
using namespace std;

 bool isValid(string s) {
    stack<char> st;
        
    for(auto it: s){
        if(st.empty()){
            st.push(it);
        }else{
            char tp = st.top();
            if(tp == '(' && it == ')' || tp == '[' && it == ']' || tp == '{' && it == '}'){
                st.pop();
            }else{
                st.push(it);
            }
        }
    }
        
    if(st.empty()){
        return true;
    }else{
        return false;
    }
}

int main(){
    string s = "{()]}";
    cout<<isValid(s);
}