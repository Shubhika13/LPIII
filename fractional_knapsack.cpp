#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class item
{
public:
    int weight;
    int profit;

    // item(int weight, int profit)
    // {
    //     this->weight = weight;
    //     this->profit = profit;
    // }
};

bool compare(item a, item b)
{
    double d1 = double(a.profit) / double(a.weight);
    double d2 = double(b.profit) / double(b.weight);

    return d1 > d2;
}

double fracknapsa(int capacity, vector<item> items)
{
    sort(items.begin(), items.end(), compare);

    double totalvalue = 0.0;
    double currentweight = 0.0;

    for (auto i = 0; i < items.size(); i++)
    {
        if (currentweight + items[i].weight <= capacity)
        {
            totalvalue += items[i].profit;
            currentweight += items[i].weight;
        }

        else
        {
            double fraction = double((capacity - currentweight) / items[i].weight);
            totalvalue = totalvalue + items[i].profit * fraction;
            break;
        }
    }

    return totalvalue;
}
int main()
{

    // vector<int> weight = {2, 3, 4, 5};
    // vector<int> profit = {3, 4, 5, 6};

    // int cap = 8;

    int size;
    cout << "Enter the number of item : ";
    cin >> size;

    vector<item> items(size);
    cout << "Enter the weight and profit of the item : ";
    for (int i = 0; i < size; i++)
    {
        cin >> items[i].weight >> items[i].profit;
    }

    cout << endl;

    int capacity;

    cout << "Enter the capacity : ";
    cin >> capacity;

    double res = fracknapsa(capacity, items);
    cout << res << endl;
    return 0;
}