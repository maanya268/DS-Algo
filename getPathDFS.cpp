#include <bits/stdc++.h>
using namespace std;

vector<int> getPathDFS(int **edges, int n, int sv, int ev, bool *visited)
{
    vector<int> ans;
    if (sv == ev)
    {
        ans.push_back(ev);
        return ans;
    }

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
                ans = getPathDFS(edges, n, i, ev, visited);
                if (ans.size() != 0)
                {
                    ans.push_back(sv);
                    return ans;
                }
            }
        }
    }
    return {};
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
        visited[i] = 0;
    }

    int sv, ev;
    cin >> sv >> ev;
    vector<int> output = getPathDFS(edges, n, sv, ev, visited);

    for (auto x : output)
    {
        cout << x << " ";
    }
    return 0;
}