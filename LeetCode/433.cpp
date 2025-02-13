#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, vector<string>> graph;
    bool difference(string x, string y)
    {
        int ct = 0;
        for (int i = 0; i < 8; i++)
        {
            if (x[i] != y[i])
                ct++;
        }
        return ct == 1;
    }

    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        // If endGene is not in the bank, it's impossible to reach
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (!bankSet.count(endGene))
            return -1;

        int n = bank.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (difference(bank[i], bank[j]))
                {
                    graph[bank[i]].push_back(bank[j]);
                    graph[bank[j]].push_back(bank[i]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (difference(bank[i], startGene))
            {
                graph[bank[i]].push_back(startGene);
                graph[startGene].push_back(bank[i]);
            }
        }

        queue<string> q;
        int minMutation = 0;
        unordered_set<string> visited;

        q.push(startGene);
        visited.insert(startGene);

        while (!q.empty())
        {
            if (visited.count(endGene))
                return minMutation;
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                string currentGene = q.front();
                q.pop();

                for (string mutated : graph[currentGene])
                {
                    if (visited.count(mutated) == 0)
                    {
                        q.push(mutated);
                        visited.insert(mutated);
                    }
                }
            }
            minMutation++;
        }

        return -1;
    }
};
