#include<bits/stdc++.h>
using namespace std;

int main(){
	//1d array
	int* array = new int[50];

	//2d array
	int** arr2d = new int*[50];

	for(int i = 0; i < 50; i++){
		arr2d[i] = new int[50];
	}

	//deleting 2d array
	for(int i = 0; i < 50; i++){
		delete[] arr2d[i];
	}
	delete[] arr2d;
	
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;

	vector<vector<int> > v(n, vector<int> (m));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>v[i][j];
		}
	}

	/*
	vector<vector<int>> vect
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }   
        cout << endl;
    }

    for (vector<int> vect1D : vect)
    {
        for (int x : vect1D)
        {
            cout << x << " ";
        }   
        cout << endl;
    }

    for(int i = 0; i < n; i++){
		for(auto it : v[i]){
			cout<<it<<" ";
		}
	}

    */

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<v[i][j]<<" ";
		}
	}
}