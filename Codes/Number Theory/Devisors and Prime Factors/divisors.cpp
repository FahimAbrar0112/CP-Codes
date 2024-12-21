#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = INT_MAX;

/*

    Optimized:

    if=>
        x = p1^n1  * p2^n2 * p3^n3
    then
     ct of divisors = (n1+1)*(n2+1)*(n3+1)
     sum of divisors = ((p1^(n1+1) ) -1 ) / (p1-1)
                      *((p2^(n2+1) ) -1 ) / (p2-1)
                      *((p3^(n3+1) ) -1 ) / (p3-1)
     watch love ep 57 if needed.

    code is not available here!


*/

void divisors(int n, vector<int> &v)
{
    // O(sq root N)
    int sum_of_divisors = 0, ct_of_divisiors = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " " << n / i << endl;
            ct_of_divisiors++;
            sum_of_divisors += i;
            v.push_back(i);

            if (i != n / i)
            {
                ct_of_divisiors++;
                sum_of_divisors += n / i;
                v.push_back(n / i);
            }
        }
    }
    cout << endl;

    cout << "sum_of_divisors: " << sum_of_divisors << "     ct_of_divisiors:  " << ct_of_divisiors << endl;
}

int main(void)
{
    int n;
    cin >> n;

    vector<int> all_divisors;
    divisors(n, all_divisors);

    cout<<"Divisors of n are: "<<endl;
    for (auto val : all_divisors)
    {
        cout << val << " ";
    }
    cout<<endl;
    return 0;
}