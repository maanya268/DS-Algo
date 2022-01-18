#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum;
    cin >> sum;

    sort(arr, arr + n);
    vector<int> output;
    for (int i = 0; i < n - 2; i++)
    {
        int start = i + 1;
        int end = n - 1;
        int newSum = sum - arr[i];
        while (start < end)
        {
            int add = arr[start] + arr[end];
            if (add == newSum)
            {
                output.push_back(arr[i]);
                output.push_back(arr[start]);
                output.push_back(arr[end]);
                start++;
                end--;
            }
            else if (add < newSum)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    for (int i = 0; i < output.size(); i++)
    {
        if (i != 0 && i % 3 == 0)
        {
            cout << endl;
        }
        cout << output[i] << " ";
    }

    return 0;
}