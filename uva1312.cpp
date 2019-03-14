// dynamic programing 
//complexity O(n)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define maxn 10100

bool map[maxn][maxn];

int main(void)
{
	//file
	freopen(1312.in, "r", stdin);
	freopen(1312.out, "w", stdout);

	int cases;

	scanf("%d", &cases);

	while(cases--)
	{
		int N, W, H;

		scanf("%d %d %d", &N, &W, &H);

		memset(map, false, sizeof(map));

		for(int i = 0; i < N; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);

			map[x][y] = true;
		}

		int upper_line, lower_line;

		for(int i = 0; i <= H; i++)
		{
			upper_line = i;

			for(int j = 0; j < )
		}

	}
	return 0;
}
/*
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 10100
#define maxm 2000

bool graph[maxn][maxn];
int dp[maxn][maxn];
int N, W, H;

int min(int a, int b, int c)
{
	int hold = min(a, b);
	return min(hold, c);
}

int largest_empty_square(void)
{
    int a = 0;

    for(int i = 0; i <= W; i++)
    {
    	dp[i][0] = 1;
    }
    for(int i = 0; i <= H; i++)
    {
    	dp[0][i] = 1;
    }
 
    for (int i=1; i<=W; i++)
        for (int j=1; j<=H; j++)
        {
            if (graph[i][j])
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
 
            if (dp[i][j] > a) // 記錄最大值
                a = dp[i][j];
        }

    //test
    for(int i = 0; i <= W; i++)
    {
    	for(int j = 0; j <= H; j++)
    	{
    		cout << graph[i][j] << ' ';
    	}
    	cout << endl;
    }

    cout << endl << endl;

    for(int i = 0; i <= W; i++)
    {
    	for(int j = 0; j <= H; j++)
    	{
    		cout << dp[i][j] << ' ';
    	}
    	cout << endl;
    }
 
    return a;
}

int main(void)
{
	int cases;

	cin >> cases;

	while(cases--)
	{
		memset(graph, false, sizeof(graph));
		memset(dp, 0, sizeof(dp));
		cin >> N >> W >> H;
		for(int i = 0; i < N; i++)
		{
			int X, Y;
			cin >> X >> Y;
			graph[X][Y] = true;
		}

		cout << largest_empty_square() << endl;
	}
	return 0;
}
*/
