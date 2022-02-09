#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    int power = 1;
    while (n)
    {
        int digit = (n & 1);
        ans += digit * power;
        power *= 10;
        n = (n >> 1);
    }

    cout << ans << endl;
    return 0;
}