#include <bits/stdc++.h>
using namespace std;

//  O( N )


int main(void)
{
    vector<int> v = {5,
                     2,
                     1,
                     8,
                     32,
                     67,
                     112, 5, 5, 5, 2};

    int min = *min_element(v.begin(), v.end());

    cout << min << endl;

    int max = *max_element(v.begin(), v.end());
    cout << max << endl;

    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;

    int ct = count(v.begin(), v.end(), 5);
    cout << ct << endl;

    string s = "abcdde";
    reverse(s.begin()+2, s.end());
    cout<<s<<endl;
}