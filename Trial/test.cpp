#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

double eqn(double x)
{
    return pow(x, 2) - 5 * x + 6;
}

int main(void)
{

    double lo = 2.5, hi = 200, mid;
    double ans;
    while (hi - lo > eps)
    {
        ans = mid = (lo + hi) / 2;

        if (eqn(mid) == 0)
        {
            break;
        }
        else if (eqn(lo) * eqn(mid) < 0)
            hi = mid;

        else
            lo = mid;
    }

    cout << ans << endl;
}