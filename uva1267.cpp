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

int n;
int server;
int dis;
int parent[maxn];
vector<int> adj[maxn];
vector<int> nodes[maxn];
bool visit[maxn];

void dfs(int from, int node, int dist)
{
	parent[node] = from;

	if(adj[node].size()==1 && dist > dis)
	{
		nodes[dist].PB(node);
	}

	for(int i = 0; i < adj[node].size(); i++)
	{
		if(adj[node][i] != from)
			dfs(node, adj[node][i], dist+1);
	}
}

void dfs2(int node, int from, int dist)
{
	visit[node] = true;

	for(int i = 0; i < adj[node].size(); i++)
	{
		if(adj[node][i] != from && dist < dis)
		{
			dfs2(adj[node][i], node, dist+1);
		}
	}
}

int solve(void)
{
	int counter = 0;
	memset(visit, false, sizeof(visit));
	for(int i = n-1; i > dis; i--)
	{
		for(int k = 0; k < nodes[i].size(); k++)
		{
			int u = nodes[i][k];
			if(visit[u])
				continue;
			for(int j = 0; j < dis; j++)
			{
				u = parent[u];
			}
			dfs2(u, -1, 0);
			counter++;
		}
	}
	return counter;
}

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
		scanf("%d", &n);
		scanf("%d %d", &server, &dis);

		for(int i = 0; i <= n; i++)
		{
			adj[i].clear();
			nodes[i].clear();
		}

		for(int i = 0; i < n-1; i++)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			adj[from].PB(to);
			adj[to].PB(from);
		}

		dfs(-1, server, 0);
		printf("%d\n", solve());
	}

	return 0;
}