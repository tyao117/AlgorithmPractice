#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/dijkstrashortreach/problem

using namespace std;

vector<string> split_string(string);

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
	typedef pair<int, int> pi;
	#define INF 0x3f3f3f3f
	set<pi> adj[n];
	vector<int> dist(n, -1);
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	for (int i = 0; i < edges.size(); ++i) {
		int u = edges[i][0];
		int v = edges[i][1];
		int weight = edges[i][2];
		adj[u - 1].emplace(make_pair(v, weight));
		adj[v - 1].emplace(make_pair(u, weight));
	}
	pq.emplace(make_pair(0, s));
	dist[s - 1] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (const auto& i : adj[u - 1]) {
				int v = i.first;
				int weight = i .second;
				if (dist[ v - 1] == -1 || dist[v - 1] > dist[u - 1] + weight) {
					dist[v - 1] = dist[u - 1] + weight;
					pq.emplace(dist[v - 1], v);
				}
		}
	}
	dist.erase(dist.begin() + s - 1);
	for (int i = 0; i < n -1; ++i)
		cout <<dist[i] << endl;
	return dist;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
