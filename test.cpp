#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    int T, cases = 0;
    string str;
    string a;
    string b;
    
    scanf("%d", &T);
    
    while(T--)
    {
        bool flag = false;
        a = ""; b = "";
        cin >> str;
        
        for(auto i : str)
        {
            if(i == '4')
            {
                a += '1';
                b += '3';
                flag = true;
            }
            
            else
            {
                a += i;
                if(flag)
                    b += '0';
            }
        }
        
        printf("Case #%d: ", cases++);
        cout << a << ' ' << b << '\n';
    }
    return 0;
}