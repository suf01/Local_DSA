#include<bits/stdc++.h>
using namespace std;

int main(){
    //converting string to char using c_str()

    string s1 = "23112";
    int n1 = s1.length(); 
    char c1[n1]; // can be c1[n1+1]
    strcpy(c1, s1.c_str());

    //not i <= n1
    for(int i = 0; i < n1; i++){
        cout<<c1[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i < n1; i++){
        int val = c1[i]-'0';
        cout<<val<<" ";
    }
    cout<<endl;

    //method 2

    string s2 = "2345424";
    int n2 = s2.length();

    char c2[n2];

    for(int i = 0; i < n2; i++){
        c2[i] = s2[i];
    }

    for(int i = 0; i < n2; i++){
        cout<<c2[i]<<" ";
    }
    cout<<endl;

    for(int i = 0; i < n2; i++){
        int val = c2[i]-'0';
        cout<<val<<" ";
    }
    cout<<endl;

    //method 3

    char *char_arr;
    string s3 = "dfodoif";

    char_arr = &s3[0];

    cout<<char_arr<<endl;


    //number to string

    int x = 434;

    string b = to_string(x);
    cout<<b<<endl;

    //string to int method 1

    string s5 = "543";
    int y = stoi(s5);
    cout<<y<<endl;

    //string to int method 2

    string s6 = "434";

    stringstream ss(s6);
    int data;

    ss>>data;

    cout<<data;
}