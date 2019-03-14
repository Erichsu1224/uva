#include <stdio.h>

void swap(int *a, int *b, int *c);

int main(void)
{
	int time;
	scanf("%d", &time);
	while(time--)
	{
		int lenth, timer = 0;
		scanf("%d", &lenth);
		int train[lenth];
		for(int i = 0; i < lenth; i++)
		{
			scanf("%d", &train[i]);
		}
		for(int i = 0; i < lenth; i++)
		{
			for(int n = 0; n < lenth-1; n++)
			{
				if(train[n] > train[n+1])
					swap(&train[n], &train[n+1], &timer);
			}
		}
		printf("Optimal train swapping takes %d swaps.\n", timer);
	}
	return 0;
}

void swap(int *a, int *b, int *c)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	*c = *c + 1;
}

/*example
#include <stdio.h>

int main()
{
	int n, l, i, k, tr[100], t, count;
	scanf("%d", &n);
	while(n--) {
		for(i = 0; i < 100; i++)
			tr[i] = 0;
		count = 0;
		scanf("%d", &l);
		for(i = 0; i < l; i++)
			scanf("%d", &tr[i]);
		for(i = 0; i < l - 1; i++)
			for(k = 0; k < l - 1; k++)
				if(tr[k]>tr[k+1])
				{
					t = tr[k];
					tr[k] = tr[k + 1];
					tr[k + 1] = t;
					count++;
				}
		printf("Optimal train swapping takes %d swaps.\n",count);
	}

	return 0;
}
*/