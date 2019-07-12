#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	double L;
	while(scanf("%lf",&L))
    {
        long long rp = L,rq = 1;
        while(L != (long long)L){
            L *= 10;
            rp = (long long)L;
            rq *= 10;
        }
        long long tmp = __gcd(rp, rq);
        rp /= tmp;
        rq /= tmp;
        printf("%lld/%lld\n",rp,rq);
    }
	return 0;
}
6
5 9 2 4 3 1
4
2 3 1 4
0