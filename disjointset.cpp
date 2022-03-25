#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int rank[100000];

void makeSet(){
	for(int i = 1; i <=n; i++){
		parent[i] = i;
		rank[i] = 0;
	}
}

int findParent(int node){
	if(node == parent[node]){
		return node;
	}

	//path compression
	return parent[node] = findParent(parent[node]);
}

void union(int u, int v){
	u = findParent(u);
	v = findParent(v);

	if(rank[u] == rank[v]){
		parent[v] = u;
		rank[u]++;
	}else if(rank[u] < rank[v]){
		parent[u] = v;
	}else if(rank[v] < rank[u]){
		parent[v] = u;
	}
}

int main(){

	if(findParent(2) == findParent(1)){
		cout<<"same component";
	}else{
		cout<<"different component";
	}
}