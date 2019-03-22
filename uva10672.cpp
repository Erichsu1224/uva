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
#define maxn 10000+5

struct Item
{
	Item()
	{
		ball = 0;
		parent = 0;
	}
	int list;
	int ball;
	vector<int> child;
	int parent;

	void set_child(int a)
	{
		child.PB(a);
	}
};

int step;

void dfs(Item* tree, int par, int num)
{
	//test
	//cout << num << endl;

	//if(tree[num].child.size() == 0)
		//return;
	
	for(int i = 0; i < tree[num].child.size(); i++)
	{
		dfs(tree, num, tree[num].child[i]);
	}
	
	//if(par == -1)
		//return;

	int hold = tree[num].ball-1;
	tree[num].ball = 1;
	tree[par].ball += hold;
	step += abs(hold);
	//test
	//printf("step: %d, hold: %d\n", step, hold);
	return;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;

	while(~scanf("%d", &n))
	{
		if(n == 0)
			break;

		Item tree[maxn];
		step = 0;
		int start;

		for(int i = 0; i < n; i++)
		{
			int num, balls, children;

			scanf("%d %d %d", &num, &balls, &children);
			tree[num].ball = balls;

			if(i == 0)
				start = num;

			for(int k = 0; k < children; k++)
			{
				int tmp;
				scanf("%d", &tmp);
				tree[tmp].parent = num;
				tree[num].set_child(tmp);
			}

			//test
		}

		//find where is the start
		for(int i = 1; i <= n; i++)
		{
			if(tree[i].parent == 0)
			{
				start = i;
				break;
			}
		}

		dfs(tree, -1, start);

/*
		for(int i = n; i >= 1; i--)
		{				
			int hold = tree[i].ball-1;
			tree[i].ball = 1;
			tree[tree[i].parent].ball += hold;
			step += abs(hold);
			//test
			//printf("step: %d\n", step);
		}
*/
		printf("%d\n", step);
	}

	return 0;
}