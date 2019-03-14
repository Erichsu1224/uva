#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define max 4000
int A[max];
int B[max];
int C[max];
int D[max];
int sums[max*max];


//using standard library binary search
//complexity O(n^2log(n))
int main(void)
{
	int testcases;

	cin >> testcases;

	while(testcases--)
	{
		int n;

		cin >> n;

		for(int i = 0; i < n; i++)
		{
			cin >> A[i] >> B[i] >> C[i] >> D[i];
		}

		int c = 0;

		for(int i = 0; i < n; i++)
		{
			for(int k = 0; k < n; k++)
			{
				sums[c++] = A[i] + B[k];
			}
		}

		sort(sums, sums+c);

		int total = 0;

		for(int i = 0; i < n; i++)
		{
			for(int k = 0; k < n; k++)
			{
				total += upper_bound(sums, sums+c, -(C[i]+D[k])) - lower_bound(sums, sums+c, -(C[i]+D[k]));
			}
		}

		cout << total << endl;
	}

	return 0;
}