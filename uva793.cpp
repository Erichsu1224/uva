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
#define maxn 100000

//structure

//declaration
int T, n, a, b, AC, WA, cases;;
string str;
char type;
//functions

int arr[maxn];

void init() // give a initial length
{
	memset(arr, -1, sizeof(arr));
}

int find(int x)
{
	return arr[x] < 0 ? x : (arr[x] = find(arr[x]));
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if(x == y)
		return;

	if(arr[x] <= arr[y])
	{
		arr[x] += arr[y];
		arr[y] = x;
	}
	else
	{
		arr[y] += arr[x];
		arr[x] = y;
	}
}
int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    cin >> T;
    getchar();

    cases = 0;

    while(T--)
    {
        if(cases++)
            puts("");
        init();
        AC = WA = 0;
        cin >> n;
        getchar();
        while(getline(cin, str) && str != "")
        {
            // cout << str << endl;
            stringstream ss(str);
            ss >> type >> a >> b;

            if(type == 'c')
                Union(a, b);
            else
            {
                if(find(a) == find(b))
                    AC++;
                else
                    WA++;
            }
        }

        cout << AC << ',' << WA << '\n';
    }

	return 0;
}