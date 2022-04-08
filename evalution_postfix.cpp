#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(auto it: tokens){
        if(it == "/" || it == "*" || it == "+" || it == "-" || it == "^"){
            auto op2 = st.top();
            st.pop();
            auto op1 = st.top();
            st.pop();
                
            if(it == "/"){
                st.push(op1/op2);
            }else if(it == "*"){
                st.push(op1*op2);
            }else if(it == "+"){
                st.push(op1+op2);
            }else if(it == "-"){
                st.push(op1-op2);
            }else if(it == "^"){
                st.push(op1^op2);
            }
        }else{
            int data;
            stringstream ss(it);
            ss>>data;
            st.push(data);
        }
    }
        
    int ans = st.top();
    return ans;
}


int main(){
    vector<string> v = {"2", "1", "+", "3", "*"};
    cout<<evalRPN(v);
}