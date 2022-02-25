#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfsConnectedComponentsHelper(int sv, unordered_map<int, int> &visited)
    {
        queue<int> q;

        q.push(sv);
        visited[sv] = 1;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            cout << front << " ";

            for (auto x : l[front])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = 1;
                }
            }
        }
    }

    void bfsConnectedComponents()
    {
        unordered_map<int, int> visited;
        for (int i = 0; i < v; i++)
        {
            visited[i] = 0;
        }
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                bfsConnectedComponentsHelper(i, visited);
            }
        }
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 6);
    g.addEdge(2, 6);
    g.addEdge(3, 6);
    g.addEdge(4, 6);
    g.bfsConnectedComponents();
    return 0;
}