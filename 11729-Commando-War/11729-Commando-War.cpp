#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int,int> b)
{
	if (a.second == b.second)
		return (a.first < b.second);
	return a.second < b.second;
}

int total_time (int soldiers)
{
	int t_time = 0;
	int e_time = 0;
	int timer;
	vector<pair<int,int>> v(soldiers);
	for (int i = 0; i < soldiers; ++i)
	{
		pair<int,int> temp;
		cin >> temp.first;
		cin >> temp.second;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), compare);
	t_time += v[0].first;
	e_time = v[0].second;
	for (int i = 1; i < soldiers; ++i)
	{
		
	}
	t_time += e_time;
	return t_time;
}

int main()
{
	int soldiers;
	int i = 1;
	while (true)
	{
		cin >> soldiers;
		if (!soldiers)
		return 0;
		else
			cout << "Case " << i++ << ":  " << total_time(soldiers)<< endl;
	}
}
