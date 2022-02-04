#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.second.second < b.second.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> arr;

    for (int i = 0; i < n; i++)
    {
        int activity, start, end;
        cout << "Enter the activity number" << endl;
        cin >> activity;
        cout << "Enter the start of activity " << activity << endl;
        cin >> start;
        cout << "Enter the end of activity " << activity << endl;
        cin >> end;
        arr.push_back({activity, {start, end}});
    }

    sort(arr.begin(), arr.end(), compare);

    int j = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].second.first >= arr[j].second.second)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}