// it is used to find the maxm subarray sum

#include <bits/stdc++.h>
using namespace std;

int kadanesAlgo(vector<int> arr)
{
    int n = arr.size();
    int maxSum = INT_MIN;
    int sum = 0;
    int i = 0;

    while (i < n)
    {
        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
        i++;
    }
    return maxSum;
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
    cout << kadanesAlgo(arr) << endl;
    return 0;
}
