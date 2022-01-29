#include <bits/stdc++.h>
using namespace std;

vector<int> housing(vector<int> arr, int k)
{
    vector<int> output;
    int i = 0;
    int j = 0;
    int n = arr.size() - 1;
    int sum = arr[i];

    while (j <= n)
    {
        if (sum == k)
        {
            output.push_back(i);
            output.push_back(j);
            if (arr[i] == 0)
            {
                if (j < n && arr[j + 1] == 0)
                {
                    j++;
                    sum += arr[j];
                }
                else
                {
                    sum -= arr[i];
                    i++;
                }
            }
            else
            {
                j++;
                sum += arr[j];
            }
        }
        else if (sum > k)
        {
            sum -= arr[i];
            i++;
        }
        else
        {
            j++;
            sum += arr[j];
        }
    }
    return output;
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

    vector<int> ans = housing(arr, k);
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0 && i % 2 == 0)
        {
            cout << endl;
        }
        cout << ans[i] << " ";
    }
    return 0;
}