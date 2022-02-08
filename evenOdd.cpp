#include <bits/stdc++.h>
using namespace std;

int isOdd(int n)
{
    return n & 1;
}

int main()
{
    int n;
    cin >> n;

    if (isOdd(n))
    {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
    return 0;
}