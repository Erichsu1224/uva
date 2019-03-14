//TLE
//Complexity O(2^2n)

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define pb push_back
#define maxn 3005

int A[maxn];
int B[maxn];
int tmp_a[maxn];
int tmp_b[maxn];

int main(void)
{
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif

	int n;


	while(~scanf("%d", &n) && n != 0)
	{
		int counter = 0;

		for(int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		for(int i = 0; i < n; i++)
			scanf("%d", &B[i]);

		for(int i = 2; i <= n; i++)
		{
			for(int k = 0; k <= n-i; k++)
			{
				for(int l = 0; l < i; l++)
				{
					tmp_a[l] = A[k+l];
				}
				for(int k = 0; k <= n-i; k++)
				{
					for(int l = 0; l < i; l++)
					{
						tmp_b[l] = B[k+l];
					}
					sort(tmp_a, tmp_a+i);
					sort(tmp_b, tmp_b+i);

					bool check = true;

					for(int l = 0; l < i; l++)
					{
						if(tmp_a[l] != tmp_b[l])
						{
							check = false;
							break;
						}
					}

					if(check)
						counter++;
				}
			}
		}

		printf("%d\n", counter);
	}

	return 0;
}