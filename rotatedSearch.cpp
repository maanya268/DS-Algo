#include <bits/stdc++.h>
using namespace std;

int rotatedSearch(int *arr, int n, int key)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] >= arr[s]) // mid lies on line 1
        {
            //further i have to check element lies on left side of mid or right side  of mid
            if ((arr[s] <= key) && (key <= arr[mid]))
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else if (arr[mid] < arr[e])
        {
            //further i have to check whether element lies on left side or right side
            if ((arr[mid] <= key) && (key <= arr[e]))
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    cout << rotatedSearch(arr, n, key) << endl;
    return 0;
}