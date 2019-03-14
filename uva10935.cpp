#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define ll long long
#define C cases
#define pb push_back


int main(void)
{
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int number;

	while(~scanf("%d", &number) && number != 0)
	{
		queue<int> q;
		int counter = 0;

		for(int i = 1; i <= number; i++)
		{
			q.push(i);
		}

		printf("Discarded cards:");

		while(q.size() != 1)
		{
			if(counter == 0)
			{
				printf(" %d", q.front());
				counter++;
			}
			else
				printf(", %d", q.front());
			q.pop();
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}

		printf("\n");
		printf("Remaining card: %d\n", q.front());
	}

	return 0;
}