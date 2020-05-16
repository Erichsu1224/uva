#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PB push_back
#define PII pair<int, int>
#define MP make_pair
#define all(x) x.begin(), x.end()
#define REP(x, y, z) for(int x = (y); x <= (z); x++)
#define REPP(x, y, z) for(int x = (y); x >= (z); x--)
#define F first
#define S second
#define MSET(x, y) memset(x, y, sizeof(x)) 
#define EB emplace_back
#define maxn
#define IOS ios::sync_with_stdio(false); cin.tie(0);

//structure

//declaration
int n;
int x, y;
//functions

int main(void)
{
	#ifdef DBG
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	IOS;

	while(cin >> n)
	{
		stack<int> st;
		queue<int> q;
		priority_queue<int> pq;

		bool flag_st = true, flag_q = true, flag_pq = true;

		REP(i, 1, n)
		{
			cin >> x >> y;

			if(x == 1)
			{
				st.push(y);
				q.push(y);
				pq.push(y);
			}

			else
			{
                if(st.empty())
                {
                    flag_st = false;
                    continue;
                }
					
				if(q.empty())
				{
                    flag_st = false;
                    continue;
                }
				if(pq.empty())
				{
                    flag_st = false;
                    continue;
                }
                
				if(st.top() != y)
					flag_st = false;
				if(q.front() != y)
					flag_q = false;
				if(pq.top() != y)
					flag_pq = false;
				
				st.pop();
				q.pop();
				pq.pop();
			}
			
		}

		int cnt = 0;
		if(flag_st)
			cnt++;
		if(flag_q)
			cnt++;
		if(flag_pq)
			cnt++;

		if(cnt >= 2)
		{
			cout << "not sure\n";
			continue;
		}

		if(flag_st)
		{
			cout << "stack\n";
			continue;
		}
		if(flag_q)
		{
			cout << "queue\n";
			continue;
		}
		if(flag_pq)
		{
			cout << "priority queue\n";
			continue;
		}

		cout << "impossible\n";
	}

	return 0;
}