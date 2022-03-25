#include<bits/stdc++.h>
using namespace std;

void primsbf(int V, vector<pair<int, int> > adjL[]){
	vector<int> key(V, INT_MAX);
	vector<int> parent(V, -1);
	vector<bool> mstset(V, false);

	key[0] = 0;
	parent[0] = -1;

	for(int i = 0; i < V-1; i++){
		int mini = INT_MAX;
		int u;

		for(int v = 0; v < V; v++){
			if(mstset[v] == false && key[v] < mini){
				mini = key[v];
				u = v;
			}

			mstset[u] = true;

			for(auto ele : adjL[u]){
				int v = ele.first;
				int weight = ele.second;

				if(mstset[v] == false && weight < key[v]){
					key[v] = weight;
					parent[v] = u;
				}
			}
		}
	}

	for(int i = 1; i < V; i++){
		cout<<parent[i]<<" - "<<i<<" ";
	}
}

void primsop(int V, vector<pair<int, int> > adjL[]){
	vector<int> key(V, INT_MAX);
	vector<int> parent(V, -1);
	vector<bool> mstset(V, false);

	key[0] = 0;
	parent[0] = -1;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
	q.push({key[0], 0});

	for(int i = 0; i < V-1; i++){
		int u = q.top().second;
		q.pop();

		for(auto ele : adjL[u]){
			int v = ele.first;
			int weight = ele.second;

			if(mstset[v] == false && weight < key[v]){
				key[v] = weight;
				parent[v] = u;

				q.push({key[v], v});
			}
		}

	}

	for(int i = 1 ; i < V; i++){
		cout<<parent[i]<<" - "<<i<<" ";
	}
}

int main(){
	int V, E;
	cin>>V>>E;

	vector<pair<int, int> > adjL[V];

	for(int i = 0; i < E; i++){
		int a, b, wt;
		cin>>a>>b>>wt;
		adjL[a].push_back({b, wt});
		adjL[b].push_back({a, wt});
	}

	for(int i = 0; i < V; i++){
		cout<<i<<"-->";
		for(auto ele : adjL[i]){
			cout<<"("<<ele.first<<", "<<ele.second<<")";
		}
		cout<<endl;
	}

	primsop(V, adjL);
}