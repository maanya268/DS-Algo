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

    void dfsHelperConnectedComponents(int sv, unordered_map<int, int> &visited)
    {
        cout << sv << " ";
        visited[sv] = true;

        for (auto x : l[sv])
        {
            if (!visited[x])
            {
                dfsHelperConnectedComponents(x, visited);
            }
        }
    }

    void dfsConnectedComponents(int sv)
    {
        unordered_map<int, int> visited;

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfsHelperConnectedComponents(i, visited);
            }
        }
    }
};

int main()
{
    Graph g(8);
    g.addEdge(0, 4);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.dfsConnectedComponents(0);
    return 0;
}