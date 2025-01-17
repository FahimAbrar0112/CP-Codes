#include <bits/stdc++.h>
using namespace std;

// A structure to store the weight, value, and value-to-weight ratio
struct Item
{
    int weight, value;
    double ratio;
};

// Comparator to sort items based on value-to-weight ratio in descending order
bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int W, vector<Item> &items)
{
    // Sort items based on their value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0; // To store the maximum value we can achieve
    int currentWeight = 0; // Current weight of the knapsack

    for (auto &item : items)
    {
        // If the item can be taken completely
        if (currentWeight + item.weight <= W)
        {
            currentWeight += item.weight;
            maxValue += item.value;
        }
        else
        {
            // Take the fraction of the item
            int remainingCapacity = W - currentWeight;
            maxValue += item.ratio * remainingCapacity;
            break; // No more capacity left
        }
    }
    return maxValue;
}

int main()
{
    int n, W; // Number of items and knapsack capacity
    cin >> n >> W;

    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = (double)items[i].value / items[i].weight; // Calculate ratio
    }

    double maxValue = fractionalKnapsack(W, items);
    cout << fixed << setprecision(2) << maxValue << endl;

    return 0;
}

/*
    3 50
10 60
20 100
30 120


*/