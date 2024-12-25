// https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

vector<string> subsets(string s)
{
    int n = s.size();
    int subset_size = (1 << n);
    vector<string> subsets;
    for (int mask = 0; mask < subset_size; mask++)
    {
        string subset;
        for (int bit = 0; bit < n; bit++)
        {
            if (mask & (1 << bit))
            {
                subset.push_back(s[bit]);
            }
        }
        if (subset.size()) // to ignore empty set
            subsets.push_back(subset);
    }

    return subsets;
}

int main(void)
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<string> str(n);

        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
        }

        unordered_map<string, int> hsh;

        for (int i = 0; i < n; i++)
        {
            set<char> distinct_vowel;
            for (auto ch : str[i])
            {
                if (isVowel(ch))
                    distinct_vowel.insert(ch);
            }

            string vowel_string;
            for (auto ch : distinct_vowel)
            {
                vowel_string.push_back(ch);
            }

            vector<string> all_subsets = subsets(vowel_string);

            for (string vowel_subset : all_subsets)
            {
                hsh[vowel_subset]++;
            }
        }

        long long ans = 0;
        for (auto &pr : hsh)
        {
            if (pr.second < 3)
                continue;
            long long ct = pr.second;
            long long ways = ct * (ct - 1) * (ct - 2) / 6; // nC3

            if (pr.first.size() % 2 == 0)
                ans -= ways;
            else
                ans += ways;
        }
        cout << ans << endl;
    }
}