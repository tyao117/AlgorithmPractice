#include <bits/stdc++.h>

using namespace std;

bool dfs(const vector<vector<char>>& grid,const vector<vector<char>>& grid2, vector<vector<bool>>& visited, int row, int col)
{
	const int row_arr[4] = {-1, 0, 1, 0};
	const int col_arr[4] = {0, 1, 0, -1};
	if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
		return 1;
	if (grid[row][col] != grid2[row][col])
		return 0;
	int temp = 1;
	if (grid[row][col] == '1' && visited[row][col] == false) {
		visited[row][col] = true;
		for (int i = 0; i < 4; ++i)
		{
			temp &= dfs(grid, grid2, visited, row + row_arr[i], col + col_arr[i]);
		}
	}
	return temp;
}

int numIslands(const vector<vector<char>>& grid,const vector<vector<char>>& grid2) {
	if (grid.empty()) return 0;
	int row = grid.size();
	int col = grid[0].size();
	int islands = 0;
	vector<vector<bool>> visited(row, vector<bool>(col,false));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (grid[i][j] == '1' && !visited[i][j])
			{
				islands += dfs(grid, grid2, visited, i, j);
			}
		}
	}
	return islands;
}

void handletemp(vector<vector<char>>& v, const string& line)
{
	stringstream ss;
	ss << line;
	vector<char> temp;
	char c;
	while (ss >> c)
	{
		temp.push_back(c);
	}
	v.push_back(temp);
}

int main()
{
	int size1, size2;
	string line;
	vector<vector<char>> grid;
	vector<vector<char>> grid2;
	while (getline(cin, line) && line.size())
	{
		handletemp(grid, line);
	}
	while (getline(cin,line))
	{
		handletemp(grid2, line);
	}
	//cout << grid.size() << " " << grid[0].size() << endl;
	//cout << grid2.size() << " " << grid2[0].size() << endl;
	cout <<  numIslands(grid, grid2) << endl;
	return 0;
}
