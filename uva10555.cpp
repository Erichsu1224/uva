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
#define maxn

//structure

//declaration
string str;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(getline(cin, str))
    {
        // if(str.size() == 1)
        // {
        //     cout << "IN1\n";
        //     break;
        // }
            
        if(str == "0")
        {
            // cout << "IN2\n";
            break;
        }
            
        string num = "";

        for(int i = 2; i < str.size(); i++)
        {
            if(str[i] == '.')
                break;
            num += str[i];
        }

        int m = 0, n = 0;
        int hold = 1;
        int ans_m = 1e9, ans_n;

        for(int i = 0; i < num.size(); i++)
        {
            m = 0;
            hold = 1;
            for(int j = 0; j < num.size(); j++)
            {
                m *= 10;
                if(num.size()-i > j)
                {
                    hold *= 10;
                    m += 9;
                } 
            }

            n = stoi(num)-(stoi(num)/hold);

            int gcd = __gcd(n, m);
            if(m/gcd < ans_m)
            {
                ans_m = m/gcd;
                ans_n = n/gcd;
            }

        }

        printf("%d/%d\n", ans_n, ans_m);
    }

	return 0;
}