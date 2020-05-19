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
#define maxn 200+5
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int cases;
double x, y;
string str;
map<pair<double, double>, int> mp;
vector<pair<double, double>> v;
int e[maxn][maxn];
double dis[maxn];
//functions
void dijk(int cur) // dijk(起點)
{ 
  int d;
  priority_queue<PII,vector<PII>,greater<PII>> q; // 放 (距離, 點編號)，每次會拿距離最小的點出來
  q.push( MP(0, cur) );
    
  while (!q.empty()) 
  {
    tie(d, cur) = q.top();
    q.pop();
    if (dis[cur] != 1e9) 
        continue; // 如果之前就拜訪過，無視

    dis[cur] = d;

    for(int i = 0; i < v.size(); i++)
        if (dis[i] == 1e9) 
        {
            q.push( MP((int)(d+e[cur][i]), i) );
        }
    }
}

void init(void)
{
    fill(dis, dis+maxn, 1e9);

    v.clear();
    mp.clear();
    MSET(e, 0);
}

double getdis(pair<double, double> a, pair<double, double> b)
{
    return sqrt((a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S));
}

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

    cin >> cases;

    while(cases--)
    {
        init();
        cin >> x >> y;
        v.EB(MP(x, y));
        cin >> x >> y;
        v.EB(MP(x, y));

        cin.ignore(100, '\n');

        while(getline(cin, str))
        {
            if(str == "")
                break;
            stringstream ss(str);
            ss >> x >> y;
            v.EB(MP(x, y));

            while(ss >> x >> y) {
                if(x < 0)    break;
                v.EB(MP(x, y));
                e[v.size()-2][v.size()-1] = getdis(v[v.size()-2], v.back());
                e[v.size()-1][v.size()-2] = e[v.size()-2][v.size()-1];
            }
        }

        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < v.size(); j++)
            {
                if(!e[i][j])
                    e[i][j] = getdis(v[i], v[j])*4;
            }
        }

        dijk(0);
        

        cout << (int)(dis[1]*6/4000+0.5) << "\n";
        if(cases)
            cout << '\n';
    }

    

	return 0;
}