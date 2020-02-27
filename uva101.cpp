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
#define EB emplace_back
#define maxn 25+5

//structure

//declaration
vector<int> v[maxn];
int idx[maxn];
int n, a, b;
string str1;
string str2;

//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	while(~scanf("%d", &n))
	{
		//init
        REP(i, 0, n-1)
        {
            v[i].clear();
            v[i].EB(i);
            idx[i] = i;
        }

        while(cin >> str1)
        {
            // for(int i = 0; i < n; i++)
            // {
            //     printf("%d:", i);
            //     for(int j = 0; j < v[i].size(); j++)
            //         printf(" %d", v[i][j]);
            //     puts("");
            // }
            // printf("-----------\n");

            if(str1[0] == 'q')
                break;
            cin >> a >> str2 >> b;

            // cout << str1 << ' ' << a << ' ' << str2 << ' ' << b << endl;

            if(idx[a] == idx[b])
                continue;

            vector<int> mm;

            if(str2 == "onto")
            {
                for(int i = 0; i < v[idx[b]].size(); i++)
                {
                    if(v[idx[b]][i] == b)
                    {
                        for(int j = i+1; j < v[idx[b]].size(); j++)
                        {
                            v[v[idx[b]][j]].EB(v[idx[b]][j]);

                            idx[v[idx[b]][j]] = v[idx[b]][j];
                        }

                        v[idx[b]].resize(i+1);
                        break;
                    }
                }
            }

            if(str1 == "move")
            {
                for(int i = 0; i < v[idx[a]].size(); i++)
                {
                    if(v[idx[a]][i] == a)
                    {
                        for(int j = i+1; j < v[idx[a]].size(); j++)
                        {
                            v[v[idx[a]][j]].EB(v[idx[a]][j]);

                            idx[v[idx[a]][j]] = v[idx[a]][j];
                        }

                        v[idx[a]].resize(i+1);
                        break;
                    }
                }
            }

            int tmp = idx[a];
            for(int i = 0; i < v[tmp].size(); i++)
            {
                
                if(v[tmp][i] == a)
                {

                    for(int j = i; j < v[tmp].size(); j++)
                    {
                        v[idx[b]].EB(v[tmp][j]);
                        idx[v[tmp][j]] = idx[b];
                    }

                    
                    v[tmp].resize(i);

                    break;
                }
            }
            
        }

        for(int i = 0; i < n; i++)
        {
            printf("%d:", i);
            for(int j = 0; j < v[i].size(); j++)
                printf(" %d", v[i][j]);
            puts("");
        }
	}

	return 0;
}