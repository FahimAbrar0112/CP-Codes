#include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int n)
{

    // O( sq root N)
    vector<int> prime_factors;
    for (int i = 2; i * i <= n; i++)
    {

        while (n % i == 0)
        {
            prime_factors.push_back(i);
            n /= i;
        }
        if (n == 1)
            break;
    }
    if (n > 1)
        prime_factors.push_back(n);
    return prime_factors;
}
//  We can calculate divisors in log N using sieve . watch sieve folder divisor_store.cpp.

int main(void)
{
}