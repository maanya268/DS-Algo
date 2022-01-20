#include <bits/stdc++.h>
using namespace std;

int minmSwaps(vector<int> arr)
{
    if (arr.size() == 1)
    {
        return 0;
    }

    int n = arr.size();
    pair<int, int> ap[n];
    for (int i = 0; i < n; i++)
    {
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    sort(ap, ap + n);

    vector<bool> visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int actual = i;
        int current = ap[i].second;
        if (visited[i] == true || actual == current)
        {
            continue;
        }

        int count = 0;
        while (!visited[actual])
        {
            count++;
            visited[actual] = true;
            actual = ap[actual].second;
        }
        ans += count - 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << minmSwaps(arr) << endl;
    return 0;
}