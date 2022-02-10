#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> a >> n;

    int ans = 1;
    while (n > 0)
    {
        int lastBit = (n & 1);
        if (lastBit)
        {
            ans = ans * a;
        }
        a = a * a;
        n = n >> 1;
    }

    cout << ans << endl;
    return 0;
}