#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dfs

int main(void)
{
	int time;
	scanf("%d", &time);
	while(time--)
	{
		int n, k, counter = 0, counter2 = 2;
		scanf("%d %d", &n, &k);
		char drug_name[n][1000];
		int drug_fre[n];
		for(int i = 0; i < n; i++)
		{
			scanf("%s %d", drug_name[i], &drug_fre[i]);
		}


		int count = 0;

		while(counter < k)
		{
			count += 1;
			for(int i = 0; i < n; i++)
			{
				if(count % drug_fre[i] == 0 && counter < k)
				{
					printf("%d %s\n", count, drug_name[i]);
					counter++;
				}
			}	
		}
	}
	return 0;
}