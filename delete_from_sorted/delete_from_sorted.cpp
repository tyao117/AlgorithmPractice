#include <iostream>
#include <vector>

using namespace std;

void print_out_array(const vector<int> &array)
{
	int size = array.size();
	for (int i = 0; i < size; ++i)
		cout << array[i] << " ";
	cout << endl;
}

void delete_from_sorted(vector<int> &array)
{
	if (array.empty())
		return;
	int index=1;
	int last_index = array.size() - 1;
	for(int i = 1; i <= last_index; ++i)
		if (array[index - 1] != array[i])
			array[index++] = array[i];
	array.resize(index);	
}

int main() {
	int temp;
	vector<int> s_array;
	while(!(cin>>temp).fail())
		s_array.push_back(temp);
	print_out_array(s_array);
	delete_from_sorted(s_array);
	print_out_array(s_array);	
	return 0;	
}
