#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> white;
    vector<int> black;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        white.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        black.push_back(x);
    }

    sort(white.begin(), white.end());
    sort(black.begin(), black.end());

    int i = 0;
    int j = 0;

    int ans = 0;
    while (i < n)
    {
        ans += abs(white[i++] - black[j++]);
    }

    cout << ans << endl;
    return 0;
}