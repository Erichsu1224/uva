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
#define maxn 109*2+1

int map[maxn][maxn];

struct Item
{
	int node, num;

	Item()
	{
		num = 0;
	}

	bool operator < (const Item& rs) const
	{
		return num > rs.num;
	}
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    #ifndef file
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    #endif

    int n, k = 1;

    while(~scanf("%d", &n) && n != 0)
    {
    	Item s_x[maxn];
    	Item s_y[maxn];
    	int x1, x2, y1, y2, total = 0;

    	memset(map, 0, sizeof(map));
    	

    	for(int i = 0; i < n; i++)
    	{
    		int x, y;
    		scanf("%d %d", &x, &y);
    		map[x+109][y+109] = 1;
    		s_x[x+109].node = x;
    		s_x[x+109].num += 1;
    		s_y[y+109].node = y;
    		s_y[x+109].num += 1;
    	}
/*
    	for(int i = 0; i < maxn; i++)
    	{
    		cout << s_x[i].num << ' ';
    	}
    	cout << endl;

    	for(int i = 0; i < maxn; i++)
    	{
    		cout << s_y[i].num << ' ';
    	}
    	cout << endl;
*/
    	sort(s_x , s_x+maxn);
    	sort(s_y, s_y+maxn);


    	//cout << s_x[0].num << ' ' << s_x[1].num << endl;
    	//cout << s_y[0].num << ' ' << s_y[1].num << endl;



    	x1 = s_x[0].num;
    	x2 = s_x[1].num;
    	y1 = s_y[0].num;
    	y2 = s_y[1].num;

    	total = x1+x2+y1+y2;

    	if(map[x1][y1] == 1)	total--;
    	if(map[x1][y2] == 1)	total--;
    	if(map[x2][y1] == 1)	total--;
    	if(map[x2][y2] == 1)	total--;

    	printf("Case %d: %d\n", k++, total);
    }



    return 0;
}