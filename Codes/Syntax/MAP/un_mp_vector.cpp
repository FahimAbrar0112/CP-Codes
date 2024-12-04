#include <bits/stdc++.h>
using namespace std;

// Custom hash function for vector<int>
auto VectorHash = [](  const vector<int> &vec)
{
    size_t seed = 0;
    for (int val : vec)
    {
        // Combine each value's hash into a single hash value
        seed ^= hash<int>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

            // seed+= hash<int>()(val) ;
    }
    return seed;
};

int main()
{
    // Define an unordered_map with vector<int> as the key
    unordered_map<vector<int>, string, decltype(VectorHash)> mp(10, VectorHash);

    // Insert key-value pairs
    mp[{1, 2, 3}] = "Vector 1";
    mp[{4, 5}] = "Vector 2";
    mp[{6}] = "Vector 3";
    mp[{7, 8, 9, 10}] = "Vector 4";
    mp[{11, 12, 13}] = "Vector 5";
    mp[{14, 15, 16, 17, 18}] = "Vector 6";

    // Access the values

    for (auto &val : mp)
    {
        cout << "KEY: ";
        for (auto &v : val.first)
        {
            cout << v << " ";
        }
        cout << "VAL: " << val.second << endl;
    }

    cout << (long long int)0x9e3779b9;
     return 0;
}
