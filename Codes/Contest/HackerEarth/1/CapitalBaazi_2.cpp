#include <bits/stdc++.h>
using namespace std;

void cap(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }

    cout << s << endl;
}

int main()
{

    while (1)
    {
        string s;
        cin >> s;
        if (s.size() == 0)
        {
            cout << "Empty:" << s.size() << endl;
            break;
        }
        cap(s);
    }
}