#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    void buildGraph(vector<vector<string>> &equations, vector<double> &values)
    {
        for (int i = 0; i < equations.size(); i++)
        {
            string x = equations[i][0];
            string y = equations[i][1];

            double val = values[i];

            graph[x].push_back({y, val});
            graph[y].push_back({x, 1.0 / val});
        }
    }

    double bfs(string start, string end)
    {
        if (graph.count(start) == 0 || graph.count(end) == 0)
            return -1.0;

        queue<pair<string, double>> q;
        unordered_set<string> visited;

        q.push({start, 1});
        visited.insert(start);

        while (!q.empty())
        {
            auto pair = q.front();
            q.pop();

            auto node = pair.first;
            auto val = pair.second;

            if (node == end)
                return val;

            for (auto &p : graph[node])
            {
                auto &neighbor = p.first;
                auto &weight = p.second;

                if (visited.count(neighbor) == 0)
                {

                    visited.insert(neighbor);
                    q.push({neighbor, val * weight});
                    cout << node << " " << neighbor << " " << val * weight << endl;
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        buildGraph(equations, values);

        vector<double> results;

        for (auto &q : queries)
        {
            results.push_back(bfs(q[0], q[1]));
        }
        return results;
    }
};

int main()
{
    Solution sol;

    vector<vector<string>> equations = {
        {"a", "b"}, {"a", "c"}, {"a", "d"}, {"b", "c"}, {"c", "e"}};
    vector<double> values = {5, 2, 3, .4, 10};
    string start = "a", end = "e";
    vector<vector<string>> q = {
        {start, end}};

    vector<double> result = sol.calcEquation(equations, values, q);

    for (auto val : result)
    {
        cout << val << endl;
    }

    return 0;
}
