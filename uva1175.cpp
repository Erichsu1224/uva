#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define maxn 1000+5

int girl[maxn][maxn];
int boy[maxn][maxn];
int stable[maxn];
int present[maxn];
bool picked[maxn];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int cases;
	queue<int> q;

	scanf("%d", &cases);

	for(int T = 0; T < cases; T++)
	{
		if(T)
			printf("\n");

		int n;

		scanf("%d", &n);

		fill(stable, stable+(n+1), 0);
		fill(present, present+(n+1), 1);
		fill(picked, picked+(n+1), false);


		for(int i = 1; i <= n; i++)	
			for(int j = 1; j <= n; j++)
				scanf("%d", &girl[i][j]);

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
				scanf("%d", &boy[i][j]);
			q.push(i);
		}


		while(!q.empty())
		{
			int tmp = q.front();
			q.pop(); //輪到的女孩

			//stable 男生配到哪個女生
			//cout << tmp << endl;

			if(!picked[girl[tmp][present[tmp]]])
			{
				stable[girl[tmp][present[tmp]]] = tmp;
				picked[girl[tmp][present[tmp]]] = true;
			}

			else if(picked[girl[tmp][present[tmp]]])
			{
				int tmp_boy = girl[tmp][present[tmp]];

				for(int i = 1; i <= n; i++)
				{

					if(boy[tmp_boy][i] == tmp)
					{
						//搶贏了
						//printf("1|%d|%d\n", i, boy[tmp_boy][i]);
						q.push(stable[tmp_boy]);
						present[stable[tmp_boy]]++;
						stable[tmp_boy] = tmp;
						break;
					}

					if(boy[tmp_boy][i] == stable[girl[tmp][present[tmp]]])
					{
						//printf("2\n");
						q.push(tmp);
						present[tmp]++;
						break;
					}
				}
			}

			//test
			/*
			cout << "stable:" << endl;
			for(int i = 1; i <= n; i++)
			{
				cout << stable[i] << ' ';
			}
			cout << endl;

			cout << "present:" << endl;
			for(int i = 1; i <= n; i++)
			{
				cout << present[i] << ' ';
			}
			cout << endl;
			cout << endl;
			*/
		}

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(stable[j] == i)
				{
					printf("%d\n", j);
					break;
				}
			}
		}

	}

	return 0;
}