#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
using namespace std;

#define ll long long
#define PB push_back
#define PP pair<int, int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
#define maxn

//structure

//declaration
vector<int> num;
vector<int> lis;
vector<int> pos;
stack<int> S;
//functions

int main(void)
{
	IOS;
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int tmp;

	while(cin >> tmp)
	{
		num.PB(tmp);
		if(lis.size()==0||tmp>lis.back())
		{
			lis.push_back(tmp);
			pos.PB(lis.size());
		}
    		
		else
		{
			pos.PB(lower_bound(lis.begin(),lis.end(),tmp)-lis.begin()+1);
			*lower_bound(lis.begin(),lis.end(),tmp)=tmp;
		}
    		
	}
	//test
	

	cout << lis.size() << '\n';
	cout << "-\n";
	
	int now = lis.size();
	for(int i = pos.size(); i >= 0; i--)
	{
		if(pos[i] == now)	
		{
			S.push(i);
			now--;
		}
	}

	while(!S.empty())
	{
		cout << num[S.top()] << '\n';
		S.pop();
	}
	
	return 0;
}
