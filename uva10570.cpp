#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 510
#define maxm 10000

int alien[maxn];
int n;
int change_max;

void find(void)
{
	int tmp[maxn*2];
	for(int i = 0; i < n*2; i++) 
	{
		tmp[i] = alien[i%n]-1;
	}

	for(int i = 0; i < n; i++)
	{
		int table[n];
		int table_mark[n];
		for(int j = 0; j < n; j++)
		{
			table[j] = tmp[j+i];
			//table_mark[table[j]] = j; 
		}

		for(int j = 0; j < n; j++)
		{
			table_mark[table[j]] = j;
		}

		int counter = 0;

		for(int j = 0; j < n; j++)
		{
			/*//test
			for(int k = 0; k < n; k++)
			{
				cout << table_mark[k] << ' ';
			}

			cout << "mark" << endl;

			for(int k = 0; k < n; k++)
			{
				cout << table[k] << ' ';
			}
			cout << endl;
			*///end test

			if(table_mark[j] != j)
			{
				swap(table[j], table[table_mark[j]]);
				swap(table_mark[j], table_mark[table_mark[j]]);
				counter++;
			}
		}

		//test
		//cout << "-----------------------" << endl;
		//end test

		if(counter < change_max)	change_max = counter;
	}
}

int main(void)
{
	while(cin >> n)
	{
		if(n == 0)
			break;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &alien[i]);
		}

		change_max = 510;
		find();
		reverse(alien, alien+n);
		find();
		cout << change_max << endl;
	}
	return 0;
}