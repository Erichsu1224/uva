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

    int num1, num2;

    while(~scanf("%d %d", &num1, &num2))
    {
        if(num1 == 0 && num2 == 0)
            break;
        char str1[15] = {'0'};
        char str2[15] = {'0'};
        int len1 = 0, len2 = 0;

        for(int i = 0; num1 >= 1; i++)
        {
            str1[i] = char(num1%10)+'0';
            len1++;
            num1 /= 10;
        }

        for(int i = 0; num2 >= 1; i++)
        {
            str2[i] = char(num2%10)+'0';
            len2++;
            num2 /= 10;
        }

        int bits = 0;
        int bit = 0;

        //cout << len1 << ' ' << len2 << endl;

        for(int i = 0; i < max(len1, len2); i++)
        {
            int tmp1;
            int tmp2;

            if(i >= len1)   tmp1 = 0;
            else tmp1 = str1[i]-'0';

            if(i >= len2)   tmp2 = 0;
            else    tmp2 = str2[i]-'0';

            if(tmp1+tmp2+bit >= 10)
            {
                bit = 1;
                bits++;
            }
            else bit = 0;
        }

        if(bits == 0)
            printf("No carry operation.\n");
        else if(bits == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", bits);
    }

    return 0;
}