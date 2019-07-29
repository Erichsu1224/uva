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
    char t;
    float x1, x2, y1, y2;

    Item(char t, float x1, float x2, float y1, float y2): t(t), x1(x1), x2(x2), y1(y1), y2(y2){}
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

        if(type == 'r')
        {
            cin >> a >> b >> c >> d;

            if(a > c)   swap(a, c);
            if(b > d)   swap(b, d);

            v.PB(Item(type, a, c, b, d));
        }
        
        if(type == 'c')
        {
            cin >> a >> b >> c;

            v.PB(Item(type, a, c, b, 0));
        }
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
            if(v[i].t == 'r')
            {
                if(v[i].x1 < x && x < v[i].x2 && v[i].y1 < y && y < v[i].y2)
                {
                    printf("Point %d is contained in figure %d\n", counter, i+1);
                    found = true;
                }
            }
            
            if(v[i].t == 'c')
            {
                if(sqrt((x-v[i].x1)*(x-v[i].x1)+(y-v[i].y1)*(y-v[i].y1)) < v[i].x2)
                {
                    printf("Point %d is contained in figure %d\n", counter, i+1);
                    found = true;
                }
            }
        }

        if(!found)
            printf("Point %d is not contained in any figure\n", counter);
        counter++;
    }

	return 0;
}