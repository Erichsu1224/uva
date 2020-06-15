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

    while(cin >> str){
        if(str[0] == '0')
            break;
        
        map<string, int> mp;

        int cnt = 0;

        cout << "Original number was " << str << '\n';

        while(!mp[str]){
            mp[str] = 1;
            sort(all(str));

            string tmp = str;

            reverse(all(tmp));

            ll a = stoi(tmp);
            ll b = stoi(str);

            cout << a << " - " << b << " = " << a-b << '\n';

            str = to_string(a-b);
            cnt++;
        }

        cout << "Chain length " << cnt << "\n\n";


        
        
    }

	return 0;
}