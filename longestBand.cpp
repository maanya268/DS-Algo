#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        map[arr[i]]++;
    }

    int maxCount = 1;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i] - 1;
        if (map.find(x) == map.end())
        {
            int count = 1;
            int a = arr[i] + 1;
            while (map.find(a) != map.end())
            {
                count++;
                a++;
            }
            if (count > maxCount)
            {
                maxCount = count;
            }
        }
    }

    cout << maxCount << endl;

    return 0;
}