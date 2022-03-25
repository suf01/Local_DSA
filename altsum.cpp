#include <bits/stdc++.h>
using namespace std;

void altsum(int *mat, int n){
	int sum1, sum2;
	sum1 = sum2 = 0;

	for(int i = 0; i < n*n; i++){
		if(i%2 == 0){
			sum1 = sum1 + mat[i];
		}
		else{
			sum2 = sum2 + mat[i];
		}
	}

	cout<<sum1<<" "<<sum2;
}
int main(){
	int mat[3][3] = { { 1, 2, 3 },
                      { 4, 5, 6 },
                      { 7, 8, 9 } };
    int n = 3;

    altsum(&mat[0][0], n);
}