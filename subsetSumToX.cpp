#include <bits/stdc++.h>
using namespace std;

int totalSubsetsSumToX(vector<int> arr, int i, int target)
{
    if (i == arr.size())
    {
        if (target == 0)
        {
            return 1;
        }
        return 0;
    }
    int op1 = totalSubsetsSumToX(arr, i + 1, target - arr[i]);
    int op2 = totalSubsetsSumToX(arr, i + 1, target);

    return op1 + op2;
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
    int target;
    cin >> target;
    cout << totalSubsetsSumToX(arr, 0, target);
}