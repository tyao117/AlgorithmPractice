#include <bits/stdc++.h>

using namespace std;

void LIS(vector<int>& arr) {
	unordered_map<int,int> parent;
	vector<int> dp(arr.size(), 0);
	int length = 0;
	for (int i = 0; i < arr.size(); ++i) {
		int l = 0, r = length;
		while (l < r) {
			int mid = (l+r) / 2;
			if (dp[mid] < arr[i])
				l = mid + 1;
			else
				r = mid;
		}
		dp[l] = arr[i];
		length = max(length, l+1);
		if (l == 0)
			parent[arr[i]] = -1;
		else
			parent[arr[i]] = l-1;
	}
	for (auto i : parent) {
		cout << i.first << " " << i.second << endl;
	}
}

int main()
{
	int size;
	cin >> size;
	vector<int> arr(size);
	for (int i = 0; i < size; ++i) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	LIS(arr);
	return 0;
}
