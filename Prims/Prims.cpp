#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/primsmstsub/problem
using namespace std;

vector<string> split_string(string);

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
	typedef pair<int, int> pi;
	# define INF 0x3f3f3f3f
	vector<pi> adj[n];
	for (int i = 0; i < edges.size(); ++i)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		int weight = edges[i][2];
		adj[u - 1].push_back(make_pair(v,weight));
		adj[v - 1].push_back(make_pair(u,weight));
	}
	priority_queue<pi, vector<pi>, greater<pi> > pq;
	// Create a vector for keys and initalizie all keys as inf for minimum
	vector<int> key(n,INF);
	// vector to store parent array which in turn store MST
	vector<int> parent(n, -1);
	// vector to keep track of vertices included in MST
	vector<bool> inMST(n, false);
	pq.push(make_pair(0, start));
	key[start - 1] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		inMST[u - 1] = true;
		for (const auto &i : adj[u - 1]) {
			int v = (i).first;
			int weight = (i).second;
			if (inMST[v - 1] == false && key[v - 1] > weight) {
				key[v - 1] = weight;
				pq.push(make_pair(key[v - 1], v));
				parent[v - 1] = u;
			}
		}
	}
	key[start - 1] = 0;
	int sum = 0;
	for (int i = 0; i < key.size(); ++i)
		sum += key[i];
	cout << endl;
	return sum;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string nm_temp;
	getline(cin, nm_temp);

	vector<string> nm = split_string(nm_temp);

	int n = stoi(nm[0]);

	int m = stoi(nm[1]);

	vector<vector<int>> edges(m);
	for (int i = 0; i < m; i++) {
		edges[i].resize(3);

		for (int j = 0; j < 3; j++) {
			cin >> edges[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int start;
	cin >> start;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int result = prims(n, edges, start);

	fout << result << "\n";

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
			return x == y and x == ' ';
			});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
