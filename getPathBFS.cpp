#include <bits/stdc++.h>
using namespace std;

void getPathBFS(int **edges, int n, int sv, int ev, bool *visited)
{
    if (sv == ev)
    {
        cout << sv << " ";
        return;
    }
    unordered_map<int, int> m;
    m[sv] = -1;

    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    bool found = false;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (i == front)
            {
                continue;
            }
            if (edges[sv][i] == 1 && !visited[i] && i == ev)
            {
                m[i] = front;
                visited[i] = true;
                q.push(i);
                found = true;
                break;
            }
            if (edges[sv][i] == 1 && !visited[i])
            {
                m[i] = front;
                visited[i] = true;
                q.push(i);
            }
        }
        if (found)
        {
            break;
        }
    }

    if (!found)
    {
        return;
    }

    int i = ev;
    cout << i << " ";
    while (m[i] != -1)
    {
        cout << m[i] << " ";
        i = m[i];
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
        visited[i] = 0;
    }

    int sv, ev;
    cin >> sv >> ev;
    getPathBFS(edges, n, sv, ev, visited);
    return 0;
}