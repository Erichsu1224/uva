#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
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
#define maxn 100005

struct Point{
	int x, y, w, d;
	Point(){
		x = y = w = d = 0;
	}
};

int T, w, n;
int sumw[maxn], sumd[maxn], dp[maxn];
Point p[maxn], zero;

int dis(Point a, Point b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}

int func(int j)
{
	return dp[j]+p[j+1].d-sumd[j+1];
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int T;

	scanf("%d", &T);

	while(T--)
	{
		scanf("%d %d", &w, &n);

		for(int i = 1; i <= n; i++)
		{
			scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].w);
			sumw[i] = sumw[i-1]+p[i].w;
			sumd[i] = sumd[i-1]+dis(p[i], p[i-1]);
			p[i].d = dis(p[i], zero);
		}

		deque<int> Q;
		Q.push_front(0);
		for(int i = 1; i <= n; i++)
		{
			while(!Q.empty() && sumw[i]-sumw[Q.front()] > w)
			{
				Q.pop_front();
			}
			dp[i] = func(Q.front())+sumd[i]+p[i].d;

			while(!Q.empty() && func(i) <= func(Q.back()))
			{
				Q.pop_back();
			}
			Q.push_back(i);
		}

		printf("%d\n", dp[n]);
		if(T)	printf("\n");
	}

	return 0;
}