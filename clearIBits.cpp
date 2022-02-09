#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n >> i;
    int mask = (~0) << i;

    cout << (n & mask) << endl;
    return 0;
}