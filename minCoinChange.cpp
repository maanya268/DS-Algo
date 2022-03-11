#include <bits/stdc++.h>
using namespace std;

int minCoinsChange(int n, int T, int *coins, int *dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ans = INT_MAX;
    for (int i = 0; i < T; i++)
    {
        if (n - coins[i] >= 0)
        {
            ans = min(ans, minCoinsChange(n - coins[i], T, coins, dp));
        }
    }
    return dp[n] = 1 + ans;
}

int main()
{
    int n, T;
    cin >> n >> T;
    int *coins = new int[T];
    for (int i = 0; i < T; i++)
    {
        cin >> coins[i];
    }

    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
    }

    cout << minCoinsChange(n, T, coins, dp) << endl;
    return 0;
}