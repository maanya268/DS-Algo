#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, v;
    cin >> n >> i >> v;

    // first we clear the bit at ith position as we dont know which bit is present there
    int mask = ~(1 << i);

    int afterClear = n & mask;

    // now updating the bit at ith position to v
    int newMask = v << i;

    int ans = n | newMask;

    cout << ans << endl;

    return 0;
}