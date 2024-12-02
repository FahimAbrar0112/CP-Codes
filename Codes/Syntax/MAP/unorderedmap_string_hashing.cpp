#include <bits/stdc++.h>
using namespace std;

// Custom hash function for pair<string, int>
 
    auto hash_map = [](pair<string,int>p)
    {
         
        size_t hash1 = hash<string>()(p.first); // Hash for the string
        size_t hash2 = hash<int>()(p.second);   // Hash for the int
        return hash1 ^ (hash2 << 1);            // Combine using XOR and bit shifting
    };
 

int main()
{
    // Define an unordered_map with custom hash
    unordered_map<pair<string, int>, string, decltype(hash_map)> mp(10,hash_map);

    // Insert key-value pairs
    mp[{"John", 1}] = "Developer";
    mp[{"Alice", 2}] = "Designer";
    mp[{"Bob", 3}] = "Manager";
    mp[{"fuad",123}]="HR";


    // Access the values 

    for(auto & val : mp)
    {
        cout<<val.first.first<<" "<<val.first.second<<" "<<val.second<<endl;
    }

    return 0;
}
