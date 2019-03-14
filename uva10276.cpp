#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define C cases
#define pb push_back
#define maxn 50+5

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int C;

	scanf("%d", &C);

	while(C--)
	{
		int N;
		bool finished = false;
		vector<int> pillers[maxn];

		scanf("%d", &N);

		for(int i = 1; ; i++)
		{
			for(int n = 0; n < N; n++)
			{
				//infinity is not avalible
				if(pillers[n].size() == 0)
				{
					pillers[n].pb(i);
					break;
				}

				else if(sqrt(pillers[n][pillers[n].size()-1]+i) == (int)sqrt(pillers[n][pillers[n].size()-1]+i))
				{
					pillers[n].pb(i);
					break;
				}

				else if(n == N-1)
				{
					finished = true;
					printf("%d\n", i-1);
					break;
				}
			}
			
			if(finished)
				break;
		}
	}

	return 0;
}