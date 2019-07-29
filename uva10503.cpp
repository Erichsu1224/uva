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
#define maxn 14+5

//structure

//declaration
int n, m;
PP start, fin;
vector< PP > v;
bool visit[maxn];

//functions
bool dfs(int t, int w)
{
    //cout << t << ' ';
    if(t == fin.first && w == n)
    {
        return true;
    }

    if(w == n)
    {
        return false;
    }
        
    for(int i = 0; i < v.size(); i++)
    {
        if(t == v[i].first && !visit[i])
        {
            visit[i] = true;
            if(dfs(v[i].second, w+1))    return true;
            visit[i] = false;
        }

        if(t == v[i].second && !visit[i])
        {
            visit[i] = true;
            if(dfs(v[i].first, w+1))    return true;
            visit[i] = false;
        }
    }

    return false;
}
int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(cin >> n && n)
    {
        v.clear();
        memset(visit, false, sizeof(visit));

        cin >> m;
    
        cin >> start.first >> start.second;
        cin >> fin.first >> fin.second;

        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            v.PB(make_pair(a, b));
        }

        if(dfs(start.second, 0)) cout << "YES\n";
        else    cout << "NO\n";
    }

	return 0;
}