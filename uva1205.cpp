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

struct Item
{
	int id;
	int cost;
	vector<int> child;
	int weight;

	Item(int weight = 0) : weight(weight) { }

	bool operator< (const Item&rs) const
	{
		if(weight == rs.weight)
			return cost < rs.weight;
		return weight < rs.weight;
	}
};

int N, R;
Item tree[maxn];

int dfs(int a)
{
	int n = tree[a].child.size();

	tree[a].weight += tree[a].cost;
	
	for(int i = 0; i < n; i++)
	{
		tree[a].weight += dfs(tree[a].child[i]);
	}

	return tree[a].weight;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	while(~scanf("%d %d", &N, &R) && N && R)
	{
		for(int i = 1; i <= N; i++)
		{
			tree[i].id = i;
			scanf("%d", &tree[i].cost);
		}

		for(int i = 0; i < N; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);

			tree[a].child.PB(b);
		}

		dfs(R);
/*
		for(int i = 1; i <= N; i++)
		{
			cout << i  << " " << tree[i].weight << endl;
		}
*/

		priority_queue<Item> q;
		q.push(tree[R]);

		int counter = 1;
		int total = 0;

		while(!q.empty())
		{
			Item tmp = q.top();
			total += tmp.cost * (counter++);
			q.pop();

			//test
			cout << tmp.weight << ' ' << tmp.id << endl;

			for(int i = 0; i < tmp.child.size(); i++)
			{
				q.push(tree[tmp.child[i]]);
			}
		}

		cout << total << endl;
	}

	return 0;
}