#include <bits/stdc++.h>
using namespace std;
//   https://www.spoj.com/problems/TWOSQRS/
int main(void)
{

    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        long long lo = 0, hi = sqrt(n), mid;

        while (hi - lo >= 1)
        {
            mid = lo * lo + hi * hi;
            if (mid == n)
                break;
            if (mid < n)
                lo++;
            else
                hi--;
        }

        if (lo * lo + hi * hi == n)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}