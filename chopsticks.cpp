#include <bits/stdc++.h>
using namespace std;

int pairChopsticks(vector<int> arr, int diff)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int count = 0;
    int i = 0;
    int j = i + 1;
    while (j < n)
    {
        if (i != j && arr[j] - arr[i] == diff)
        {
            count++;
            j++;
        }
        else if (i != j && arr[j] - arr[i] > diff)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return count;
}

int main()
{
    int n, diff;
    cin >> n >> diff;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << pairChopsticks(arr, diff) << endl;
    return 0;
}