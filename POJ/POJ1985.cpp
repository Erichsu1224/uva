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
#define maxn 40000+5

//structure
struct Item
{
    int f, t, w;

    Item(int f, int t, int w) : f(f), t(t), w(w) {}

};

//declaration
int n, m;
int max_dis, target_ver, target_ori;
bool visit[maxn];
vector<Item> v;
vector<int> edges[maxn];
//functions
void dfs(int vertex, int dis)
{
    visit[to_ver] = true;
    if(dis > max_dis)
    {
        max_dis = dis;
        target_ver = vertex;
    }

    for(int i = 0; i < edges[vertex].size(); i++)
    {
        int to_ver = v[edges[vertex][i]].t;

        if(!visit[to_ver])
        {
            dfs(to_ver, dis+v[edges[vertex][i]].w);
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

    

    while(cin >> n >> m)
    {
        max_dis = 0;

        for(int i = 0; i < m; i++)
        {
            int from, to, w;
            char dir;

            cin >> from >> to >> w >> dir;

            v.PB(Item(from, to, w));
            v.PB(Item(to, from, w));

            edges[from].PB(v.size()-2);
            edges[to].PB(v.size()-1);
        }

        dfs(1, 0);

        max_dis = 0;
        target_ori = target_ver;

        dfs(target_ver, 0);

        cout << max_dis << '\n';
    }


	return 0;
}