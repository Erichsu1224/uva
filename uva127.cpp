#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = (y); x <= (z); x++)
#define REPP(x, y, z) for(int x = (y); x >= (z); x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration

//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

	string str;
    char c, cc;

    while(getline(cin, str))
    {
        if(str[0] == '#')   break;

        stack<pair<char, char>> ss[56];
        stringstream s1(str);

        REP(i, 1, 26)
        {
            s1 >> c >> cc;
            ss[i].push(MP(c, cc));
        }

        getline(cin, str);
        stringstream s2(str);

        REP(i, 27, 52)
        {
            s2 >> c >> cc;
            ss[i].push(MP(c, cc));
            // cout << c << ' ' << cc << endl;
        }

        REP(i, 1, 55)
        {
            if(ss[i].empty())
                continue;
            int cnt = 0;
            int j = 1;
            while(i-j >= 1)
            {
                if(!ss[i-j].empty())
                    cnt++;
                if (cnt == 3)
                    break;
                j++;
            }

            // cout << i-j << ' ' << i << endl;
            if(cnt == 3)
                if(!ss[i].empty() && (ss[i-j].top().F == ss[i].top().F || ss[i-j].top().S == ss[i].top().S))
                {
                    ss[i-j].push(ss[i].top());
                    ss[i].pop();

                    i = i-j-1;
                    continue;   
                }
            j = 1;
            cnt = 0;
            while(i-j >= 1)
            {
                if(!ss[i-j].empty())
                    cnt++;
                if (cnt == 1)
                    break;
                j++;
            }
            // cout << i-j << ' ' << i << endl;
            if(cnt == 1)
                if(!ss[i].empty() && (ss[i-j].top().F == ss[i].top().F || ss[i-j].top().S == ss[i].top().S))
                {
                    ss[i-j].push(ss[i].top());
                    ss[i].pop(); 
                    i = i-j-1;
                    continue;  
                }
        }

        vector<int> ans;

        REP(i, 1 ,52)
        {
            if(!ss[i].empty())
                ans.EB(ss[i].size());
        }

        if(ans.size() == 1)
        {
            cout << "1 pile remaining: " << ans[0] << '\n';
        }

        else
        {
            cout << ans.size() << " piles remaining:";
            for(auto i : ans)
                cout << ' ' << i;
            cout << '\n';
        }
    }

	return 0;
}