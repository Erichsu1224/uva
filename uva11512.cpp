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
#define maxn 1000+5

//structure

//declaration
int T;
char str[maxn];
vector<string> v;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    scanf("%d", &T);

    while(T--)
    {
        v.clear();
        scanf("%s\n", str);

        REP(i, 0, (strlen(str)-1))
        {
            string tmp(str+i);
            v.EB(tmp);
        }

        sort(all(v));

        int cnt = 0;
        string ans;

        REP(i, 1, v.size()-1)
        {
            string tmp;
            REP(j, 0, min(v[i-1].size(), v[i].size())-1)
            {
                if(v[i][j] != v[i-1][j])
                    break;
                tmp += v[i][j];
            }

            if((cnt < tmp.size()) || (cnt == tmp.size() && tmp < ans))
            {
                cnt = tmp.size();
                ans = tmp; 
            }  
        }

        cnt = 0;

        for(int i = 0; i < strlen(str); i++)
        {
            if(str[i] == ans[0] && i+ans.size() <= strlen(str))
            {
                bool flag = true;
                for(int j = 0; j < ans.size() && i+j < strlen(str); j++)
                {
                    if(str[i+j] != ans[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    cnt++;
            }   
        }

        if(cnt == 0)
            printf("No repetitions found!\n");
        else
            cout << ans << ' ' << cnt << '\n';
    }


	return 0;
}