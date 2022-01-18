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

    sort(arr, arr + n);

    int i = 0;
    int j = n - 1;

    int sum;
    cin >> sum;
    while (i < j)
    {
        int add = arr[i] + arr[j];
        if (add == sum)
        {
            cout << arr[i] << " " << arr[j] << endl;
            break;
        }
        else if (add < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    if (i >= j)
    {
        cout << "No pair found" << endl;
    }
    return 0;
}