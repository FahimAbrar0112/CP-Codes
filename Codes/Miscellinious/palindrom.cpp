#include <bits/stdc++.h>
using namespace std;

int arr[30];

int main(void)
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        arr[s[i] - 'a']++;
    }

    int odd = 0, even = 0;
    for (int i = 0; i < 26; i++)
    {
        if(arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    if(odd > 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

}