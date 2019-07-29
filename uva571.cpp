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
#define maxn 1000+5

//structure

//declaration
int A, B, N;
vector<string> v;
bool visit[maxn][maxn];
//functions

bool dfs(int a, int b)
{
    //cout << a << ' ' << b << ' ' << visit[a][b] << endl;
    visit[a][b] = true;
    if(a == N || b == N)
        return true;
    if(!visit[A][b])
    {
        v.PB("fill A");
        if(dfs(A, b))
            return true;
        v.pop_back();
    }
    if(!visit[a][B])
    {
        v.PB("fill B");
        if(dfs(a, B))
            return true;
        v.pop_back();
    }
    if(!visit[0][b])
    {
        v.PB("empty A");
        if(dfs(0, b))
            return true;
        v.pop_back();
    }
    if(!visit[a][0])
    {
        v.PB("empty B");
        if(dfs(a, 0))
            return true;
        v.pop_back();
    }
    if(b > A-a)
    {
        if(!visit[A][b-(A-a)])
        {
            v.PB("pour B A");
            if(dfs(A, b-(A-a)))
                return true;
            v.pop_back();
        }
    }
    else
    {
        if(!visit[a+b][0])
        {
            v.PB("pour B A");
            if(dfs(a+b, 0))
                return true;
            v.pop_back();
        }
    }
    
    if(a > B-b)
    {
        if(!visit[a-(B-b)][B])
        {
            v.PB("pour A B");
            if(dfs(a-(B-b), B))
                return true;
            v.pop_back();
        }
    }

    else
    {
        if(!visit[0][a+b])
        {
            v.PB("pour A B");
            if(dfs(0, a+b))
                return true;
            v.pop_back();
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

    while(cin >> A >> B >> N)
    {
        v.clear();
        memset(visit, false, sizeof(visit));

        dfs(0, 0);
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << '\n';
        }
        cout << "success\n";
    }

	return 0;
}