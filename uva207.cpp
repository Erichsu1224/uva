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
#define maxn 150

//structure
struct Player
{
    string name;
    int cnt;
    int score[4];
    int total;

    bool operator< (const Player& rs) const{
        if(cnt == rs.cnt)
        {
            if(total == rs.total)

            return total < rs.total;
        }
        return cnt > rs.cnt;
    }
};
//declaration
int T;
int n;
double total_price;
vector<double> price;
Player player[maxn];
//functions
bool check(string a)
{
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == '*')
            return false;
    }
    return true;
}
int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    cin >> T;

    while(T--)
    {
        double x;
        string str;
        price.clear();

        getchar();

        cin >> total_price;
        cout << total_price << endl;

        REP(i, 1, 70)
        {
            cin >> x;
            price.EB(x);
        }

        cout << "test\n";
        cin >> n;
        cout << n << endl;
        getchar();
        REP(i, 1, n)
        {
            string nn;
            int a1 = -1, a2 = -1, a3 = -1, a4 = -1, cnt = 0;
            string tmp = "";
            getline(cin, str);

            for(int j = 0; j < str.size(); j++)
            {
                tmp += str[j];

                if(j == 19)
                {
                    nn = tmp;
                    tmp = "";
                }

                else if(j == 23)
                {
                    if(tmp == "DQ")
                    {
                        break;
                    }
                    else
                        a1 = stoi(tmp);
                    tmp = "";
                    cnt++;
                }
                
                else if(j == 26)
                {
                    if(tmp == "DQ")
                    {
                        break;
                    }
                    else
                        a2 = stoi(tmp);
                    tmp = "";
                    cnt++;
                }

                else if(j == 29)
                {
                    if(tmp == "DQ")
                    {
                        break;
                    }
                    else
                        a3 = stoi(tmp);
                    tmp = "";
                    cnt++;
                }

                else if(j == 32)
                {
                    if(tmp == "DQ")
                    {
                        break;
                    }
                    else
                        a4 = stoi(tmp);
                    tmp = "";
                    cnt++;
                }
            }

            player[i] = (Player){nn, cnt, a1, a2, a3, a4, a1+a2+a3+a4};
        }

        sort(player+1, player+1+n);

        cout << "Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n";
        cout << "-----------------------------------------------------------------------\n";

        int cnt = 1;

        REP(i, 1, n)
        {
            if(!check(player[i].name))
                continue
        }

        
        REP(i, 1, n)
        {
            cout << player[i].name << ' ' << player[i].total << endl;
        }
    }

	return 0;
}