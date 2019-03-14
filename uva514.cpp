//stack
//[]
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main(void)
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int train;

	while(~scanf("%d", &train) && train != 0)
	{
		stack<int> st;
		int order[train];
		int lis[train+5];

		for(int i = 0; i < train; i++)
		{
			lis[i] = i+1;
		}

		while(~scanf("%d", &order[0]))
		{
			if(order[0] == 0)
			{
				printf("\n");
				break;
			}
			for(int i = 1; i < train; i++)
				scanf("%d", &order[i]);

			bool fail = false;
			int k = 1;
			st.push(lis[0]);
			
			for(int i = 0; i < train; i++)
			{
				while(order[i] != st.top() )
				{
					if(k >= train)
					{
						fail = true;
						break;
					}
					st.push(lis[k++]);
				}
				if(fail)	
					break;
				st.pop();
				if(st.empty())
					st.push(lis[k++]);
			}
			
			if(!fail)	printf("Yes\n");
			if(fail)	printf("No\n");
		}

	}
	return 0;
}