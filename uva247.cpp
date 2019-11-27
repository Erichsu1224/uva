#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = y; x <= z; x++)
#define REPP(x, y, z) for(int x = y; x >= z; x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define maxn 25+5

//structure

//declaration
int n, m;
vector<string> idx;
int cir[maxn];
int adj[maxn][maxn];

//functions

int GetIdx(string str)
{
    if(idx.size() != 0)
    {
        for(int i = 0; i < idx.size(); i++)
        {
            if(str == idx[i])
            {
                return i;
            }
        }
    }

    idx.PB(str);
    return idx.size()-1;
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    int cases = 0;

    while(~scanf("%d %d", &n, &m))
    {
        if(!n && !m)
            break;
        if(cases)
            puts("");
        printf("Calling circles for data set %d:\n", ++cases);
        //init
        idx.clear();
        MSET(adj, 0);
        MSET(cir, -1);

        string x, y;

        REP(i, 1, m)
        {
            cin >> x >> y;
            int a = GetIdx(x);
            int b = GetIdx(y);

            adj[a][b] = 1;
        }

        REP(k, 0, n-1)
            REP(i, 0, n-1)
                REP(j, 0, n-1)
                    if(adj[i][k] && adj[k][j])
                        adj[i][j] = 1;

        int cnt = 1;

        REP(i, 0, n-1)
        {
            if(cir[i] == -1)
            {
                cir[i] = cnt;
                REP(j, i+1, n-1)
                    if(adj[i][j] && adj[j][i])
                        cir[j] = cnt;
                cnt++;
            }
        }

        REP(i, 1, cnt-1)
        {
            bool flag = false;
            REP(j, 0, n-1)
            {
                if(cir[j] == i)
                {
                    if(flag)
                        printf(", ");
                    cout << idx[j];
                    flag = true;
                }
            }
            puts("");
        }
    }

	return 0;
}