#include <bits/stdc++.h>
using namespace std;

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

    int highestMountain = 0;
    for (int i = 1; i < n - 1;)
    {
        if ((arr[i] > arr[i - 1]) && (arr[i] > arr[i + 1]))
        {
            int count = 1;
            int j = i;
            while ((j > 0) && (arr[j] > arr[j - 1]))
            {
                count++;
                j--;
            }
            while (i < n - 1 && arr[i] > arr[i + 1])
            {
                i++;
                count++;
            }
            highestMountain = max(highestMountain, count);
        }
        else
        {
            i++;
        }
    }
    cout << highestMountain << endl;
    return 0;
}