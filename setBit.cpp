#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n >> i;

    int mask = 1 << i;

    cout << (n | mask) << endl;
    return 0;
}