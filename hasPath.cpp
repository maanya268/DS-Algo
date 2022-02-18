#include <bits/stdc++.h>
using namespace std;

bool hasPath(int **edges, int n, int sv, int ev, bool *visited)
{
    if (sv == ev && sv < n && ev < n)
    {
        return true;
    }

    bool ans = false;
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (sv == i)
        {
            continue;
        }

        if (edges[sv][i] == 1)
        {
            if (!visited[i])
            {
                ans = hasPath(edges, n, i, ev, visited);
                if (ans)
                {
                    return ans;
                }
            }
        }
    }
    return ans;
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

    int sv, ev;
    cin >> sv >> ev;

    if (hasPath(edges, n, sv, ev, visited))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}