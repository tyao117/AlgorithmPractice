#include <bits/stdc++.h>

using namespace std;

void subString(string str, int n, set<string>& se)
{
	for (int i = 0; i < n; i++) {
		for (int len = 1; len <= n - i; len++) {
			se.emplace(str.substr(i, len));
		}
	}
}

string deleteDuplicates(string str)
{
	if (!str.size())
		return "";
	string temp = str;
	int write_index = 1;
	for (int i = 1; i < str.size(); ++i) {
		if (str[write_index - 1] != str[i])
			temp[write_index++] = str[i];
	}
	return temp.substr(0, write_index);
}

int main()
{
	string str = "hello";
	sort(str.begin(), str.end());
	cout << deleteDuplicates(str) << endl;
	cout << str << endl;
	cout << endl;
	set<string> se;
	subString(str, str.size(), se);
	for (auto s : se)
		cout << s << endl;
	return 0;
}
