#include<bits/stdc++.h>
using namespace std;

void finddfs(int node, vector<int> &visited, vector<int> adjL[], vector<int> &dfs){
	if(!visited[node]){
		dfs.push_back(node);
		visited[node] = 1;

		for(auto ele : adjL[node]){
			if(!visited[ele]){
				finddfs(ele, visited, adjL, dfs);
			}
		}
	}
}
vector<int> dfsofGraphRec(int V, vector<int> adjL[]){

	vector<int> dfs;
	vector<int> visited(V+1, 0);
	for(int i = 1; i <= V; i++){
		if(!visited[i]){
			finddfs(i, visited, adjL, dfs);
		}
	}

	return dfs;
}

vector<int> dfsofGraphSt(int V, vector<int> adjL[]){
	vector<int> dfs;
	vector<int> visited(V+1, 0);

	for(int i = 1; i <= V; i++){
		stack<int> st;
		if(!visited[i]){
			st.push(i);
			visited[i] = 1;

			while(!st.empty()){
				int node = st.top();
				st.pop();
				dfs.push_back(node);

				for(auto ele : adjL[node]){
					if(!visited[ele]){
						st.push(ele);
						visited[ele] = 1;
					}
				}
			}
		}
	}

	return dfs;
}
int main(){
	int V, E;
	cin>>V>>E;

	vector<int> adjL[V+1];

	for(int i = 0; i < E; i++){
		int u, v;
		cin>>u>>v;

		adjL[u].push_back(v);
		adjL[v].push_back(u);

	}

	for(int i = 1; i <= V; i++){
		cout<<i<<"-->";
		for(auto ele : adjL[V]){
			cout<<ele<<" ";
		}
		cout<<endl;
	}
	
	
	vector<int> dfslist1 = dfsofGraphRec(V, adjL);

	for(auto ele : dfslist1){
		cout<<ele<<" ";
	}
	cout<<endl;

	vector<int> dfslist2 = dfsofGraphSt(V, adjL);

	for(auto ele : dfslist2){
		cout<<ele<<" ";
	}

}