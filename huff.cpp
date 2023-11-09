#include <iostream>
#include <queue>
using namespace std;

struct Node
{
public:
    char data;
    unsigned freq;
    Node *left;
    Node *right;
    Node(char data, unsigned freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

struct compareNode
{
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};

void print(Node *root, string str)
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

void buildTree(char data[], unsigned freq[], int size)
{
    priority_queue<Node *, vector<Node *>, compareNode> minHeap;
    for (int i = 0; i < size; i++)
    {
        minHeap.push(new Node(data[i], freq[i]));
    }

    while (minHeap.size() != 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();

        Node *right = minHeap.top();
        minHeap.pop();

        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    print(minHeap.top(), "");
}

int main()
{
    return 0;
}