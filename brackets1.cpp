#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int>  m = { {'(', -1}, {'[', -2}, {'{', -3}, {')', 1}, {']', 2}, {'}', 3} };
string isBalanced(string expr){
    stack<char> st;
    for(char it : expr){
        if(m[it] < 0){
            st.push(it);
        }
        else{
            if(st.empty()) return "NO";
            char top = st.top();
            st.pop();
            if(m[it] + m[top] != 0) return "NO";
            return "YES";
        }
    }
    if(st.empty()) return "YES";
    return "NO";
}

int main(){
    string s =  "{{[[(())]]}}";
    cout<<isBalanced(s);

}