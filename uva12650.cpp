#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool peo[10005];

int main(void)
{
	int n, m;

	while(cin >> n >> m)
	{
		memset(peo, false, sizeof(peo));

		for(int i = 0; i < m; i++)
		{
			int tmp;
			cin >> tmp;

			peo[tmp] = true;
		}

		if(n == m)
		{
			cout << "*\n";
			continue;
		}

		for(int i = 1; i <= n; i++)
		{
			if(!peo[i])
			{
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}