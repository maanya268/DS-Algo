#include <bits/stdc++.h>
using namespace std;

int minCoinsChangeDpBU(int n, int T, int *coins)
{
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        int ans = INT_MAX;
        for (int j = 0; j < T; j++)
        {
            if (dp[i - coins[j]] >= 0)
            {
                ans = min(ans, dp[i - coins[j]]);
            }
        }
        dp[i] = 1 + ans;
    }
    return dp[n];
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

    cout << minCoinsChangeDpBU(n, T, coins) << endl;
    return 0;
}