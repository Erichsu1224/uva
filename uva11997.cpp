#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define max 750

struct Item
{
	int sum, b;

	Item(int sum, int b) : sum(sum), b(b) {}

	bool operator <(const Item &r) const
	{
		return sum > r.sum;
	}
};

void merge(int *A, int *B, int k)
{
	priority_queue <Item> q;

	for(int i = 0; i < k; i++)
	{
		q.push(Item(A[i]+B[0], 0));
	}

	for(int i = 0; i < k; i++)
	{
		Item item = q.top();
		A[i] = item.sum;
		int b = item.b;
		q.pop();
		if(b+1<k) q.push(Item(item.sum-B[b]+B[b+1], b+1));
	}
}

int main(void)
{
	int k, first = 1;
	int A[max];
	int B[max];

	while(scanf("%d", &k) != EOF)
	{
		for(int j = 1; j < k; j++)
		{
			if(first)
			{
				for(int i = 0; i < k; i++)
					scanf("%d", &A[i]);
				sort(A, A+k);
				first = 0;
			}
			
			for(int i = 0; i < k; i++)
				scanf("%d", &B[i]);
			sort(B, B+k);

			merge(A, B, k);
		}
		cout << A[0];
		for(int i = 1; i < k; i++)
			printf(" %d", A[i]);
		printf("\n");
		first = 1;
	}
	return 0;
}