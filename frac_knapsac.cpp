#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct item
{
    int weight;
    int profit;
};

bool compare(item a, item b)
{
    double r1 = double(a.profit) / double(a.weight);
    double r2 = double(b.profit) / double(b.weight);
    return r1 > r2;
}

double knapsack(int capacity, vector<item> items)
{
    sort(items.begin(), items.end(), compare);
    double currentWeight = 0.0;
    double totalValue = 0.0;

    for (int i = 0; i < items.size(); i++)
    {
        if (currentWeight + items[i].weight < capacity)
        {
            totalValue = totalValue + items[i].profit;
            currentWeight = currentWeight + items[i].weight;
        }
        else
        {
            double fraction = (double)(capacity - currentWeight) / items[i].weight;
            cout << "Fraction " << fraction << endl;
            totalValue = totalValue + items[i].profit * fraction;
            break;
        }
    }
    return totalValue;
}

int main()
{
    int c;
    cout << "Enter capacity ";
    cin >> c;
    int n;
    cout << "Enter the items ";
    cin >> n;
    cout << "Enter the weight and profit of the items: " << endl;
    vector<item> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].profit;
    }

    double maximumProfit = knapsack(c, items);
    cout << "Maximum profit " << maximumProfit << endl;
    return 0;
}