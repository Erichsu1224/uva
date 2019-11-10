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
#define maxn

//structure

//declaration
int T, cnt;
bool check_c[10];
bool check_crx1[20];
bool check_crx2[20];
int table[10][10];
int tmp_q[10];
int que[10000][10];
//functions

void dfs(int row)
{
    if(row == 9)
    {
        REP(j, 1, 8)
        {
            que[cnt][j] = tmp_q[j];
        }
        cnt++;
    }

    else
    {
        REP(i, 1, 8)
        {
            if(!check_c[i] && !check_crx1[row+i] && !check_crx2[row-i+8])
            {

                check_c[i] = check_crx1[row+i] = check_crx2[row-i+8] = true;
                tmp_q[row] = i;
                dfs(row+1);
                check_c[i] = check_crx1[row+i] = check_crx2[row-i+8] = false;
            }
        }
    }
    
}

void make_queen(void)
{
    cnt = 0;
    MSET(check_c, false);
    MSET(check_crx1, false);
    MSET(check_crx2, false);
    
    dfs(1);
}


int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    make_queen();

    scanf("%d", &T);

    while(T--)
    {
        REP(i, 1, 8)
        {
            REP(j, 1, 8)
            {
                scanf("%d", &table[i][j]);
            }
        }

        int ans = 0;

        REP(i, 0, cnt-1)
        {
            int tmp = 0;
            REP(j, 1, 8)
            {
                tmp += table[j][que[i][j]];
            }
            ans = max(ans, tmp);
        }

        printf("%5d\n", ans);
    }

	return 0;
}