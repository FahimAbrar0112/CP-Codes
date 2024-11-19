#include <bits/stdc++.h>
using namespace std;

int arrSum(int arr[], int i)
{
    if (i < 0)
        return 0;

    return arrSum(arr, i - 1) + arr[i];
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 4;
    cout<<arrSum(arr,n-1)<<endl;

}