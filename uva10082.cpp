#include <iostream>
#include <map>
using namespace std;

map<char, char> m;

int main(void)
{
    string code = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    for(int i = 0; i < code.size(); i++)
    {
        if(code[i] == '`' || code[i] == 'A' || code[i] == 'Q' || code[i] == 'Z' )
        {
            m[code[i]] = code[i];
        }

        else
        {
            m[code[i]] = code[i-1];
        }
    }
    m[' '] = ' ';

    string str;

    while(getline(cin, str))
    {
        for(int i = 0; i < str.size(); i++)
        {
            cout << m[str[i]];
        }
        cout << '\n';
    }
    return 0;
}