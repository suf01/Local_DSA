#include<bits/stdc++.h>
using namespace std;

string getPhoneNumber(string s) {
    string curr;
    
    int n = s.length();
    
    int i = 0;
    
    string ans;
    int cnt = 1;
    cout<<"in function"<<endl;
    
    for(int i = 0; i < n; i++){
        while(s[i] != ' ' && s[i] != '\0'){
            curr+=s[i];
            i++;
        }
        cout<<curr<<endl;
        if(curr == "one"){
            while(cnt >= 1){
            ans.push_back('1');
            cnt--;
            }
            curr = "";
            cnt = 1;
        }else if(curr == "two"){
            while(cnt>=1){
            ans.push_back('2');
            cnt--;
            }
            curr = "";
            cnt = 1;
        }else if(curr == "three"){
            while(cnt>=1){
            ans.push_back('3');
            cnt--;
            }
            curr = "";
            cnt = 1;
        }else if(curr == "four"){
            while(cnt >= 1){
            ans.push_back('4');
            cnt--;
            }
            curr = "";
            cnt = 1;
        }else if(curr == "five"){
            while(cnt >= 1){
            ans.push_back('5');
            cnt--;
            }
            curr = "";
            cnt = 1;
        }else if(curr == "six"){
            while(cnt >= 1){
            ans.push_back('6');
            cnt--;
            }
            curr = "";
            cnt = 1;
        }else if(curr == "seven"){
            while(cnt >= 1){
            ans.push_back('7');
            cnt--;
            }
            curr = "";
            cnt = 1;
        }else if(curr == "eight"){
            while(cnt >= 1){
            ans.push_back('8');
            cnt--;
            }
            curr = "";
            cnt = 1;
        }else if(curr == "nine"){
            while(cnt >= 1){
            ans.push_back('9');
            cnt--;
            }
            curr = "";
            cnt = 1;
        }else if(curr == "zero"){
            while(cnt >= 1){
            ans.push_back('0');
            cnt--;
            }
            curr = "";
            cnt = 1;
        }else if(curr == "double"){
            curr = "";
            int temp = 1;
            while(temp !=0){
            cnt++;
            temp--;
            }
        }else if(curr == "triple"){
            curr = "";
            int temp = 2;
            while(temp != 0){
            cnt++;
            temp--;
            }
        }
        
        cout<<ans<<endl;
    }
    return ans;
}

string print_string(string s){
    int i = 0;
    int n = s.length();

    cout<<n<<endl;

    string ans;

    for(int i = 0; i < n; i++){
        while(s[i] != ' ' && s[i] != '\0'){
            ans+=s[i];
            i++;
        }
        ans+=" ";
    }
    return ans;
}

int main(){
    string s = "eight one two three six three four five seven three";

    cout<<getPhoneNumber(s);
}