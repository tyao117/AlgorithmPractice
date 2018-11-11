#include <bits/stdc++.h>

using namespace std;

int handle_string(const string& input)
{
	int changes = 0;
	for (int i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] == input[i+1])
			changes++;
		while (input[i] == input[i+1])
			i++;
	}
	return changes;
}

int main()
{
	int size;
	string input;
	cin >> size;
	vector<string> v(size);
	for (int i = 0; i < size; ++i)
	{
		cin >> input;
		cout << handle_string(input) << endl;
	}
	return 0;
}
