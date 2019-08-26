#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	vector<int> v;

	while(cin >> n)
	{
		v.push_back(n);
		sort(v.begin(), v.end());

		if(v.size()%2 == 1)
		{
			cout << v[v.size()/2] << '\n';
		}
		else
			cout << (v[v.size()/2]+v[v.size()/2-1])/2 << '\n';
	}
	return 0;
}