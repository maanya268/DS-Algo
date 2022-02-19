#include <bits/stdc++.h>
using namespace std;

void allConnectedCompoonents(int **edges, int n, int sv, bool *visited, vector<int> &ans)
{
    ans.push_back(sv);
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (!visited[i])
            {
                allConnectedCompoonents(edges, n, i, visited, ans);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> ans;
        if (!visited[i])
        {
            allConnectedCompoonents(edges, n, i, visited, ans);
            sort(ans.begin(), ans.end());

            for (auto x : ans)
            {
                cout << x << " ";
            }
        }
        ans.clear();
        cout << endl;
    }
    return 0;
}