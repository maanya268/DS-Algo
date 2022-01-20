#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int k)
{
    int i = 0;
    int j = arr.size() - 1;
    int lb = -1;

    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == k)
        {
            lb = mid;
            j = mid - 1;
        }
        else if (arr[mid] > k)
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return lb;
}

int upperBound(vector<int> arr, int k)
{
    int i = 0;
    int j = arr.size() - 1;
    int ub = -1;

    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == k)
        {
            ub = mid;
            i = mid + 1;
        }
        else if (arr[mid] > k)
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return ub;
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
    int k;
    cin >> k;

    int lb = lowerBound(arr, k);
    int ub = upperBound(arr, k);

    cout << ub << " " << lb << endl;
    cout << ub - lb + 1 << endl;
    return 0;
}