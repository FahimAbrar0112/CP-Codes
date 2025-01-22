#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>

using namespace std;

// Custom hash function for the nested pair structure
struct PairHash
{
    size_t operator()(const pair<long long, pair<double, pair<set<int>, string>>> &p) const
    {
        // Hash for the first part of the pair (long long)
        size_t h1 = hash<long long>()(p.first);

        // Hash for the nested pair (double, pair<set<int>, string>)
        size_t h2 = hash<double>()(p.second.first);

        // Hash for the innermost pair (set<int>, string)
        size_t h3 = 0;
        for (const auto &elem : p.second.second.first)
        {
            h3 ^= hash<int>()(elem); // Hash each element in the set
        }

        size_t h4 = hash<string>()(p.second.second.second); // Hash the string

        // Combine the individual hashes
        return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3);
    }
};

int main()
{
    // Declare the unordered_map with the complex key type and value type
    unordered_map<pair<long long, pair<double, pair<set<int>, string>>>, vector<pair<string, vector<int>>>, PairHash> mp;

    // Inserting some data into the unordered_map
    mp[{1LL, {3.14, {{1, 2, 3}, "hello"}}}] = {{"apple", {10, 20}}, {"banana", {30, 40}}};
    mp[{2LL, {2.71, {{4, 5}, "world"}}}] = {{"grape", {50, 60}}, {"cherry", {70, 80}}};

    // Output the stored values
    for (const auto &entry : mp)
    {
        cout << "Key: (" << entry.first.first << ", ("
             << entry.first.second.first << ", (";

        // Print the set<int> in the pair
        for (const auto &s : entry.first.second.second.first)
        {
            cout << s << " ";
        }

        cout << ", " << entry.first.second.second.second << "))) -> Values: ";

        for (const auto &val : entry.second)
        {
            cout << "(" << val.first << ", [";
            for (const auto &v : val.second)
            {
                cout << v << " ";
            }
            cout << "]) ";
        }
        cout << endl;
    }

    return 0;
}
