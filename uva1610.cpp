#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define max 1000
string cst[max];

int main(void)
{
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif
	
	int n;

	while(scanf("%d", &n))
	{
		if(n == 0)	break;
		for(int i = 0; i < n; i++)
		{
			cin >> cst[i];
		}

		sort(cst, cst+n);
	
		//n/2-1 n/2
		for(int i = 0; i < cst[n-1].size(); i++)
		{	
			//cout << cst[n/2-1][i] << " " << cst[n][i] << endl;
			
			if((int)cst[n/2-1][i] < (int)cst[n/2][i])
			{
				for(int j = 0; j <= i; j++)
				{
					if(j == i)	cout << (char)((int)(cst[n/2-1][j])+1);
					else	cout << cst[n/2-1][j];
				}
				cout << endl;
				break;
			}
		}
		
	}
	return 0;
}