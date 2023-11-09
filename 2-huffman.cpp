#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    char data;
    int freq;
    node *left;
    node *right;

    node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = nullptr;
        right = nullptr;
    }
};

struct comparenode
{

    bool operator()(node *left, node *right)
    {
        return left->freq > right->freq;
    }
};

void print(node *root, string str)
{
    if (!root)
    {
        return;
    }

    if (root->data != '$')
    {
        cout << root->data << ": " << str << endl;
    }

    print(root->left, str + '0');
    print(root->right, str + '1');
}

void buildtree(char data[], int freq[], int size)
{
    priority_queue<node *, vector<node *>, comparenode> minheap;

    for (int i = 0; i < size; i++)
    {
        minheap.push(new node(data[i], freq[i]));
    }

    while (minheap.size() != 1)
    {
        node *left = minheap.top();
        minheap.pop();

        node *right = minheap.top();
        minheap.pop();

        node *top = new node('$', left->freq + right->freq);

        top->left = left;
        top->right = right;
        minheap.push(top);
    }

    print(minheap.top()," ");
}
int main()
{
    return 0;
}