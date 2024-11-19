#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b)
{
     return (a * b) / __gcd(a, b);
}
int main(void)
{
     int a, b, c;
     cin >> a >> b >> c;

     int nth_val;
     for (int i = min(a, b); c > 0; i++)
     {
          if (i % a == 0 || i % b == 0)
          {
               // cout<<nth_val<<" ";
               nth_val = i;
               c--;
          }
     }

     // cout << "N" << nth_val << endl;

     int lcm_ = lcm(a, b);
     int step_size;
     if (nth_val % lcm_ == 0)
     {
          step_size = lcm_;
     }
     else if (nth_val % a == 0)
     {
          step_size = a;
     }
     else if (nth_val % b == 0)
     {
          step_size = b;
     }

     while (nth_val >= 0)
     {
          cout << nth_val << " ";
          nth_val -= step_size;
     }
}