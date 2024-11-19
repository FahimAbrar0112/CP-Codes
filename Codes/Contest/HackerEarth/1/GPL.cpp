#include <bits/stdc++.h>
using namespace std;

long long int power(int x, int y)
{
    long long int result = 1;
    for (int i = 0; i < y; i++)
    {
        result *= x;
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        string s;
        cin >> s;
        reverse(s.begin(), s.end());

        long long int result = 0;
        for (int i = 0; i < n; i++)
        {
            result += (s[i] - '0') * power(2, i);
        }
        cout << result << endl;
    }
}