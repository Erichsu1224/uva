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

struct point
{
	int x, y, z, channal;
	point(int x, int y, int z, int c) : x(x), y(y), z(z), channal(c) {}
};

struct Edge
{
	int from, to;
	float dist;
	Edge(int from, int to, float dist) : from(from), to(to), dist(dist) {}

	bool operator<(const Edge&rs) const
	{
		return dist < rs.dist;
	}
};


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;

	while(~scanf("%d", &n) && n != 0)
	{
		vector<point> planet;
		vector<Edge> edges;
		int status[maxn];
		int d_p = 0, ans_p = 0;
		float r = 0.0;

		for(int i = 0; i < n; i++)
		{
			int x, y, z, channal;
			scanf("%d %d %d %d", &x, &y, &z, &channal);
			planet.PB(point(x, y, z, channal));
		}

		for(int i = 0; i < planet.size()-1; i++)
		{
			for(int l = i+1; l < planet.size(); l++)
			{
				float dist = sqrt((planet[i].x-planet[l].x)*(planet[i].x-planet[l].x)+(planet[i].y-planet[l].y)*(planet[i].y-planet[l].y)+(planet[i].z-planet[l].z)*(planet[i].z-planet[l].z));
				edges.PB(Edge(i, l, dist));
			}
		}

		sort(edges.begin(), edges.end());

		for(int i = 0; i < n+5; i++)
		{
			status[i] = 1;
		}

		for(int i = 0; i < edges.size(); i++)
		{
			int pl1 = edges[i].from;
			int pl2 = edges[i].to;
			if(planet[pl1].channal == planet[pl2].channal)
			{
				if(status[pl1] == -1)
					d_p--;
				if(status[pl2] == -1)
					d_p--;
				status[pl1]++;
				status[pl2]++;
			}
			if(planet[pl1].channal != planet[pl2].channal)
			{
				if(status[pl1] == 0)
					d_p++;
				if(status[pl2] == 0)
					d_p++;
				status[pl1]--;
				status[pl2]--;
			}

			if(i == edges.size()-1 ||edges[i].dist != edges[i+1].dist)
			{
				if(ans_p < d_p)
				{
					ans_p = d_p;
					r = edges[i].dist;
				}
			}
		}

		printf("%d\n%.4f\n", ans_p, r);
	}

	return 0;
}