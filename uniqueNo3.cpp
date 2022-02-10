#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;

    vector<int> sum(64, 0);
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        int j = 0;
        while (no)
        {
            int lastBit = (no & 1);
            sum[j] += lastBit;
            j++;
            no = no >> 1;
        }
    }

    int ans = 0;
    int power = 1;
    for (int i = 0; i < 64; i++)
    {
        sum[i] = sum[i] % 3;
        ans += power * sum[i];
        power *= 2;
    }
    cout << ans << endl;
    return 0;
}