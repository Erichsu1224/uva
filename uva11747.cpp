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
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define all(x) x.begin(), x.end()
#define maxn 10000

//structure
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
		return cost < r.cost;
	}
};


//declaration
priority_queue<Edge> pq;
int parent_arr[maxn];
bool used[maxn];
bool used_ver[maxn];
int n, m;
int cost;
vector<Edge> edges;
vector<int> adj[maxn];
vector<int> ans;
//functions

void init(void)
{
	cost = 0;
	edges.clear();
	memset(used, false, sizeof(used));
	memset(parent_arr, -1, sizeof(parent_arr));
    ans.clear();

	while(!pq.empty())
		pq.pop();
}


int find(int x)
{ 
	return parent_arr[x] < 0 ? x : (parent_arr[x] = find(parent_arr[x]));
}

void prims(int vertex)
{
	for(int i = 0; i < adj[vertex].size(); i++)
	{
		int edge = adj[vertex][i];

		if(!used[edge])
        {
            pq.push(edges[edge]);
            used[edge] = true;
        }
			
	}

	while(!pq.empty())
	{
		Edge tmp = pq.top();
		pq.pop();

		if(find(tmp.to) == find(tmp.from) && parent_arr[tmp.to] != -1)
		{
			//不能形成環的邊
            cout << tmp.to << ' ' << tmp.from << endl;
			continue;
		}

		else
		{
			cost += tmp.cost;

			if(parent_arr[tmp.to] == -1)
			{
				vertex = tmp.to;
				parent_arr[find(tmp.from)] += -1;
				parent_arr[tmp.to] = tmp.from;
			}

			else if(parent_arr[tmp.from] == -1)
			{
				vertex = tmp.from;
				parent_arr[find(tmp.from)] -= 1;
				parent_arr[tmp.from] = tmp.to;
			}

			break;
		}
	}

	prims(vertex);
}



int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	while(cin >> n >> m && n && m)
	{
		init();

		for(int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			edges.push_back(Edge(a, b, c));

			adj[a].PB(i);
			adj[b].PB(i);			

			prims(0);
		}

		cout << cost << endl;
	}

	return 0;
}