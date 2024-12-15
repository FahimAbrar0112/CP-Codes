#include <bits/stdc++.h>
using namespace std;

/*

  a*b = gcd*lcm
  gcd= min power of the primes
  lcm= max power of the primes

*/

// Eucled Long Division:
//  O(log N)
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

int main(void)
{

  cout << gcd_(12, 18) << endl;
  cout << (12 * 18) / gcd(12, 18) << endl;

  cout << gcd_(2, 3) << endl;
  cout << lcm(2, 3) << endl;
  cout << 12 % 18 << endl;

  //  __gcd(a,b) , lcm(a,b)

  cout << "BUILTIN:\n"
       << endl;
  cout << __gcd(12, 18) << endl;
  cout << (12 * 18) / __gcd(12, 18) << endl;

  cout << "GCD 0f 12,18 ,20: " << endl;
  cout << "GCD: " << gcd(12, __gcd(18, 20)) << endl;
  cout << "LCM: " << lcm(12, lcm(18, 20)) << endl;
  cout << "LCM: " << lcm_(12, lcm_(18, 20)) << endl;

  cout << (2 * 2 * 3 * 3 * 5) << endl;

  return 0;
}