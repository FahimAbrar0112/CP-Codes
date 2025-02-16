#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    double eps = 1e-5;

public:
    double mySqrt(double x)
    {
        double lo = 0, hi = max(1.0,(double)x), mid;

        while (hi - lo > eps)
        {
            mid = (lo + hi) / 2.0;

            if (mid * mid < x)
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }

        cout << lo << " " << hi << endl;
        return  (int)hi;
    }
};

int main(void)
{
    Solution S;
    double x= .5;
    cout << S.mySqrt(x)<<endl;
    cout<<pow(x,.5)<<endl;
}
