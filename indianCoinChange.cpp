// {1,2,5,10,20,50,100,200,500,2000}
// greedy approach work well for indian denomination

#include <bits/stdc++.h>
using namespace std;

int hightestCoinIndex(vector<int> arr, int amt)
{
    int n = arr.size();
    int i = 0;
    int j = n - 1;
    int ans = -1;

    while (i <= j)
    {
        int mid = (i + j) / 2;

        if (arr[mid] == amt)
        {
            return mid;
        }
        else if (arr[mid] > amt)
        {
            ans = mid;
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return ans - 1;
}

int indianCoinChange(vector<int> arr, int amt)
{
    int n = arr.size();

    int count = 0;
    while (amt > 0)
    {
        int idx = hightestCoinIndex(arr, amt);
        count += 1;
        cout << arr[idx] << endl;
        amt -= arr[idx];
    }
    return count;
}

int main()
{
    vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int amt;
    cin >> amt;
    cout << indianCoinChange(arr, amt) << endl;
    return 0;
}