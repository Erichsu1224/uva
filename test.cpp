#include <bits/stdc++.h>
using namespace std;
#define maxn 21

int arr[maxn];

int main(void)
{
	int T;
	cin >> T;

	while(T--)
	{
		memset(arr, 0, sizeof(arr));
		int n, m;
		cin >> n >> m;

		for(int i = n-m; i < n; i++)
		{
			arr[i] = 1;
 		}

 		do
 		{
 			for(int i = 0; i < n; i++)
 			{
 				cout << arr[i];
 			}
 			cout << '\n';
 		}	while(next_permutation(arr, arr+n));

 		if(T)
 			printf("\n");
	}
	return 0;
}