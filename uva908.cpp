//kruskal algorithm
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
#define maxn 1000000+5

int parent_arr[maxn];

struct Edge
{
	int to, from, dist;

	Edge(int to, int from, int dist) : to(to), from(from), dist(dist) {}

	bool operator< (const Edge& rs) const
	{
		return dist < rs.dist;
	}
};

int find(int x)
{ 
    return parent_arr[x] < 0 ? x : (parent_arr[x] = find(parent_arr[x]));
}

vector<Edge> edges;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;
	bool first = true;

	while(~scanf("%d", &n))
	{
		int total_ori = 0;
		int total_new = 0;
		edges.clear();

		for(int i = 0; i < n-1; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			total_ori += c;
		}

		int k;
		scanf("%d", &k);
		for(int i = 0; i < k; i++)
		{
			int to, from, dist;
			scanf("%d %d %d", &to, &from, &dist);
			edges.PB(Edge(to, from, dist));
		}

		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; i++)
		{
			int to, from, dist;
			scanf("%d %d %d", &to, &from, &dist);
			edges.PB(Edge(to, from, dist));
		}

		sort(edges.begin(), edges.end());

		//test
		/*
		for(int i = 0; i < edges.size(); i++)
		{
			printf("%d %d %d\n", edges[i].to, edges[i].from, edges[i].dist);
		}
		*/

		memset(parent_arr, -1, sizeof(parent_arr));
		for(int i = 0; i < edges.size(); i++)
	    {
	        Edge tmp = edges[i];

	        if(find(tmp.to) == find(tmp.from) && parent_arr[tmp.to] != -1)
	        {
	        	
	            continue;
	        }

	        else
	        {
	        	//printf("%d %d %d\n", edges[i].to, edges[i].from, edges[i].dist);
	            total_new += tmp.dist;

	            if(parent_arr[tmp.to] == -1)
	            {
	                parent_arr[find(tmp.from)] += -1;
	                parent_arr[tmp.to] = tmp.from;
	            }

	            else if(parent_arr[tmp.from] == -1)
	            {
	                parent_arr[find(tmp.from)] -= 1;
	                parent_arr[tmp.from] = tmp.to;
	            }
	            else
	            {
	                parent_arr[find(tmp.to)] += parent_arr[find(tmp.from)];
	                parent_arr[find(tmp.from)] = find(tmp.to);
	            }
	        }
	    }
	    if (first)
            first = false;
        else
            putchar('\n');
        printf("%d\n%d\n", total_ori, total_new);
	}

	return 0;
}