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
    int id, p;

    bool operator< (const Item& rs) const
    {
        return p < rs.p;
    }
};
//declaration
int T;
int n, m;
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

    cin >> T;

    while(T--)
    {
        priority_queue<Item> PQ;
        queue<Item> Q;
        int counter = 0;
        cin >> n >> m;

        for(int i = 0; i < n; i++)
        {
            int tmp;    cin >> tmp;
            Q.push((Item){i, tmp});
            PQ.push((Item){i, tmp});
        }

        while(!Q.empty())
        {
            Item tar = Q.front(); Q.pop();
            if(tar.p != PQ.top().p)
            {
                Q.push(tar);
            }

            else
            {
                PQ.pop();
                counter++;
                if(tar.id == m)
                {
                    break;
                }
            }
        }
        cout << counter << '\n';
    }

	return 0;
}