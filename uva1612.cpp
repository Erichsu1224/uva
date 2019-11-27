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
#define maxn 16384+5


//structure
struct Score
{
    double s[10];

    Score(){};
} s[maxn];
//declaration
int n;
int ranking[maxn];
int cases;

//functions


int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif
    cases = 1;

    while(~scanf("%d", &n) && n)
    {
        printf("Case %d: ", cases++);

        REP(i, 1, n)
        {
            double a, b, c;
            scanf("%lf %lf %lf", &a, &b, &c);

            a = round(a*100);
            b = round(b*100);
            c = round(c*100);

            s[i].s[0] = 0.0;
            s[i].s[1] = a;
            s[i].s[2] = b;
            s[i].s[3] = c;
            s[i].s[4] = a+b;
            s[i].s[5] = a+c;
            s[i].s[6] = b+c;
            s[i].s[7] = a+b+c;

            sort(s[i].s, s[i].s+8);

            REP(j, 0, 7)
            {
                s[i].s[j] /= 100;
            }
        }

        REP(i, 1, n)
            scanf("%d", &ranking[i]);

        

        int id = ranking[1];
        double total = s[id].s[7];

        bool flag = true;

        REP(i, 2, n)
        {
            int hold = ranking[i];
            flag = false;

            double tmp;

            if(hold > id)
            {
                REP(j, 0, 7)
                {
                    if(s[hold].s[j] <= total)
                    {
                        tmp = s[hold].s[j];
                        flag = true;
                    }

                    else
                    {
                        break;
                    }
                }
            }

            else
            {
                REP(j, 0, 7)
                {
                    
                    if(s[hold].s[j] < total)
                    {  
                        tmp = s[hold].s[j];
                        flag = true;
                    }

                    else
                        break;
                }
            }

            if(flag == false)
                break;

            total = tmp;
            id = hold;
        }

        if(!flag || total == 0)
            printf("No solution\n");
        else
            printf("%.2lf\n", total);
        
    }

	return 0;
}