#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int T;	cin >> T;

	while(T--)
	{
		int n;
		float avg = 0;
		vector<int> v;

		cin >> n;

		for(int i = 0; i < n; i++)
		{
			int tmp;	cin >> tmp;
			v.push_back(tmp);
			avg += tmp;
		}

		avg /= n;

		sort(v.begin(), v.end());

		float loc = n;

		for(int i = 0; i < n; i++)
		{
			if(avg < v[i])
			{
				loc = i;
				break;
			}
		}

		printf("%.3f%\n", (n-loc)/n*100);
	}
}