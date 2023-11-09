#include <iostream>
using namespace std;

// recursive
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}


void print(int n){
    for(auto i = 0;i<=n;i++){
        cout << fib(i) << " ";
    }

    cout << endl;
}
// non recursive
void nonrecur(int x)
{
    if (x <= 1)
        return;
    int n1 = 0;
    int n2 = 1;
    cout << n1 << " " << n2 << " ";
    for (int i = 2; i <= x; i++)
    {
        int n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        cout << n3 << " ";
    }

    // return n2;
    // 0 1 1 2 3 5 8 13 21 34 55 79
}
int main()
{

    // int n1, n2, n3;

    int n;
    cin >> n;

    // recursive
    int ans = fib(n);
    cout << ans << endl;
    print(n);
    // non recursive
    // cout << nonrecur(n) << endl;
    nonrecur(n);
    return 0;
}

// 0 1 1 2 3 5 8 13 21 34 55 79