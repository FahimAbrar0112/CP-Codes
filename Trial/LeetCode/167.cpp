#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        int start = 0, end = numbers.size() - 1;

        while (start < end)
        {
            if(numbers[start]+numbers[end]>target)
            {
                end--;
                continue;
            }
            if(numbers[start]+numbers[end]<target)
            {
                start++;
                continue;
            }

            if (numbers[start] + numbers[end] == target)
            {
                break;
            }
        }

        return vector<int>  {start + 1, end + 1};
    }
};

int main(void)
{
}