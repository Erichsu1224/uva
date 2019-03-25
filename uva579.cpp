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

    float H, M;

    while(~scanf("%f:%f", &H, &M))
    {
        if(H == 0 && M == 0)
            break;

        H = H*30+M/60*30;
        M = M*6;

        float angle1, angle2;
        angle1 = abs(H-M);
        angle2 = abs(360-angle1);

        printf("%.3f\n", min(angle1, angle2));
    }

    return 0;
}