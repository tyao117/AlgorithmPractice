#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int root(int arr[], int i) {
	while (arr[i] != i) {
		arr[i] = arr[arr[i]];
		i = arr[i];
	}
	return i;
}

void union_two(int arr[], int size[], int a, int b) {
	int root_a = root(arr, a);
	int root_b = root(arr, b);
	if(size[root_a] < size[root_b]) {
		arr[root_a] = arr[root_b];
		size[root_b] += size[root_a];
	}
	else {
		arr[root_b] = arr[root_a];
		size[root_a] += size[root_b];
	}
}

void initialize(int arr[], int size[], int n) {
	for (int i = 0; i < n; ++i) {
		arr[i] = i;
		size[i] = 1;
	}
}

// Complete the journeyToMoon function below.
unsigned long long journeyToMoon(int n, vector<vector<int>> astronaut) {
	int arr[n];
	int size[n];
	initialize(arr, size, n);
	unsigned long long total = 0;
	for (int i = 0; i < astronaut.size(); ++i) {
		int first = astronaut[i][0];
		int second = astronaut[i][1];
		union_two(arr, size, first, second);
	}
	vector<int> result_set;
	for (int i = 0; i < n; ++i) {
		if (arr[i] == i) {
			result_set.emplace_back(size[i]);
		}
	}
	for (int i = 0, n = result_set.size(); i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			total += result_set[i] * result_set[j];
		}
	}
	cout << total << endl;
	return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string np_temp;
    getline(cin, np_temp);
    vector<string> np = split_string(np_temp);
    int n = stoi(np[0]);
    int p = stoi(np[1]);
    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);
        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    long long result = journeyToMoon(n, astronaut);
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
