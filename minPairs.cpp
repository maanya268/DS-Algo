#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int key)
{
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> a1, a2;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        a1.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a2.push_back(x);
    }

    sort(a2.begin(), a2.end());

    int a, b;
    int diff = 0;
    int minDiff = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        int lb = lowerBound(a2, a1[i]);
        if (lb == -1)
        {
            diff = abs(a1[i] - a2[0]);
            if (diff < minDiff)
            {
                a = a1[i];
                b = a2[0];
                minDiff = diff;
            }
        }
        else
        {
            int justLower = a2[lb];
            if (lb < n - 1)
            {
                int justUpper = a2[lb + 1];
                diff = abs(justUpper - a1[i]);
                if (diff < minDiff)
                {
                    a = a1[i];
                    b = justUpper;
                    minDiff = diff;
                }
            }
            diff = abs(justLower - a1[i]);
            if (diff < minDiff)
            {
                a = a1[i];
                b = justLower;
                minDiff = diff;
            }
        }
    }
    cout << a << " " << b << " " << minDiff << endl;

    return 0;
}