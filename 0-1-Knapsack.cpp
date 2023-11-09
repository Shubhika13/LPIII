#include <iostream>
#include <vector>
using namespace std;
int knapsack(const vector<int> &weight, const vector<int> &profit, int capacity)
{
    int n = weight.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));

    for(int i=1;i<=n;i++){
        for(int w = 0;w<=capacity; w++){
            if(weight[i-1]<=w){
                dp[i][w] = max(dp[i-1][w], profit[i-1]+dp[i-1][w-weight[i-1]]);
            }

            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][capacity];
}


int main()
{

    // vector<int> weight = {2, 3, 4, 5};
    // vector<int> profit = {3, 4, 5, 6};

    // int cap = 8;

    int size;
    cout << "Enter the value of size : ";
    cin >> size;
    vector<int> weight(size, 0);
    vector<int> profit(size, 0);
    int capacity;

    cout << "Enter values of weight : ";
    for (auto i = 0; i < size; i++)
    {
        cin >> weight[i];
    }

    cout << endl;

    cout << "Enter values of profit : ";
    for (auto i = 0; i < size; i++)
    {
        cin >> profit[i];
    }

    cout << endl;

    cout << "Enter the capacity : ";
    cin >> capacity;

    int res = knapsack(weight, profit, capacity);
    cout << res << endl;
    return 0;
}

// dp[i][w] = max(dp[i-1][w], profit[i-1][w]+dp[i-1][w-weight[i-1]])