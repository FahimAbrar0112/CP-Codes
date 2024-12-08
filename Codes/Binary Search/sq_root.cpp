#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6; // 5 dig precision after decimal
// if want x dig precision then 1e-(x+1)

// COMPLEXITY:  p* log(N*(10^d)) 

double sq_Root(double x)
{
    double lo = 1, hi = x, mid;

    while (hi - lo > eps)
    {
        mid = (lo + hi) / 2;
        if (mid * mid < x)
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << " " << hi << endl;
    return lo;
}
double multiplier(double x, int n)
{
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
    {
        ans *= x;
    }
    return ans;
}

double Nth_Root(double x, int n)
{
    double lo = 1, hi = x, mid;

    while (hi - lo > eps)
    {
        mid = (lo + hi) / 2;
        if (multiplier(mid, n) < x)
        {
            lo = mid;
            // cout<<"lo: "<<lo<<endl;
        }
        else
        {
            hi = mid;
            // cout<<"hi: "<<hi<<endl;
        }
    }

    cout << lo << " " << hi << endl;
    return lo;
}

int main(void)
{
    cout << setprecision(10);

    //  sq_Root(2);
    // cout<<pow(2,1.0/2)<<endl;

    sq_Root(4);
    cout<<pow(4,1/2)<<endl;

    // Nth_Root(10, 3);
    // cout << pow(10, 1.0 / 3) << endl;




}