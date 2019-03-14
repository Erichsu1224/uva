#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int time;

	cin >> time;

	for(int j = 0; j < time; j++)
	{
		int n, container;
		vector <int> lis;

		cin >> n >> container;

		for(int i = 0; i < n; i++)
		{
			int a;

			cin >> a;
			lis.push_back(a);
		}

		sort(lis.begin(), lis.end());

		int left = 0, right = lis.size()-1, counter = 0;

		while(left <= right)
		{
			if(container - lis[right] < lis[left])
			{
				right--;
				counter++;
			}

			else if(container - lis[right] >= lis[left])
			{
				right--;
				left++;
				counter++;
			}
		}
		if(j == 0)
			cout << counter;
		else
			cout << ' ' << counter;
	}
	cout << endl;

	return 0;
}