#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> arr)
{
    int candidate = -1;
    int votes = 0;

    for (auto x : arr)
    {
        if (votes == 0)
        {
            candidate = x;
        }

        if (candidate == x)
        {
            votes += 1;
        }
        else
        {
            votes--;
        }
    }
    if (votes == 0)
    {
        return -1;
    }
    return candidate;
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

    cout << majorityElement(arr) << endl;
    return 0;
}