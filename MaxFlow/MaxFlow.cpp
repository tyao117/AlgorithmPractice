#include <bits/stdc++.h>

using namespace std;

bool bfs (const vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
		vector<bool> visited(parent.size(), false);
		queue<int> q;
		q.push(s);
		visited[s] = true;
		parent[s] = -1;

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int v = 0; v < parent.size(); v++) {
				if (visited[v] == false && rGraph[u][v] > 0) {
					q.push(v);
					parent[v] = u;
					visited[v] = true;
				}
			}
		}
	 	// If we reached sink in BFS starting from source, then return 
    // true, else false
		return (visited[t] == true);
}

int fordFulkerson(const vector<vector<int>>& graph, int s, int t) {
	int u, v;
	// create the residual graph
	vector<vector<int>> rGraph = graph;
	vector<int> parent(graph.size());
	int max_flow = 0;
	while (bfs(rGraph, s, t, parent)) {
		// Find minimum residual capacity of the edges along the
    // path filled by BFS. Or we can say find the maximum flow
    // through the path found.
		int path_flow = INT_MAX;
		for (v = t; v != s; v=parent[v]) {
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}
		// update residual capacities of the edges and reverse edges
    // along the path
		for (v = t; v != s; v = parent[v]) {
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main()
{
    // Let us create a graph shown in the above example
    vector<vector<int>> graph = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);

    return 0;
}
