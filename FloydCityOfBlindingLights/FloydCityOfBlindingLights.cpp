#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
vector<vector<int>> Floyd(vector<int>road_from, vector<int> road_to, vector<int> road_weight, int road_nodes){
	int x, y , z;
	vector<vector<int>> dp(road_nodes + 1, vector<int>(road_nodes + 1, 0x0f0f0f0f));
	for (int i = 0; i < road_nodes; ++i) {
		x = road_from[i];
		y = road_to[i];
		z = road_weight[i];
		dp[x][y] = z;
	}
	for (int k = 0; k < road_nodes; ++k) {
		for (int i = 0; i < road_nodes; ++i) {
			for (int j = 0; j < road_nodes; ++j) {
				if (dp[i][k] + dp[k][j] < dp[i][j])
        	dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}
	return dp;
}

int main()
{
    int road_nodes;
    int road_edges;

    cin >> road_nodes >> road_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> road_from(road_edges);
    vector<int> road_to(road_edges);
    vector<int> road_weight(road_edges);

    for (int i = 0; i < road_edges; i++) {
        cin >> road_from[i] >> road_to[i] >> road_weight[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

		vector<vector<int>> dp = Floyd(road_from, road_to, road_weight, road_nodes);

		int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string xy_temp;
        getline(cin, xy_temp);
        vector<string> xy = split_string(xy_temp);
        int x = stoi(xy[0]);
        int y = stoi(xy[1]);
				if (dp[x][y] == 0x0f0f0f0f)
					cout << -1 << endl;
				else
					cout << dp[x][y] << endl;
    }

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
