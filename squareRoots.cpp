#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;

    int s = 0;
    int e = n;
    float ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        int q = mid * mid;

        if (q == n)
        {
            ans = mid;
            break;
        }
        else if (q < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    bool flag = false;
    int i = 1;
    float inc = 0.1;
    while (i <= p)
    {
        while (ans * ans <= n)
        {
            ans += inc;
        }
        ans = ans - inc;
        inc = inc / 10.0;
        i++;
    }

    cout << ans << endl;
    return 0;
}