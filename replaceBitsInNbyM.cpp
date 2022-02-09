#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j;

    cin >> n >> m >> i >> j;

    // first clear bits from i to j
    int a = (~0) << (j + 1);
    int b = 1 << (i - 1);

    int mask = a | b;

    n = n & mask;

    // now udpating the bits
    m = m << i;
    cout << (n | m) << endl;
    return 0;
}