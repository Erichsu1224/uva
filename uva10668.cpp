#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define ll long long
#define C cases
#define PB push_back
#define PP pair<int, int>



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif
	
	double L,n,C,R;
	while (~scanf("%lf%lf%lf",&L,&n,&C)) {
		if (L < 0 && n < 0 && C < 0)
			break;
		
		double S = (1+n*C)*L;
		double mid,l = 0.0,r = 0.5*L;
		while (r-l > 1e-6) {
			mid = (l+r)/2.0;
			R = (4*mid*mid+L*L)/8.0/mid;
			if (2*R*asin(L/R/2.0) < S)
				l = mid;
			else r = mid;
		}
		
		printf("%.3lf\n",mid); 
	}
	return 0;
}