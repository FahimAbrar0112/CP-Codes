#include <iostream>
#include <chrono> // For time measurement
#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

int gcd_(int a, int b)
{
    if (a % b == 0)
        return b;

    return gcd(b, a % b);
}

int lcm_(int a, int b)
{
    return (1ll * a * b) / __gcd(a, b);
}
int main()
{
    // Start measuring time
    auto start = high_resolution_clock::now();

    // for (int i = 1; i < 1e8; i++)
    {
        __gcd(12, __gcd(18, 20));
        // gcd(12, gcd(18, 20));
        // gcd_(12,gcd_(18,20));

        // lcm(12,18);

        // cout<<
    }

    cout << lcm(12, lcm(18, 20)) << endl;
    // Stop measuring time
    auto stop = high_resolution_clock::now();

    // Calculate duration
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;

    return 0;
}
