#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct Item
{
	int from, to;

	Item(int from, int to) : from(to), to(from){}

};

struct Edge
{
	int to, from, dist;

	Edge(int from, int to, int dist) : from(from), to(to), dist(dist) {}

	bool operator < (const Edge& rs) const
	{
		return dist > rs.dist;
	}
};

int main(void)
{
	#ifndef	jug
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;
	int k = 1;

	while(~scanf("%d\n", &n) && n != -1)
	{
		vector<Item> items;
		vector<Edge> v;
		vector<char> list;
		int start, end, cost;
		char a, b;
		vector<int> adj[130];
		bool visited[130] = {false};

		for(int i = 0; i < n; i++)
		{
			scanf("%c %c\n", &a, &b);

			items.push_back(Item((int)a, (int)b));
			adj[(int)b].push_back(i);
		}


		scanf("%d %c %c", &cost, &a, &b);

		start = (int)a;
		end = (int)b;

		priority_queue<Edge> q;

		if(end >= 65 && end <= 90)
		{
			cost = cost + (cost-1)/19 + 1;
		}
		else if(end >= 97 && end <= 122)
			cost += 1;


		q.push(Edge(end, end, cost));
		visited[end] = true;
		bool finish = false;

		while(!q.empty())
		{
			Edge tmp = q.top();
			visited[tmp.to] = true;
			q.pop();
			v.push_back(tmp);


			for(int i = 0; i < adj[tmp.to].size(); i++)
			{
				Item u = items[adj[tmp.to][i]];

				if(u.to == start)
				{
					finish = true;
					q.push(Edge(tmp.to, u.to, tmp.dist));
					v.push_back(Edge(tmp.to, u.to, tmp.dist));
					break;
				}

				if(visited[u.to])
					continue;
				else
				{
					if(u.to >= 65 && u.to <= 90)
					{
						q.push(Edge(tmp.to, u.to, tmp.dist + (tmp.dist-1)/19 + 1));
					}

					else if(u.to >= 97 && u.to <= 122)
						q.push(Edge(tmp.to, u.to, tmp.dist+1));
				}
			}

			if(finish)
				break;
		}

		printf("Case %d:\n", k++);
		printf("%d\n", q.top().dist);

		int node = end;
		list.push_back(end);
		
		while(node != start)
		{
			for(int i = 0; i < v.size(); i++)
			{
				if(v[i].to == v[i].from)
					continue;
				if(v[i].from == node)
				{
					list.push_back(v[i].to);
					node = v[i].to;
					break;
				}

			}
		}
		
		
		for(int i = list.size()-1; i >= 0; i--)
		{
			if(i == 0)
				printf("%c\n", list[i]);
			else
				printf("%c-", list[i]);
		}
		


		

	}
	return 0;
}