#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void radix_sort(vector<int>& arr, int size)
{
  int max_num = max(arr);

}

int main()
{
  vector<int> lst;
  int temp;
  while (cin >> temp)
  {
    lst.push_back(temp);
  }
  cin.clear();
  static int size = lst.size();
  radix_sort(lst, size);
  return 0;
}
