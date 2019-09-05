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
#define maxn 1000

//structure
struct Edge
{
	int from, to;
    float cost;

	Edge(int _from, int _to, float _cost) 
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
int parent_arr[maxn];
int n, m;
int counter;
float total;
vector<Edge> edges;
vector<PP> point;
//functions
int find(int x)
{ 
	return parent_arr[x] < 0 ? x : (parent_arr[x] = find(parent_arr[x]));
}

void kruskal_algorithm()
{
	sort(edges.begin(), edges.end());

	for(int i = 0; i < edges.size(); i++)
	{
        if(counter >= n)
            return;
		Edge tmp = edges[i];

		if(find(tmp.to) == find(tmp.from) && parent_arr[tmp.to] != -1)
		{
			//不能形成環的邊
			continue;
		}

		else
		{
            total += edges[i].cost;
            counter++;

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
}

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(cin >> n)
    {
        memset(parent_arr, -1, sizeof(parent_arr));
        edges.clear();
        point.clear();
        total = 0;
        counter = 0;

        for(int i = 0; i < n; i++)
        {
            int x, y;   cin >> x >> y;
            point.PB(make_pair(x, y));
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)  continue;
                float cost = sqrt((point[i].first-point[j].first)*(point[i].first-point[j].first) + 
                            (point[i].second-point[j].second)*(point[i].second-point[j].second));
                edges.PB(Edge(i, j, cost));
            }
        }

        cin >> m;

        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            if(find(b) == find(a) && parent_arr[b] != -1)
            {
                //不能形成環的邊
                continue;
            }

            else
            {
                counter++;
                if(parent_arr[b] == -1)
                {
                    parent_arr[find(a)] += -1;
                    parent_arr[b] = a;
                }

                else if(parent_arr[a] == -1)
                {
                    parent_arr[find(a)] -= 1;
                    parent_arr[a] = b;
                }
                else
                {
                    parent_arr[find(b)] += parent_arr[find(a)];
                    parent_arr[find(a)] = find(b);
                }
            } 
        }

        kruskal_algorithm();
        printf("%.2f\n", total);
    }

	return 0;
}