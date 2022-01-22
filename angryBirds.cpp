#include <bits/stdc++.h>
using namespace std;

bool canPlaceBirds(int n, int b, int sep, vector<int> nests)
{
    int birds = 1;
    int location = nests[0];

    for (int i = 1; i < n; i++)
    {
        int currentLocation = nests[i];
        if (currentLocation - location >= sep)
        {
            birds++;
            location = currentLocation;
            if (birds == b)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int b;
    cin >> b;
    vector<int> nests;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nests.push_back(x);
    }

    int s = 0;
    int e = nests[n - 1] - nests[0];
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        bool canPlace = canPlaceBirds(n, b, mid, nests);
        if (canPlace)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}