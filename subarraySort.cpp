#include <bits/stdc++.h>
using namespace std;

bool outOfOrder(vector<int> arr, int i)
{
    int x = arr[i];
    if (i == 0)
    {
        return x > arr[1];
    }

    if (i == arr.size() - 1)
    {
        return x < arr[i - 1];
    }

    return (x > arr[i + 1]) || (x < arr[i - 1]);
}

pair<int, int> subarraySort(vector<int> arr)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];
        if (outOfOrder(arr, i))
        {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }

    if (smallest == INT_MAX)
    {
        return {-1, -1};
    }

    int left = 0;
    while (arr[left] <= smallest)
    {
        left++;
    }
    int right = arr.size() - 1;
    while (arr[right] >= largest)
    {
        right--;
    }

    return {left, right};
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

    pair<int, int> p = subarraySort(arr);
    cout << p.first << " " << p.second << endl;
}