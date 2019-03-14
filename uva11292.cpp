#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define pb push_back
#define maxn 20005

int dragon[maxn];
vector<int> knight;
bool hired[maxn];

int main(void)
{
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n, m;

	while(~scanf("%d %d", &n, &m) && (n != 0 || m != 0))
	{
		int total = 0;
		memset(hired, false, m*sizeof(bool));
		knight.clear();

		for(int i = 0; i < n; i++)
			scanf("%d", &dragon[i]);
		for(int i = 0; i < m; i++)
		{
			int a;
			scanf("%d", &a);
			knight.pb(a);
		}

		if(n > m)
		{
			printf("Loowater is doomed!\n");
			continue;
		}

		sort(dragon, dragon+n);
		sort(knight.begin(), knight.end());

		/*
		//test
		printf("Dragon: ");
		for(int i = 0; i < n; i++)
		{
			printf("%d ", dragon[i]);
		}
		printf("\n");
		printf("Knight: ");
		for(int i = 0; i < m; i++)
			printf("%d ", knight[i]);
		printf("\n");
		//end test
		*/

		bool wrong = false;

		for(int i = 0; i < n; i++)
		{
			int tmp = -1;
			for(int k = 0; k < knight.size(); k++)
			{
				if(dragon[i] <= knight[k])
				{
					tmp = k;
					break;
				}
			}

			if(tmp == -1)
			{
				wrong = true;
				break;
			}

			total += knight[tmp];
			knight.erase(knight.begin()+tmp);
		}

		if(wrong)
		{
			printf("Loowater is doomed!\n");
			continue;
		}


		printf("%d\n", total);
	}

	return 0;
}