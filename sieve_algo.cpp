#include<bits/stdc++.h>
using namespace std;

/*to check if a number is number we need to check if there exists a number
  that is less then sqrt(n) that divides n, because factor n let p and q
  be the factors then p & q cannot be > sqrt(n).
*/

vector<int> prime(100, 1);
//O(nlogn) generally checking for 2, also 4, also 6, also 8 etc.
//O(nlog(logn)) checking only for primes.
int main(){
	prime[0] = 0;
	prime[1] = 0;

	for(int i = 2; i <= 100; i++){
		if(prime[i] == 1){
			for(int j = 2*i; j <= 100; j = j+i){
				prime[j] = 0;
			}
		}
	}
	
	for(int i = 1; i <= 100; i++){
		cout<<i<<" "<<prime[i]<<endl;
	}	
}
