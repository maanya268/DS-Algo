#include <bits/stdc++.h>
using namespace std;

int minRounds(vector<int> arr)
{
    int n = arr.size();
    int overallSum = 0;
    float balancedLoad = 0;

    for (int i = 0; i < n; i++)
    {
        overallSum += arr[i];
    }

    if (overallSum % n != 0)
    {
        return -1;
    }
    balancedLoad = overallSum / n;

    int currentSum = 0;

    int maxRounds = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        int transferRounds = abs(currentSum - (i + 1) * balancedLoad);
        maxRounds = max(maxRounds, transferRounds);
    }

    return maxRounds;
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
    cout << minRounds(arr) << endl;
    return 0;
}