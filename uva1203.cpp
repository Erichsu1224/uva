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

vector< PP > v;
//structure
struct Item
{
    int num, time;

    Item(int num, int time): num(num), time(time){}

    bool operator<(const Item& rs)const{
        if(time == rs.time)
            return v[num].first > v[rs.num].first;
        return time > rs.time; 
    }
};

//declaration

int n, c, w;
string type;
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif
    
    while(cin >> type)
    {
        if(type[0] == '#')
        {
            priority_queue<Item> Q;
            int now = 0;
            int counter = 0;
            cin >> n;
            
            for(int i = 0; i < v.size(); i++)
            {
                Q.push(Item(i, v[i].second));
            }

            
            while(counter < n && !Q.empty())
            {
                cout << v[Q.top().num].first << '\n';
                Q.push(Item(Q.top().num, v[Q.top().num].second+Q.top().time));
                Q.pop();
                counter++;
            }
            

            v.clear();
        }
        cin >> c >> w;

        v.PB(make_pair(c, w));
    }

	return 0;
}