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
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn

//structure

//declaration
int T, n, first;
int maxd;
vector<int> tran;
vector<int> v;
vector<int> lis;
vector<int> lds;

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
        cin >> n;
        tran.clear();
        maxd = 0;

        if(!n)
        {
            cout << 0 << '\n';
            continue;
        }

        for(int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            tran.PB(tmp);
        }

        for(int j = 0; j < n; j++)
        {
            v.clear();
            lis.clear();
            lds.clear();

            for(int i = j; i < n; i++)
            {
                int tmp = tran[i];

                if(i == j)
                {
                    first = tmp;
                }

                else
                {
                    if(tmp > first)
                    {
                        if(lis.size()==0||tmp>lis.back())
                            lis.push_back(tmp);
                        else
                            *lower_bound(lis.begin(),lis.end(),tmp)=tmp;
                    }

                    else if(tmp < first)
                    {
                        v.PB(tmp);
                    }
                }
            }

            for(int i = v.size()-1; i >= 0; i--)
            {
                if(lds.size()==0 || v[i] > lds.back())
                    lds.PB(v[i]);
                else
                    *lower_bound(lds.begin(), lds.end(), v[i]) = v[i];
            }

            if(lis.size()+lds.size()+1 > maxd)
                maxd = lis.size()+lds.size()+1;
        }

        cout << maxd << '\n';
    }

	return 0;
}