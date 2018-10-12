#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int,int> b)
{
	return a.first + b.first + b.second < b.first + a.first + a.second;
}

void total_time (int soldiers)
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
		cout << v[i].first << " " << v[i].second << endl;
		timer = v[i].first;
		e_time = max(e_time, v[i].second);
		t_time += timer;
		e_time -= timer;
	}
	t_time += e_time;
	cout << t_time << endl;
}

int main()
{
	int soldiers;
	while (true)
	{
		cin >> soldiers;
		if (!soldiers)
		return 0;
		else
		total_time(soldiers);
	}
}
