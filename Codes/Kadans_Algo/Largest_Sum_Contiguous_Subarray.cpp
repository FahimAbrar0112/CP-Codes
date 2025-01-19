// C++ program to print largest contiguous array sum
#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &v)
{
	int currSum = 0, maxSum = INT_MIN;

	for (int val : v)
	{
		currSum += val;
		maxSum = max(currSum, maxSum);
		if (currSum < 0)
			currSum = 0;
	}
	return maxSum;
}

// Driver Code
int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	// Function Call
	int max_sum = maxSubArraySum(v);
	cout << "Maximum contiguous sum is " << max_sum << endl;
	return 0;
}

/*
	8
	-2 -3 4 -1 -2 1 5 -3


*/
