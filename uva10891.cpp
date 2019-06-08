#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>
#define maxn 100+5

int S[maxn], A[maxn], d[maxn][maxn], visited[maxn][maxn], n;

int dp(int i, int j)
{
    if(visited[i][j])
        return d[i][j];

    d[i][j] = 1;
    int m = 0;
    
    for(int k = i+1; k <= j; k++)
        m = min(m, dp(k, j));
    for(int k = i; k < j; k++)
        m = min(m, dp(i,k));
    
    d[i][j] = S[j]-S[i-1] -m;
    
    return d[i][j];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    while(cin >> n && n)
    {
        S[0] = 0;

        for(int i = 1; i <=n; i++)
        {
            cin >> A[i] ;
            S[i] = S[i-1]+A[i]; //prefix
        }

        memset(visited, 0, sizeof(visited));
        printf("%d\n", 2*dp(1,n)-S[n]);
    }

	return 0;
}