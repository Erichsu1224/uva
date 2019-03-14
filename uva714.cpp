#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <stddef.h>
using namespace std;

#define ll long long
#define C cases
#define pb push_back
#define maxn 505

int books[maxn];
int prefix[maxn];


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int C;

	scanf("%d", &C);

	while(C--)
	{
		int m, k, total = 0;
		memset(prefix, 0, sizeof(prefix));

		scanf("%d %d", &m, &k);

		for(int i = 0; i < m; i++)
		{
			scanf("%d", &books[i]);
			total += books[i];
		}

		total = total/k;

		prefix[m-1] = books[m-1];
		for(int i = m-2; i >= 0; i--)
		{
			prefix[i] += (books[i]+prefix[i+1]);
		}

		//test
		/*
		for(int i = 0; i < m; i++)
		{
			cout << prefix[i] << ' ';
		}
		cout << endl;
		*/
		//cout << total << endl;
		
		int middle = k;
		stack<int> st;

		for(int i = 1; i <= k; i++)
		{
			int left = 0, right = m;

			while(left <= right)
			{
				middle = (left+right)/2;
				//printf("%d %d %d\n", left, middle, right);
				if(prefix[middle] == total*i)
				{
					break;
				}
				else if(prefix[middle] < total*i)
				{
					right = middle-1;
				}
				else if(prefix[middle] > total*i)
				{
					left = middle+1;
				}
			}

			//printf("%d\n", left);
			st.push(left);

			/*
			if(abs(prefix[middle+1] - total*i) < abs(prefix[middle] - total*i))
				st.push(right);
			else
				st.push(right+1);
			*/
		}

		//test
		printf("%lu\n", st.size());

		while(!st.empty())
		{
			printf("%d ", st.top());
			st.pop();
		}
		printf("\n");
		
		/*
		int hold = 0;
		for(int i = 0; i < k; i++)
		{
			//printf("test:%d", hold);
			int tmp = st.top();
			st.pop();

			if(i != 0)
				printf("/ ");

			for(int l = hold; l < tmp; l++)
			{
				printf("%d ", books[l]);
			}

			hold = tmp;
		}

		for(int i = hold; i < m; i++)
		{
			if(i == hold)
				printf("%d", books[i]);
			else
				printf(" %d", books[i]);
		}

		printf("\n");
		*/
	}

	return 0;
}