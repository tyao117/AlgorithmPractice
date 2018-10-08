#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int searchInsert(vector<int>& nums, int target) {
	int l = 0;
	int r = nums.size() - 1;
	int m;
	while (l <= r)
	{
		m = l + (r - l) / 2;
		if (arr[m] < target)
			l = m + 1;
		else 
			r = m - 1;
	}
	return low;
}

int main() {
	int temp;
	vector<int> arr;
	while (!(cin >> temp).fail())
		arr.push_back(temp);
	cout << arr.size() << endl;
	return 0;
}
