//kruskal algorithm

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define maxn 10100

struct Edge
{
	int from, to, cost;

	Edge(int _from, int _to, int _cost) 
	{
		from = _from;
		to = _to;
		cost = _cost;
	}

	bool operator< (const Edge &r) const
	{
		return r.cost < cost;
	}
};

int graph[maxn];
int parent_arr[maxn];
int n, m;
vector<Edge> edges;

//find
int find(int x)
{ 
	return parent_arr[x] < 0 ? x : (parent_arr[x] = find(parent_arr[x]));
}

//intersection

int kruskal_algorithm(int vertex, int edge)
{
	int cost = 0;
	memset(parent_arr, -1, sizeof(parent_arr));

	for(int i = 0; i < edge; i++)
	{
		Edge tmp = edges[i];

		if(find(tmp.to) == find(tmp.from) && parent_arr[tmp.to] != -1)
		{
			cost += tmp.cost;
		}

		else
		{
			
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

	return cost;
}

int main(void)
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int cases;
	while(scanf("%d", &cases))
	{
		if(cases == 0)
			break;
		while(cases--)
		{
			scanf("%d %d", &n, &m);

			for(int i = 0; i < m; i++)
			{
				int a, b, c;
				scanf("%d %d %d", &a, &b, &c);
				edges.push_back(Edge(a, b, c));
			}

			sort(edges.begin(), edges.end());

			

			// call the function
			printf("%d\n", kruskal_algorithm(n, m));
			edges.clear();
		}

	}
	return 0;
}