
#include <iostream>
#include <vector>

using namespace std;

int knapsack(const vector<int> &weight, const vector<int> &profit, int capacity)
{
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (weight[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], profit[i - 1] + dp[i - 1][w - weight[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main()
{
    int n;
    cout << "Enter the value pf n: ";
    cin >> n;
    vector<int> weight(n, 0);
    vector<int> profit(n, 0);

    cout << "Enter weight" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cout << "Enter profit" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    cout << endl;
    // vector<int> weight = {2, 3, 4, 5};
    // vector<int> profit = {3, 4, 5, 6};
    int capacity;
    cin >> capacity;
    int result = knapsack(weight, profit, capacity);
    cout << "Maximum Profit is: " << result;

    return 0;
}