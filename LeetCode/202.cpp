#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> digitsFunc(int n)
    {
        vector<int> digits;

        while (n)
        {
            digits.push_back(n % 10);
            n /= 10;
        }
        return digits;
    }

    bool isHappy(int n)
    {
        unordered_set<int> seen; // To detect cycles

        while (n != 1)
        {
            if (seen.count(n))
                return false; // If we've seen this number before, it's a cycle

            seen.insert(n);    
            vector<int> digits = digitsFunc(n);

            n = 0;
            for (auto dig : digits)
            {
                n += dig * dig;
            }
        }

        return 1;
    }
};

class Solution
{
public:
    int sumOfSquares(int n)
    {
        int sum = 0;
        while (n)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n, fast = n;

        do
        {
            slow = sumOfSquares(slow);               // Move by 1 step
            fast = sumOfSquares(sumOfSquares(fast)); // Move by 2 steps
        } while (slow != fast);

        return slow == 1; // If it ends in 1, it's a happy number
    }
};
