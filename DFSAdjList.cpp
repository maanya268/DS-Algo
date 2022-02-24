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

    void dfsHelper(int sv, unordered_map<int, int> &visited)
    {
        cout << sv << " ";
        visited[sv] = 1;
        for (auto x : l[sv])
        {
            if (!visited[x])
            {
                dfsHelper(x, visited);
            }
        }
    }
    void dfs(int sv)
    {
        unordered_map<int, int> visited;
        dfsHelper(0, visited);
    }
};

int main()
{
    Graph g(10);
    g.addEdge(0, 8);
    g.addEdge(0, 6);
    g.addEdge(1, 8);
    g.addEdge(1, 6);
    g.addEdge(1, 7);
    g.addEdge(7, 4);
    g.addEdge(7, 3);
    g.addEdge(7, 9);
    g.addEdge(8, 5);
    g.addEdge(5, 2);
    g.dfs(0);
    return 0;
}