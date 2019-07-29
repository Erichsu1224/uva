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
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn

//structure
struct Item
{
    float x1, x2, y1, y2;
};
//declaration

//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    char type;
    float a, b, c, d;
    vector<Item> v;

    while(cin >> type)
    {
        if(type == '*')
            break;

        cin >> a >> b >> c >> d;

        if(a > c)   swap(a, c);
        if(b > d)   swap(b, d);

        v.PB((Item){a, c, b, d});
    }

    float x, y;
    float endx = 9999.9, endy = 9999.9;
    int counter = 1;
    while(cin >> x >> y)
    {
        bool found = false;
        if(x == endx && y == endy)
        {
            break;
        }

        for(int i = 0; i < v.size(); i++)
        {
            if(v[i].x1 < x && x < v[i].x2 && v[i].y1 < y && y < v[i].y2)
            {
                printf("Point %d is contained in figure %d\n", counter, i+1);
                found = true;
            }
        }

        if(!found)
            printf("Point %d is not contained in any figure\n", counter);
        counter++;
    }

	return 0;
}