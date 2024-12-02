#include <bits/stdc++.h>
using namespace std;

// Lambda function for hashing a pair
auto pair_hash = [](const pair<int, int> &p)
{
     return p.first * 31 + p.second;
};

int main()
{

     // Declare unordered_map with lambda hash
     unordered_map<pair<int, int>, string, decltype(pair_hash)> m(10, pair_hash);

     // Insert elements
     m[{1, 2}] = "apple";
     m[{3, 4}] = "mango";

     // Access and print elements
     for (const auto &pair : m)
     {
          cout << "Key: (" << pair.first.first << ", " << pair.first.second
               << ") -> Value: " << pair.second << endl;
     }

     return 0;
}
