#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j;
    cin >> n >> i >> j;

    int a = (~0) << (j + 1);
    int b = 1 << (i - 1);

    int mask = a | b;

    cout << (n & mask) << endl;
    return 0;
}