#include<bits/stdc++.h>
using namespace std;

string isBalanced(string expr){
    stack<char> st;
    char top;
    for(int i = 0; i < expr.length(); i++){
        if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{'){
            st.push(expr[i]);
        }
            if(st.empty()) return "NO";
            top = st.top();

            switch(expr[i]){
                case ')' :
                if(top == '[' || top == '{') return "NO";
                st.pop();
                break;

                case ']' :
                if(top == '(' || top == '{') return "NO";
                st.pop();
                break;

                case '}' :
                if(top == '(' || top == '[') return "NO";
                st.pop();
                break;
            }
        
    }

    if(st.empty()) return "YES";
    return "NO";
}

int main(){
    string s =  "{{[[(())]]}}";
    cout<<isBalanced(s);

}