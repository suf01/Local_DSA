#include<bits/stdc++.h>
using namespace std;

//**************************************
/*
bool comp(int a, int b){
	if(a > b){
		return true;
	}
	return false;
}
*/

bool comp(int a, int b){
	return a > b;
	// a > b for descending
	// a < b for ascending 
}

int main(){
	vector<int> v = {4, 5, 2, 3, 1};
	sort(v.begin(), v.end(), comp);
	for(auto it: v){
		cout<<it<<" ";
	}
	cout<<endl;

}
//********************************************

//use static
static bool comp(pair<int, string> a, pair<int, string> b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main(){
	vector<pair<int, string> > v;
	v.push_back({1, "fefs"});
	v.push_back({1, "abc"});

	sort(v.begin(), v.end(), comp);

	for(auto it: v){
		cout<<it.first<<" "<<it.second<<endl;
	}
}
//**********************************************************

class student{
public:
	int marks;
	int roll;

    student(int r, int m){
		roll = r;
		marks = m;
	}
};

bool comp(student a, student b){
	if(a.marks == b.marks){
		return a.roll < b.roll;
	}else{
		return a.marks > b.marks;
	}
}

int main(){
	student s1(1, 99);
	student s2(2, 99);

	vector<student> v;
	v.push_back(s1);
	v.push_back(s2);

	sort(v.begin(), v.end(), comp);
	for(auto it: v){
		cout<<it.marks<<" "<<it.roll<<endl;
	}
}
//********************************************

class comp{
public:
	bool operator ()(const int &a, const int &b){
		return a > b;
	}
};

int main(){
	//set<dtype, classname/typename>
	set<int, comp> s;
	s.insert(4);
	s.insert(3);
	s.insert(1);

	for(auto it: s){
		cout<<it<<" ";
	}
}
//********************************************
