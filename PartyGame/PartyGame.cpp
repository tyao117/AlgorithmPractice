#include <bits/stdc++.h>

using namespace std;

bool isPowerOfTwo(int n)
{
   return (ceil(log2(n)) == floor(log2(n)));
}

string doIStarve(vector<int>& v) {
	string result[2] = {"All can eat.","Some starve."};
	vector<bool> visited (v.size(), false);
	for (int i = 0; i < v.size(); ++i) {
		visited[i] = true;
		int size = 1;
		if (v[i] != i + 1) {
			int next = v[i];
			while (visited[next - 1] == false) {
				visited[next - 1] = true;
				next = v[next - 1];
				++size;
			}
			if (!isPowerOfTwo(size))
				return result[1];
		}
	}
	return result[0];
}
int main()
{
	int testcases;
	int size;
	cin >> testcases;
	for (int i  = 0; i < testcases; ++i) {
		cin >> size;
		vector<int> party (size);
		for (int j = 0; j < size; ++j ){
				int temp;
				cin >> temp;
				party[j] = temp;
		}
		cout << doIStarve(party) << endl;
	}
	return 0;
}
