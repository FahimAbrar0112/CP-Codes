#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    getline(cin, a);

    int n = a.size();

    int i;

    for (i = 0; i < n; i++)
    {
        char x = a[i];
        if (a[i] == ' ')
        {
            cout << endl;
        }
        else
        {
            cout << (char)(x - 'a' + 'A');
        }
    }
}
