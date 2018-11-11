#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> adj[], vector<int>& nodes, int s, int e) {
	vector<int>::iterator u;
	nodes[s] += 1;
	for(u = adj[s].begin(); u != adj[s].end(); ++u)
	{
		if (*u == e)
			continue;
		dfs(adj, nodes, *u, s);
		nodes[s] += nodes[*u];
	}
}

void addEdges(vector<int> adj[], int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main() {
	int nodes;
	int edges;
	int first;
	int second;
	cin >> nodes;
	cin >> edges;
	vector<int> adj[nodes+1];
	vector<int> node_arr(nodes+1,0);
	for(int i = 0; i < edges; ++i)
	{
		cin >> first >> second;
		addEdges(adj, first, second);
	}
	dfs(adj, node_arr, 1, 0);
	for (int i = 1; i < nodes+1; ++i)
	{
		cout << node_arr[i] << endl;
	}
	return 0;
}
