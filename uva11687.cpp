#include <iostream>
using namespace std;

int main(void)
{
    string in;
    
    while(cin >> in)
    {
        int counter = 1;
        if(in[0] == 'E')
            break;
        int num = in.size();

        
        if(num == 1)
        {
            if(in[0] == '1')
            {
                cout << 1 << '\n';
                continue;
            }

            cout << 2 << '\n';
            continue;
        }

        while(num > 1)
        {
            int digit = 0;

            while(num >= 1)
            {
                digit++;
                num /= 10;
            }

            num = digit;
            counter++;
        }

        cout << counter+1 << '\n';
    }
    return 0;
}