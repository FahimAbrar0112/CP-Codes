#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + +7;

/*
    Say, a <= 10^18   or very big like 5^1024
         b <= 10^9
         M <= 10^9
    if a is very big   ,
     take a = a%M then use binExpItr to calculate.


   example:
    a= 54321^1234556789;
    b= 123;
    M=1e9+10;

    a = binExpItr(54321,123456789)%M;   // a < 10^9 b<10^9 So, no problem.

    Or, a = (a%M);

*/

/*


    example 2:
     a<10^9 b<10^9 and
     jodi  M < 10^18 hoy taile problem ase:

    OR,
     a<10^18 b<10^18 and
     jodi  M < 10^18 hoy taile problem ase:



     ans = (ans*1ll*a)%M prob hobe overflow.
     TO solve this problem use binExpItr_M function

*/

long long binMultiply(long long a, long long b)
{
    // it simply calculates a*b
    // O (log b)
    //   binMultiply  simply helps binExpItr_M to calculate multiplication using addition
    // it can calculate to big number 10^18 ranges.
    /*
        10^18 *10^18 overflow.
        but using addition it can calculate 10^18 *10^18  in log(N)
    */

    long long ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans + a) % M;
        }
        b >>= 1;
        a = (a + a) % M;
    }
    return ans;
}

long long binExpItr_M(long long a, long long b)
{
    // O ( log^2 N) => logN * logN
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {

            ans = binMultiply(ans, a) % M;
        }
        b >>= 1;

        a = binMultiply(a, a) % M;
    }
    return ans;
}

int main(void)
{

    cout << "binMultiply: " << binMultiply(5, 13) << endl;
    cout << "binExpItr_M: " << binExpItr_M(5, 13) << endl;
}