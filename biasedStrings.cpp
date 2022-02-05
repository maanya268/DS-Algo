#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<string, int>> arr;

    for (int i = 0; i < n; i++)
    {
        string name;
        int prefRank;
        cin >> name >> prefRank;

        arr.push_back({name, prefRank});
    }

    sort(arr.begin(), arr.end(), compare);

    int badness = 0;
    for (int i = 0; i < n; i++)
    {
        badness += abs(arr[i].second - (i + 1));
    }

    cout << badness << endl;

    return 0;
}