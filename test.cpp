<<<<<<< HEAD
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
=======
#include<cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define N 101

inline int input();
int main()
{
    	#ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif
    int C, S, Q, Case = 0;
    int d[N][N];

    while (C = input())
    {
        S = input();
        Q = input();

        int i, j, k;
        //init
        for (i = 0; i <= C; i++)
            for (j = 0; j <= C; j++)
                d[i][j] = 1e9;

        for (i = 0; i < S; i++)
        {
            int  c1, c2, decibel;
            c1 = input(), c2 = input(), decibel = input();
            d[c1][c2] = d[c2][c1] = decibel;
        }

        //Floyd-Warshall
        for (k = 1; k <= C; k++)
            for (i = 1; i <= C; i++)
                for (j = 1; j <= C; j++)
                {
            int max = MAX(d[i][k], d[k][j]);//取最大的分貝
            if (max < d[i][j])
                d[j][i] = d[i][j] = max;
                }

        if (Case)
            putchar('\n');
        printf("Case #%d\n", ++Case);

        for (int i = 0; i < Q; i++)
        {
            int c1, c2;
            c1 = input(), c2 = input();
            
            if (d[c1][c2] != 1e9)
                printf("%d\n", d[c1][c2]);
            else
                puts("no path");
        }
    }

    return 0;
}
int input()
{
    int n = 0;
    char c;
    while ((c = getchar()) != ' '&&c != '\n')
        n = n * 10 + c - '0';
    return n;
}
>>>>>>> 307438b569d4a4d8efbcaaba9ee0e5f7eebf8868
