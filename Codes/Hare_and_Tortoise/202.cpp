// https : // leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
        using namespace std;

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

int main()
{
    Solution sol;
    int num = 19;
    if (sol.isHappy(num))
        cout << num << " is a happy number" << endl;
    else
        cout << num << " is not a happy number" << endl;

    return 0;
}
