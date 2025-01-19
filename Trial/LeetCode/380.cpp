#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
public:
    multiset<int> s;

    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        auto it = s.find(val);
        if (it != s.end())
        {
            return false;
        }

        s.insert(val);
        return 1;
    }

    bool remove(int val)
    {
        auto it = s.find(val);
        if (it == s.end())
        {
            return 0;
        }

        s.erase(it);
        return 1;
    }

    int getRandom()
    {
        vector<int> vec(s.begin(), s.end());

        return vec[rand() % vec.size()];
    }
};
 


 