#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double multiply(double x, int n)
    {
        double result = 1;
        for (int i = 1; i <= n; i++)
        {
            result *= x;
        }
        return result;
    }

    double myPow(double x, int n)
    {

        if (n < 0)
            return 1.0 / multiply(x, -n);
        return multiply(x, n);
    }
};
 