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
    /*
               Example Cases:

                Consider n = 17. It's prime, and since i * i only goes up to 4 (since 4 * 4 = 16), the loop never runs. Without the if (n > 1) check, the function would return an empty list.
                Consider n = 77:
                The loop finds divisors 7 and 11, reducing n to 1. The final check ensures no missed prime factors.
                Conclusion:
                Removing if (n > 1) would make the function incorrect for prime numbers and remaining factors after the loop. It should not be removed.

    */
}

vector<int> divisors2(int n)
{

    // O(N)
    vector<int> prime_factors;
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            prime_factors.push_back(i);
            n /= i;
        }
    }
    return prime_factors;

    /*
            No need of if (n > 1)
            prime_factors.push_back(n);
    */
}

int main(void)
{

    // for(int i=1;i<=100;i++)
    // {
    //     cout<<i<<" "<<isPrime(i)<<endl;
    // }

    int n;
    cin >> n;
    vector<int> prime_factors = divisors(n);

    for (int val : prime_factors)
    {
        cout << val << endl;
    }

    /// cout<<isPrime(1e9+5)<<endl;
    return 0;
}