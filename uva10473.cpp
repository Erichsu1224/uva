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

	string str;

    while(getline(cin, str)){
        if(str[0] == '-')
            break;
        if(str.size() >= 2 && str[1] == 'x'){
            stringstream ss(str);
            int tmp;
            ss >> hex >> tmp;
            cout << tmp << '\n';
        }
        else
        {
            int tmp = stoi(str);
            printf("0x%X\n", tmp);
        }
        
    }

	return 0;
}